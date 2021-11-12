/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 15:30:46 by spoliart          #+#    #+#             */
/*   Updated: 2021/11/12 02:54:30 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_dir(const char *path)
{
	struct stat	buf;

	if (stat(path, &buf) == -1)
		return (-1);
	return (S_ISDIR(buf.st_mode));
}

static int	manage_error(char *path, char *cmd, char *error, int ret)
{
	free_one(path, NULL);
	ft_dprintf(STDERR_FILENO, "minishell: %s: %s\n", cmd, error);
	return (ret);
}

static int	check_error(char *path, char *cmd)
{
	int	ret;

	if (!path)
	{
		if (ft_getenv("PATH") == NULL || ft_strchr(cmd, '/'))
			return (manage_error(NULL, cmd, strerror(ENOENT),
					127));
		else
			return (manage_error(NULL, cmd, "command not found",
					127));
	}
	ret = is_dir(path);
	if (ret == -1)
		return (manage_error(path, cmd, strerror(errno),
				126));
	else if (ret == 1)
		return (manage_error(path, cmd, strerror(EISDIR),
				127));
	if (access(path, X_OK) != 0)
		return (manage_error(path, cmd, strerror(errno),
				126));
	return (EXIT_SUCCESS);
}

static void	child(t_cmd *cmd)
{
	int		ret;
	char	*path;

	path = get_path(cmd->argv[0]);
	ret = check_error(path, cmd->argv[0]);
	if (ret != EXIT_SUCCESS)
		exit(ret);
	if (execve(path, cmd->argv, g_shell->env) == -1)
		exit(manage_error(path, cmd->argv[0], strerror(errno), 126));
	free_one(path, NULL);
	exit(EXIT_SUCCESS);
}

static void	print_signal(int sig)
{
	const char	*tab[32] = {
		[SIGINT] = "\n",
		[SIGSEGV] = "Segmentation fault\n",
		[SIGBUS] = "Bus error\n",
		[SIGABRT] = "Aborted\n",
		[SIGQUIT] = "Quit\n",
		[SIGTERM] = "Terminated\n",
		[SIGTRAP] = "Trace/breakpoint trap\n",
		[SIGPIPE] = ""
	};

	if (tab[sig])
		ft_dprintf(STDERR_FILENO, "%s", tab[sig]);
	g_shell->exit_value = sig + 128;
}

static void	parent(pid_t pid)
{
	int	wstatus;

	waitpid(pid, &wstatus, WUNTRACED | WCONTINUED);
	if (WIFSIGNALED(wstatus))
		print_signal(WTERMSIG(wstatus));
	if (WIFEXITED(wstatus))
		g_shell->exit_value = WEXITSTATUS(wstatus);
}

void	exec_cmd(t_cmd *cmd)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		exit(EXIT_FAILURE);
	if (pid == 0)
		child(cmd);
	else
		parent(pid);
}

void	exec(t_node *ast)
{
	if (ast->type == CMD_NODE)
		exec_cmd(&ast->content.cmd);
//	else
//		exec_pipe();
}

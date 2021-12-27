/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 14:00:00 by spoliart          #+#    #+#             */
/*   Updated: 2021/12/06 19:45:29 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	Child process that executes the command
**
**	@param	cmd	=> The structure that stores the command
*/

static void	child(t_cmd *cmd)
{
	int		ret;
	char	*path;
	char	**env;

	signal_on_exec();
	path = get_path(cmd->argv[0]);
	ret = check_error(path, cmd->argv[0]);
	if (ret != EXIT_SUCCESS)
		exit(ret);
	env = lst_to_array(g_shell->env);
	if (execve(path, cmd->argv, env) == -1)
		exit(manage_error(path, cmd->argv[0], strerror(errno), 126));
	ft_free_tab(env, NULL);
	free_one(path, NULL);
	exit(EXIT_SUCCESS);
}

/*
**	Manage the execution of the command
**
**	@param	pid		=> The child pid
*/

static void	parent(pid_t pid)
{
	int	wstatus;

	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	waitpid(pid, &wstatus, WUNTRACED | WCONTINUED);
	if (WIFSIGNALED(wstatus))
		print_signal(WTERMSIG(wstatus));
	if (WIFEXITED(wstatus))
		g_shell->exit_code = WEXITSTATUS(wstatus);
}

/*
**	Execute one command with flags if there is
**
**	@param	cmd	=>	The structure containing the command with its arguments,
**					the input file descriptor and the output file descriptor.
*/

void	exec_cmd(t_cmd *cmd)
{
	pid_t	pid;

	ft_dup2(cmd->fd_in, STDIN_FILENO);
	ft_dup2(cmd->fd_out, STDOUT_FILENO);
	if (is_builtin(cmd->argv[0]))
		run_builtin(cmd);
	else
	{
		pid = fork();
		if (pid == -1)
			internal_error("Fork failed", EXIT_FAILURE);
		else if (pid == 0)
			child(cmd);
		else
			parent(pid);
	}
	restfd(STDIN_FILENO, cmd->fd_in);
	restfd(STDOUT_FILENO, cmd->fd_out);
}

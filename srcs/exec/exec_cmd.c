/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 14:00:00 by spoliart          #+#    #+#             */
/*   Updated: 2021/11/23 02:22:51 by spoliart         ###   ########.fr       */
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

	path = get_path(cmd->argv[0]);
	ret = check_error(path, cmd->argv[0]);
	if (ret != EXIT_SUCCESS)
		exit(ret);
	if (execve(path, cmd->argv, g_shell->env) == -1)
		exit(manage_error(path, cmd->argv[0], strerror(errno), 126));
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

	waitpid(pid, &wstatus, WUNTRACED | WCONTINUED);
	if (WIFSIGNALED(wstatus))
		print_signal(WTERMSIG(wstatus));
	if (WIFEXITED(wstatus))
		g_shell->exit_value = WEXITSTATUS(wstatus);
}

int	is_builtin(char *cmd)
{
	int			i;
	const char	*builtin_cmd[8] = {
	[0] = "echo",
	[1] = "cd",
	[2] = "pwd",
	[3] = "export",
	[4] = "unset",
	[5] = "env",
	[6] = "exit",
	[7] = NULL
	};

	i = 0;
	while (builtin_cmd[i] && !ft_strequ(builtin_cmd[i], cmd))
		i++;
	if (builtin_cmd[i])
		return (ft_strequ(builtin_cmd[i], cmd));
	return (0);
}

void	run_builtin(t_cmd *cmd)
{
	if (ft_strequ(cmd->argv[0], "env"))
	{
		if (cmd->argv[1])
			printf("%s \n", ft_getenv(cmd->argv[1]));
		else
			run_env();
	}
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

	if (is_builtin(cmd->argv[0]))
		run_builtin(cmd);
	else
	{
		pid = fork();
		if (pid == -1)
			exit(EXIT_FAILURE);
		if (pid == 0)
			child(cmd);
		else
			parent(pid);
	}
}

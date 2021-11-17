/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 14:00:00 by spoliart          #+#    #+#             */
/*   Updated: 2021/11/17 16:34:48 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

static void	parent(pid_t pid)
{
	int	wstatus;

	waitpid(pid, &wstatus, WUNTRACED | WCONTINUED);
	if (WIFSIGNALED(wstatus))
		print_signal(WTERMSIG(wstatus));
	if (WIFEXITED(wstatus))
		g_shell->exit_value = WEXITSTATUS(wstatus);
}

/*
**	Execute one command
**
**	@param	cmd	=>	The structure containing the command with its arguments,
**					the input file descriptor and the output file descriptor.
*/

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

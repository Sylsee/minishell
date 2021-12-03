/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 14:23:55 by spoliart          #+#    #+#             */
/*   Updated: 2021/12/03 01:09:56 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	Child process that executes the command on the left
**
**	@param	node	=> The structure that stores the command or pipe to be executed
**	@param	fd		=> The pipe file descriptor to link with parent process
*/

static void	child(t_node *node, int fd[2], int savefd[2])
{
	close(savefd[INPUT]);
	close(savefd[OUTPUT]);
	dup2(fd[OUTPUT], STDOUT_FILENO);
	close(fd[INPUT]);
	close(fd[OUTPUT]);
	exec(node);
	exit(EXIT_SUCCESS);
}

/*
**	Parent process that executes the command on the right
**
**	@param	node	=> The structure that stores the command or pipe to be executed
**	@param	fd		=> The pipe file descriptor to link with child process
**	@param	pid		=> The child pid to wait end of execution
*/

static void	parent(t_node *node, int fd[2], int savefd[2])
{
	ft_dup2(fd[INPUT], STDIN_FILENO);
	close(fd[INPUT]);
	close(fd[OUTPUT]);
	exec(node);
	wait(NULL);
	ft_dup2(savefd[INPUT], STDIN_FILENO);
	ft_dup2(savefd[OUTPUT], STDOUT_FILENO);
	close(savefd[INPUT]);
	close(savefd[OUTPUT]);
}

/*
**	Duplicate process to execute both commands at the same time and redirect
**	output to input.
**
**	@param	pipe	=> The structure that stores the two commands to be executed
*/

void	exec_pipe(t_content *p)
{
	int		fd[2];
	int		savefd[2];
	pid_t	pid;

	savefd[INPUT] = dup(STDIN_FILENO);
	savefd[OUTPUT] = dup(STDOUT_FILENO);
	if (pipe(fd) == -1)
		internal_error(strerror(errno), EXIT_FAILURE);
	pid = fork();
	if (pid == -1)
		internal_error(strerror(errno), EXIT_FAILURE);
	if (pid == 0)
		child(p->left, fd, savefd);
	else
		parent(p->right, fd, savefd);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 15:30:46 by spoliart          #+#    #+#             */
/*   Updated: 2021/11/05 18:18:38 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	child(t_cmd *cmd)
{
	char	*path;

	path = find_path(cmd->argv[0]);
}

static void	parent(pid_t pid)
{
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
		parent();
}

void	exec(t_node *ast)
{
	if (ast->type == CMD_NODE)
		exec_cmd(ast->content.cmd);
	else
	{
	}
}

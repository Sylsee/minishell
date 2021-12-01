/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 15:30:46 by spoliart          #+#    #+#             */
/*   Updated: 2021/11/23 22:08:10 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	The main function of execution
**	Check if it's a pipe or a simple command to execute it recursively
**
**	@param	ast	=> the ast where pipes and command are store
*/

void	exec(t_node *ast)
{
	if (ast->type == CMD_NODE)
		exec_cmd(&ast->content.cmd);
	else if (ast->type == PIPE_NODE)
		exec_pipe(&ast->content);
}

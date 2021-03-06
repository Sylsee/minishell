/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 15:30:46 by spoliart          #+#    #+#             */
/*   Updated: 2021/12/28 00:11:15 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
 **	The main function of execution
 **	Check if it's a pipe or a simple command to execute it recursively
 **
 **	@param	ast	=> the ast where pipes and commands are store
 */

void	exec(t_node *ast)
{
	if (expand_node(ast) == 0 || clear_redirections(ast) == 0)
	{
		if (g_shell->exit_code != CTRLC_ERR)
			g_shell->exit_code = FAILURE_ERR;
	}
	else if (ast->type == CMD_NODE)
	{
		if (ast->content.cmd.argv[0] == NULL
			|| ast->content.cmd.argv[0][0] == '\0')
			g_shell->exit_code = EXIT_SUCCESS;
		else
			exec_cmd(&ast->content.cmd);
	}
	else if (ast->type == PIPE_NODE)
		exec_pipe(&ast->content);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 07:56:48 by arguilla          #+#    #+#             */
/*   Updated: 2021/12/03 15:27:25 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	The main function of execution
**	Check if it's a pipe or a simple command to execute it recursively
**
**	@param	ast	=> the ast where pipes and command are store
**
**	@return	void.
*/

void	exec(t_node *ast)
{
//	if (!expand_node(ast) || !clear_redirections(ast))
//	{
//		g_shell->exit_code = FAILURE_ERR; 
//		return ;
//	}
	if (ast->type == PIPE_NODE)
	{}//exec_pipe(ast->content);
	else
	{}//exec_cmd(ast->content.cmd);
}

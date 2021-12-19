/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <arguilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 16:30:22 by arguilla          #+#    #+#             */
/*   Updated: 2021/11/26 10:46:22 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	Alloc a node structure representing a command.
**
**	@param	node	=>	the structure to alloc.
**	@param	tokens	=>	the list of tokens.
**
**	@return	a boolean value.
*/

bool	create_cmd(t_node **node, t_token **tokens)
{
	if ((*tokens)->type != Word_token && !is_redirection((*tokens)->type))
		return (false);
	*node = alloc(sizeof(t_node), &g_shell->a);
	(*node)->content.cmd.fd_in = STDIN_FILENO;
	(*node)->content.cmd.fd_out = STDOUT_FILENO;
	(*node)->content.cmd.has_quotes = false;
	(*node)->type = CMD_NODE;
	(*node)->content.left = NULL;
	(*node)->content.right = NULL;
	return (create_argv_cmd(&(*node)->content.cmd, tokens));
}

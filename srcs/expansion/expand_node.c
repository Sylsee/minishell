/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 08:03:36 by arguilla          #+#    #+#             */
/*   Updated: 2021/12/18 17:16:45 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	Redirect the node to the expanser or redirect its child.
**
**	@param	ast	=>	the node to redirect.
**
**	@return a boolean value.
*/

bool	expand_node(t_node *ast)
{
	if (ast->type == CMD_NODE)
		return (expanser(&ast->content.cmd));
	else
	{
		if (ast->content.left && !expand_node(ast->content.left))
			return (false);
		if (ast->content.right && !expand_node(ast->content.right))
			return (false);
	}
	return (true);
}

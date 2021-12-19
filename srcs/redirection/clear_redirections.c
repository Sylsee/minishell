/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_redirections.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 08:06:40 by arguilla          #+#    #+#             */
/*   Updated: 2021/12/19 20:07:45 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	Redirections controller, redirect to the good function.
**
**	@param	ast	=>	the current node.
**
**	@return	a boolean value.
*/

bool	clear_redirections(t_node *ast)
{
	if (ast->type == CMD_NODE)
		return (open_redirections(&ast->content.cmd));
	if (ast->content.left)
		if (!clear_redirections(ast->content.left))
			return (false);
	if (ast->content.right)
		if (!clear_redirections(ast->content.right))
			return (false);
	return (true);	
}

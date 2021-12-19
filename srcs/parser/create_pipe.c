/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_pipe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <arguilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 14:57:32 by arguilla          #+#    #+#             */
/*   Updated: 2021/11/26 17:53:54 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	Alloc a node structure representing a pipe.
**
**	@param	node	=>	the structure to alloc.
**	@param	ast		=>	the ast to store in the left child
**	of the pipe node.
**
**	@return	a pipe node.
*/

t_node	*create_pipe(t_node **node, t_node **ast)
{
	*node = NULL;
	*node = alloc(sizeof(t_node), &g_shell->a);
	(*node)->type = PIPE_NODE;
	(*node)->content.left = *ast;
	(*node)->content.right = NULL;
	return (*node);
}

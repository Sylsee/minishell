/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <arguilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 14:23:03 by arguilla          #+#    #+#             */
/*   Updated: 2021/11/28 12:55:15 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	Parse a token of type Pipe_token.
**
**	@param	tokens	=>	the list of tokens.
**	@param	ast	=> the ast to fill.
**
**	@return	a boolean value.
*/

t_bool	parse_pipe(t_token **tokens, t_node **ast)
{
	t_node	*node;

	while (*tokens && (*tokens)->type == Pipe_token)
	{
		skip_token(tokens);
		if (!check_pipe(*tokens))
			return (false);
		*ast = create_pipe(&node, ast);
		if (!create_cmd(&((*ast)->content.right), tokens))
			return (false);
	}
	return (true);
}

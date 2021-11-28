/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tokens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <arguilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:31:01 by arguilla          #+#    #+#             */
/*   Updated: 2021/11/25 15:24:09 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	Parse the tokens and fill the ast.
**
**	@param	tokens	=>	the list of tokens.
**	@param	ast	=>	the abstract syntax tree to fill.
**
**	@return	a boolean value.
*/

t_bool	parse_tokens(t_token **tokens, t_node **ast)
{
	t_node	*node;

	if (!create_cmd(&node, tokens))
		return (false);
	*ast = node;
	if (!parse_pipe(tokens, ast))
		return (false);
	return (true);
}

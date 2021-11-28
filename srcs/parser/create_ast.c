/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_ast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <arguilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:23:25 by arguilla          #+#    #+#             */
/*   Updated: 2021/11/26 18:44:14 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	This function read each tokens and create a abstract syntax tree
**	with the data of tokens.
**
**	@param	tokens	=>	the list of tokens.
**	@param	ast		=>	the abstract syntax tree to fill with tokens datas.
**
**	@return	boolean value.
*/

t_bool	create_ast(t_token **tokens, t_node **ast)
{
	*ast = NULL;
	while (*tokens)
		if (!parse_tokens(tokens, ast))
			return (false);
	return (true);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_add_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <arguilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 07:37:59 by arguilla          #+#    #+#             */
/*   Updated: 2021/11/14 07:45:53 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	Retrieve the last token of a linked list.
**
**	@param	token	=>	the linked list.
**
**	@return	the last token.
*/

static t_token	*last_token(t_token	*token)
{
	if (token)
		while (token->next)
			token = token->next;
	return (token);
}

/*
**	Add a new token at the end of a linked token list.
**
**	@param	tokens	=>	the linked list.
**	@param	token	=>	the new token.
**
**	@return	a boolean value (false if the token parameter is equal to NULL)
*/

t_bool	token_add_back(t_token **tokens, t_token *token)
{
	t_token	*tmp;

	if (!token)
		return (false);
	tmp = last_token(*tokens);
	if (tmp)
		tmp->next = token;
	else
		*tokens = token;
	return (true);
}

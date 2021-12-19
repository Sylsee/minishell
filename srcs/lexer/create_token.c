/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <arguilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 07:16:37 by arguilla          #+#    #+#             */
/*   Updated: 2021/11/16 12:07:28 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	This function create a new token.
**
**	@param	data	=>	the data that will be stored in the token.
**	@param	type	=>	the type of the data.
**
**	return	a new token.
*/

t_token	*create_token(char	*data, enum e_token_type type)
{
	t_token	*token;

	token = alloc(sizeof(*token), &g_shell->a);
	token->data = data;
	token->type = type;
	token->next = NULL;
	return (token);
}

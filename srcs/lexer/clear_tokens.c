/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_tokens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <arguilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 09:27:51 by arguilla          #+#    #+#             */
/*   Updated: 2021/11/23 15:11:35 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	Unset and free a linked list of tokens.
**
**	@param	tokens	=>	the tokens list.
**
**	@return	void.
*/

void	clear_tokens(t_token **tokens)
{
	t_token	*tmp;

	if (!*tokens)
		return ;
	while (*tokens)
	{
		free_one((*tokens)->data, NULL);
		tmp = *tokens;
		*tokens = (*tokens)->next;
		free_one(tmp, &g_shell->a);
	}
	*tokens = NULL;
}

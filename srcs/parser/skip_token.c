/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <arguilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 11:08:25 by arguilla          #+#    #+#             */
/*   Updated: 2021/11/26 11:19:10 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	Skip the first token of the list.
**
**	@param	tokens	=>	the list of tokens.
**
**	@return	void.
*/

void	skip_token(t_token **tokens)
{
	t_token	*tmp;

	if (!*tokens)
		return ;
	free_one((*tokens)->data, NULL);
	tmp = *tokens;
	*tokens = (*tokens)->next;
	free_one(tmp, &g_shell->a);
}

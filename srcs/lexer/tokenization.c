/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 17:00:25 by arguilla          #+#    #+#             */
/*   Updated: 2021/11/06 18:40:12 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	Create a list of tokens from a string.
**
**	@param	line	=>	the string will be tokenize
**	@param	tokens	=>	the linked list that will store the tokens.
**
**	@return	boolean value.
*/

t_bool	*tokenization(char *line, t_token **tokens)
{
	t_token	*tokens;
	int		i;

	tokens = NULL;
	i = -1;
	while (line && line[++i])
	{
		line = skip_space(line);
		tokens = add_new_token(line + i);
	}
	return (tokens);
}

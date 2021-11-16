/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_redirection_token.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <arguilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 10:46:32 by arguilla          #+#    #+#             */
/*   Updated: 2021/11/16 11:17:00 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	This function check if the current redirection token is a input or output
**	redirection and if the next character is a redirection. In this case,
**	the token is a heredoc.
**
**	@param	line	=>	the string starting by the new token.
**
**	@return a token structure.
*/

t_token	*get_redirection_token(char **line)
{
	t_token	*token;

	token = NULL;
	if ((*line)[0] == '<')
	{
		if ((*line)[1] == '<')
			token = create_token(ft_strdup("<<"), Iheredoc_token);
		else
			token = create_token(ft_strdup("<"), Iredir_token);
	}
	if ((*line)[0] == '>')
	{
		if ((*line)[1] == '>')
			token = create_token(ft_strdup(">>"), Oheredoc_token);
		else
			token = create_token(ft_strdup(">"), Oredir_token);
	}
	if (((*line)[0] == '>' && (*line)[1] == '>')
		|| ((*line)[0] == '<' && (*line)[1] == '<'))
		(*line)++;
	(*line)++;
	return (token);
}

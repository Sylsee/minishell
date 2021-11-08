/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 17:00:25 by arguilla          #+#    #+#             */
/*   Updated: 2021/11/08 19:38:07 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	Redirect the current token to the function dedicated to its type.
**
**	@param	line	=> the string contains the tokens.
**
**	@return	a new token structure.
*/

static t_token	*add_new_token(char	*line)
{
	enum e_char_type	char_type;
	t_token				*(*tokenizer[CHAR_TYPE_LENGTH])(char *);

 	tokenizer[Any_char] = &parse_word_token;
 	tokenizer[Space_char] = NULL;
 	tokenizer[Null_char] = NULL;
 	tokenizer[Squote_char] = tokenizer[Any_char];
 	tokenizer[Dquote_char] = tokenizer[Any_char];
 	tokenizer[Iredir_char] = &parse_iredir_token;
 	tokenizer[Oredir_char] = &parse_oredir_token;
 	tokenizer[Pipe_char] = &parse_pipe_token;;
	char_type = get_char_type(*line);
	return (tokenizer[char_type](line));
}

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

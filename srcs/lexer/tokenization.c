/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 17:00:25 by arguilla          #+#    #+#             */
/*   Updated: 2021/11/14 11:41:40 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	Increment the pointer of a string as long as the current character
**	is a space.
**
**	@param	str	=>	the string to increment.
**
**	@return	a new string starting by a no-space character.
*/

static char	*skip_space(char *str)
{
	while (str && ft_isspace(*str))
		str++;
	return (str);
}

/*
**	Redirect the current token to the function dedicated to its type.
**
**	@param	line	=> the string contains the tokens.
**
**	@return	a new token structure.
*/

static t_token	*add_new_token(char	**line)
{
	enum e_char_type	char_type;
	t_token				*(*tokenizer[CHAR_TYPE_LENGTH])(char **);

	tokenizer[Any_char] = &get_word_token;
	tokenizer[Space_char] = NULL;
	tokenizer[Null_char] = NULL;
	tokenizer[Squote_char] = tokenizer[Any_char];
	tokenizer[Dquote_char] = tokenizer[Any_char];
	tokenizer[Iredir_char] = &get_redirection_token;
	tokenizer[Oredir_char] = &get_redirection_token;
	tokenizer[Pipe_char] = &get_pipe_token;
	char_type = get_char_type(*(*line));
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

t_bool	tokenization(char *line, t_token **tokens)
{
	int		i;

	i = 0;
	while (*line)
	{
		line = skip_space(line);
		if (*line && !token_add_back(tokens, add_new_token(&line + i)))
			return (false);
	}
	t_token **copy;
	copy = tokens;
	while ((*tokens))
	{
		printf("token {\n\tdata: %s , type: %d\n}\n", (*tokens)->data, (*tokens)->type);
		*tokens = (*tokens)->next;
	}
	tokens = copy;
	return (true);
}

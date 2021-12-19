/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_word_token.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 19:41:11 by arguilla          #+#    #+#             */
/*   Updated: 2021/11/16 11:52:04 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	Initialize the data of the data structure.
**
**	@param	data	=>	the structure to be initialized.
**
**	return	void.
*/

static void	init_word_data(t_word_data	*data)
{
	data->i = -1;
	data->squotes = false;
	data->dquotes = false;
	data->word = NULL;
}

/*
**	Set the opening and closing of quotes.
**
**	@param	data	=> the structure contains all datas of the current token.
**	@param	flags	=> the flags can be SET_QUOTE or INIT_QUOTE.
**	This means whether we want to use the feature to define the quotes
**	the first time or to check them later.
**
**	return	void.
*/

static void	set_quotes(t_word_data *data, int flags)
{
	if (flags == INIT_QUOTE)
	{
		if (data->word_type == Squote_char)
			data->squotes = true;
		else if (data->word_type == Dquote_char)
			data->dquotes = true;
	}
	if (flags == CHECK_QUOTE)
	{
		if (data->word_type == Squote_char && data->squotes)
			data->squotes = false;
		else if (data->word_type == Dquote_char && data->dquotes)
			data->dquotes = false;
	}
}

/*
**	Check if we need to close a quote or set an errors if a quote is unclosed.
**
**	@param	data	=> the structure contains all datas of the current token.
**
**	return	boolean value.
*/

static bool	check_quotes(t_word_data *data)
{
	if (data->word_type == Null_char)
		return (NOT_VALID_CHAR);
	set_quotes(data, CHECK_QUOTE);
	return (VALID_CHAR);
}

/*
**	Check if the current character of the current token is valid.
**
**	@param	c	=> the character to be tested.
**	@param	data	=> the structure contains all datas of the current token.
**
**	return	boolean value.
*/

static bool	is_valid_char(char c, t_word_data *data)
{
	data->word_type = get_char_type(c);
	if (!data->squotes && !data->dquotes)
		set_quotes(data, INIT_QUOTE);
	else
		return (check_quotes(data));
	return (data->word_type == Any_char || data->word_type == Dquote_char
		|| data->word_type == Squote_char);
}

/*
**	This function check the current word token and if the token is valid,
**	then return a new token structure.
**
**	@param	line	=>	the string starting by the new token.
**
**	@return	a token structure.
*/

t_token	*get_word_token(char **line)
{
	t_word_data	data;

	init_word_data(&data);
	while (is_valid_char((*line)[++data.i], &data))
		;
	if ((*line)[data.i] == '\0' && (data.dquotes || data.squotes))
		return (NULL);
	data.word = ft_strndup(*line, data.i);
	*line += data.i;
	return (create_token(data.word, Word_token));
}

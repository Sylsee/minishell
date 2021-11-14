/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_char_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <arguilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 07:21:03 by arguilla          #+#    #+#             */
/*   Updated: 2021/11/14 07:26:54 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	Get the type of a character.
**
**	@param	c	=>	the character.
**
**	return	a enum set with the type of c.
*/

enum e_char_type	get_char_type(char c)
{
	enum e_char_type	char_type;

	char_type = Any_char;
	if (ft_isspace(c))
		char_type = Space_char;
	if (c == '\"')
		char_type = Dquote_char;
	if (c == '\'')
		char_type = Squote_char;
	if (c == '<')
		char_type = Iredir_char;
	if (c == '>')
		char_type = Oredir_char;
	if (c == '|')
		char_type = Pipe_char;
	if (c == '\0')
		char_type = Null_char;
	return (char_type);
}

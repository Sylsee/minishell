/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <arguilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 07:23:32 by arguilla          #+#    #+#             */
/*   Updated: 2021/11/14 11:23:23 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# define INIT_QUOTE 0
# define CHECK_QUOTE 1

/*
**	The data structure represents the informations about a word token.
**
**	@param	i	=>	the length of the current token.
**	@param	squotes	=>	the boolean to manage double quotes.
**	@param	dquotes	=>	the boolean to manage single quotes.
**	@param	word	=>	the extracted token.
**	@param	word_type	=>	the type of the extracted token.
*/

typedef struct s_word_data
{
	int					i;
	int					squotes;
	int					dquotes;
	char				*word;
	enum e_char_type	word_type;
}				t_word_data;

/*
** Main token
*/

t_bool				tokenization(char *line, t_token **tokens);

/*
** Tokens CRUD
*/

t_token				*create_token(char	*data, enum e_token_type type);
t_bool				token_add_back(t_token **tokens, t_token *token);
void				clear_tokens(t_token **tokens);

/*
** Getters
*/

t_token				*get_pipe_token(char **line);
t_token				*get_word_token(char **line);
t_token				*get_redirection_token(char **line);
enum e_char_type	get_char_type(char c);

#endif

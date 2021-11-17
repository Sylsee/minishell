/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <arguilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 07:23:32 by arguilla          #+#    #+#             */
/*   Updated: 2021/11/17 20:27:36 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# define INIT_QUOTE 0
# define CHECK_QUOTE 1

/*
**	The char_type enum contains the list of character types.
**
**	@var	Any_char		=>	basics characters.
**	@var	Space_char		=>	spaces characters, see ft_isspace() function.
**	@var	Null_char		=>	null character '\0'.
**	@var	Squote_char		=>	simple quote character '\''.
**	@var	Dquote_char		=>	double quote character '\"'.
**	@var	Iredir_char		=>	character starting by input redirections pattern '<'.
**	@var	Oredir_char		=>	character starting by output redirections pattern '>'.
**	@var	Pipe_char		=>	pipeline character '|'.
**	@var	CHAR_TYPE_LENGTH	=>	the enum length.
*/

enum	e_char_type
{
	Any_char,
	Space_char,
	Null_char,
	Squote_char,
	Dquote_char,
	Iredir_char,
	Oredir_char,
	Pipe_char,
	CHAR_TYPE_LENGTH
};

/*
**	The token_type enum contains the list of token types.
**
**	@var	Word_token		=>	a token starting with Any_char or Squote_char
**								or Dquote_char.
**	@var	Pipe_token		=>	a token starting with Pipe_char.
**	@var	Iheredoc_token	=>	a token equal to '<<'.
**	@var	Oheredoc_token	=>	a token equal to '>>'.
**	@var	Iredir_token	=>	a token equal to '<'.
**	@var	Oredir_token	=>	a token equal to '>'.
**	@var	TOKEN_TYPE_LENGHT	=>	the enum length.
*/

enum	e_token_type
{
	Word_token,
	Pipe_token,
	Iheredoc_token,
	Oheredoc_token,
	Iredir_token,
	Oredir_token,
	TOKEN_TYPE_LENGTH
};

/*
**	The token structure represents a token extracted by the lexer.
**
**	@var	type	=>	the token type.
**	@var	data	=>	the token string.
**	@var	next	=>	the next token.
*/

typedef struct s_token
{
	enum e_token_type	type;
	char				*data;
	struct s_token		*next;
}					t_token;

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

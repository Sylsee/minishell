/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 03:04:51 by spoliart          #+#    #+#             */
/*   Updated: 2021/11/02 17:18:40 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "utils.h"

/*
 * A FAIRE
 * une fois que tout fonctionne a peu pres, clean le bordel, re optimiser, re reflechir
 * premier objectif que ca fonctionne
 * mettre dans des fichiers, commenter en anglais
 * utiliser le garbage collector pour les mallocs
 */


# define NOT_VALID_CHAR 0
# define VALID_CHAR 1
# define TRUE 1
# define FALSE 0
# define INIT_QUOTE 1
# define CHECK_QUOTE 2

typedef	int	t_bool;
enum {
	false,
	true
};


#define	PIPE_NODE 0 
#define	CMD_NODE 1

/*
**	The cmd structure represents the linked data for the
**	execution of a command.
**	In the ast, this is the last part interpreted.
**
**	@var	argv	=>	the array that contains the arguments required
**	for the execution of the command.
**	@var	i_fd	=>	this is the input file descriptor (STDIN).
**	@var	o_fd	=>	this is the output file descriptor (STDOUT).
*/

typedef struct s_cmd
{
	char	**argv;
	int		i_fd;
	int		o_fd;
}				t_cmd;

/*
**	The content structure represents the content of a node of the ast.
**
**	@var	cmd		=> see the s_cmd (command structure) description.
**	@var	left	=> see the s_node (node structure) description.
**	@var	right	=> see the s_node (node structure) description.
**
**	the right and left structures are intended to represent the children of the current node.
**	If they are not null, it means that the current node is followed by one or more potential
**	other nodes (PIPE_NODE) and/or tree leaves (CMD_NODE).
*/

typedef struct s_content {
	struct s_cmd	cmd;
	struct s_node	*left;
	struct s_node	*right;
};

/*
** The node structure represents a node in a abstract syntax tree. A node is the representation
** of a branch in a tree. It then divides into several leaves or other branches.
**
**	@var	type	=>	the type of the node, see PIPE_NODE and CMD_NODE defines.
**	@var	content	=>	see the s_content (content structure) description.
*/

typedef struct s_node
{
	int 				type;
	struct s_content	content;		
}				t_node;

/*
**	The char_type enum contains the list of character types.
**
**	@var	Any_char	=>	basics characters.
**	@var	Space_char	=>	spaces characters, see ft_isspace() function.
**	@var	Null_char	=>	null character '\0'.
**	@var	Squote_char	=>	simple quote character '\''.
**	@var	Dquote_char	=>	double quote character '\"'.
**	@var	Iredir_char	=>	character starting by input redirections pattern '<'.
**	@var	Oredir_char	=>	character starting by output redirections pattern '>'.
**	@var	Pipe_char	=>	pipeline character '|'.
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
**	@var	Word_token	=>	a token starting with Any_char or Squote_char or Dquote_char.
**	@var	Pipe_token	=>	a token starting with Pipe_char.
**	@var	Iheredoc_token	=>	a token equal to '<<'.
**	@var	Oheredoc_token	=>	a token equal to '>>'.
**	@var	Iredir_token	=>	a token equal to '<'.
**	@var	Oredir_token	=>	a token equal to '>'.
**	@var	TOKEN_TYPE_LENGHT	=> the enum length.
*/

enum	e_token_type
{
	Word_token,
	Pipe_token,
	Iheredoc_token,
	OHeredoc_token,
	Iredir_token,
	Oredir_token,
	TOKEN_TYPE_LENGTH
};

/*
** The token structure represents a token extracted by the lexer.
**
**	@var	type	=>	the token type.
**	@var	data	=>	the token string.
**	@var	next	=>	the next token.
*/

typedef	struct	s_token
{
	enum	e_token_type type;
	char				*data;
	struct	s_token		*next;
}				t_token;

/*
** Check if a character si a space.
**
** @param	c	=> the character will be compared.
**
** @return	boolean value.
*/

int	ft_isspace(int c)
{
	return (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == ' ');
}

char	*skip_space(char *str)
{
	while (str && ft_isspace(*str))
		str++;
	return (str);
}


enum e_char_type	get_char_type(char c)
{
	enum e_char_type	char_type;

	char_type = Any_char;
	if (ft_isspace(c))
		char_type = Space_char;
	if (c == '\"')
		char_type = Dquote_char;
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

/*
** Structure representant les datas necessaires pour parser un token ayant pour char_type Any_char.
** 
** @var	i			=> increment
** @var	squotes		=> le booleen permettant de gerer les simples quotes
** @var	dquotes		=> le booleen permettant de gerer les doubles quotes
** @var	word		=> le token extrait
** @var word_type	=> le type du token
*/

typedef	struct	s_parser_word_data
{
	int					i;
	int					squotes;
	int					dquotes;
	char				*word;
	enum e_char_type	word_type;
}				t_parser_word_data;

void	init_parser_word_data(t_parser_word_data *data)
{
	data->i = -1;
	data->squotes = FALSE;
	data->dquotes = FALSE;
	data->word = NULL;
}

void	set_quotes(t_parser_word_data *data, int flags)
{
	if (data->word_type == Squote_char)
		data->squotes = TRUE;
	else if (data->word_type = Dquote_char)
		data->dquotes = TRUE;
}

void	check_quotes(t_parser_word_data *data)
{
	if (data->word_type == Null_char)
		return (NOT_VALID_CHAR);
	set_quotes(data, CHECK_QUOTES);
	return (VALID_CHAR);
}

t_bool	is_valid_char(char c, t_parser_word_data *data)
{
		t_bool	ret;

		data->word_type = get_char_type(c);
		if (!data->squotes && !data->dquotes)
			set_quotes(data, INIT_QUOTE);
		else
			ret = check_quotes(data);
}


t_token	*parse_word_token(char	*word)
{
	t_parser_word_data data;

	init_parser_word_data(&data);

	i  = -1;
	while (is_valid_char(word[++i]);
	//get_token_data
}
	

t_token	*add_new_token(char *line)
{
	enum e_char_type	char_type;
	t_token				*(*tokenizer[CHAR_TYPE_LENGTH])(char *);

 	tokenizer[Any_char] = &parse_word_token;
 	//tokenizer[Space_char] = NULL;
 	//tokenizer[Null_char] = NULL;
 	tokenizer[Squote_char] = tokenizer[Any_char];
 	tokenizer[Dquote_char] = tokenizer[Any_char];
 	tokenizer[Iredir_char] = &parse_iredir_token;
 	tokenizer[Oredir_char] = &parse_oredir_token;
 	tokenizer[Pipe_char] = &parse_pipe_token;;
	char_type = get_char_type(*line);
	return (tokenizer[char_type](line));
}

/*
 * la tokenization consiste a separer chaque tokens et de le lier a un type pour pouvoir l'interpreter
 */
t_token	*tokenization(char *line)
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

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;

	char *str;

	str = ft_strdup("echo bonjour | echo hey << a");

	/*
	 * On cree une liste chainee de tokens, qui sera utilise dans la fonction ast
	 */
	t_token	*tokens;
	tokens = tokenization(str);

	//ast(tokens);
	(void)str;
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 15:19:10 by spoliart          #+#    #+#             */
/*   Updated: 2021/11/12 00:21:46 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AST_H
# define AST_H

# define NOT_VALID_CHAR 0
# define VALID_CHAR 1
# define INIT_QUOTE 1
# define CHECK_QUOTE 2
# define PIPE_NODE 0
# define CMD_NODE 1

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
	OHeredoc_token,
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
**	The cmd structure represents the linked data for the execution of a command.
**	In the ast, this is the last part interpreted.
**
**	@var	argv	=>	the array that contains the arguments required for
**						the execution of the command.
**	@var	fd_in	=>	this is the input file descriptor (STDIN).
**	@var	fd_out	=>	this is the output file descriptor (STDOUT).
*/

typedef struct s_cmd
{
	char	**argv;
	int		fd_in;
	int		fd_out;
}			t_cmd;

/*
**	The content structure represents the content of a node of the ast.
**
**	@var	cmd		=>	see the s_cmd (command structure) description.
**	@var	left	=>	see the s_node (node structure) description.
**	@var	right	=>	see the s_node (node structure) description.
**
**	The right and left structures are intended to represent the children of
**	the current node.
**	If they are not null, it means that the current node is followed by one
**	or more potential
**	other nodes (PIPE_NODE) and/or tree leaves (CMD_NODE).
*/

typedef struct s_content
{
	struct s_cmd	cmd;
	struct s_node	*left;
	struct s_node	*right;
}					t_content;

/*
**	The node structure represents a node in a abstract syntax tree.
**	A node is the representation of a branch in a tree.
**	It then divides into several leaves or other branches.
**
**	@var	type	=>	the type of the node, see PIPE_NODE and CMD_NODE defines.
**	@var	content	=>	see the s_content (content structure) description.
*/

typedef struct s_node
{
	int					type;
	struct s_content	content;
}						t_node;

#endif
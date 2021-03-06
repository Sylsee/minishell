/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 15:19:10 by spoliart          #+#    #+#             */
/*   Updated: 2021/12/19 23:06:30 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AST_H
# define AST_H

# define NOT_VALID_CHAR 0
# define VALID_CHAR 1
# define PIPE_NODE 0
# define CMD_NODE 1

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
	bool	has_quotes;
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

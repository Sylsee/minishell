/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 03:06:11 by spoliart          #+#    #+#             */
/*   Updated: 2021/11/28 13:28:49 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "builtin.h"
# include "../libft/includes/libft.h"
# include <readline/readline.h>
# include <readline/history.h>
# include <stdbool.h>

# define NO_ERR 0
# define SYNTAX_ERR 2
# define ft_dprintf(fd, ...)  dprintf(fd, ##__VA_ARGS__) 

typedef struct s_shell
{
	char	**env;
	t_area	a;
	t_area	ast_area;
	int		exit_code;
}				t_shell;

/*
**	The e_error_msg enum represents the type of error message contained
**	in the error_msg function.
**
**	@var	ERR_EOL	=>	the array that contains the arguments required for
**	the execution of the command.
**	@var	ERR_EOL	=>	Error end of line, when a bracket isn't close..
**	@var	ERR_NEWFILE	=>	Error newfile, when a diamon operator
**	is the last token.
**	@var	ERR_TOK		=>	Error token, when a token doesn't respect
**	the rules related to its type.
**	@var	ERROR_MSG_LENGTH	=>	the enum length.
*/

enum	e_error_msg
{
	ERR_EOL,
	ERR_NEWFILE,
	ERR_TOK,
	ERROR_MSG_LENGTH
};

/*
** Global variables
*/
extern t_shell	*g_shell;

typedef short	t_bool;

/*
** Ast
*/

# include "ast.h"

/*
** Lexer
*/

# include "../srcs/lexer/lexer.h"
# include "../srcs/parser/parser.h"
/*
** Error
*/
void	internal_error(char *s, int code);
char	*ft_getenv(char *s);

#endif

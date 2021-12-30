/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 03:06:11 by spoliart          #+#    #+#             */
/*   Updated: 2021/12/27 22:16:52 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <signal.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stdarg.h>
# include "ast.h"
# include "exec.h"
# include "builtin.h"
# include "../libft/includes/libft.h"
# include "utils.h"
# include "system.h"

# define NO_ERR 0
# define SYNTAX_ERR 2
# define FAILURE_ERR 1
# define MALLOC_ERR	1
# define CTRLC_ERR	130


/*
**	Main structure
*/

typedef struct s_shell
{
	t_area	a;
	t_lst	*env;
	int		signum;
	int		heredoc_signal;
	int		savefd[2];
	int		exit_code;
	int		line_count;
	bool	is_multithreaded;
}			t_shell;

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
**	@var	ERR_TOO_LONG	=>	Error file, when a name of a file is too long.
**	@var	ERR_NO_FILE		=>	Error file, when a file doesn't exist.
**	@var	ERR_REDIRECT	=>	Error redirection, when a redirection is ambiguous
**	after a expansion.
**	@var	ERROR_MSG_LENGTH	=>	the enum length.
*/

enum	e_error_msg
{
	ERR_EOL,
	ERR_NEWFILE,
	ERR_TOK,
	ERR_TOO_LONG,
	ERR_NO_FILE,
	ERR_REDIRECT,
	ERROR_MSG_LENGTH
};

/*
** Global variables
*/

extern t_shell	*g_shell;

# include "test.h"
# include "../srcs/lexer/lexer.h"
# include "../srcs/parser/parser.h"
# include "../srcs/exec/exec.h"
# include "../srcs/redirection/redirection.h"
# include "../srcs/expansion/expansion.h"

#endif

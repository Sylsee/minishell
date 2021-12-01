/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 03:06:11 by spoliart          #+#    #+#             */
/*   Updated: 2021/12/01 19:08:18 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "ast.h"
# include "exec.h"
# include "builtin.h"
# include "../libft/includes/libft.h"
# include "utils.h"
# include "system.h"
# include <signal.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <readline/readline.h>
# include <readline/history.h>

# define ft_dprintf(X, str, ...) dprintf(X, str, __VA_ARGS__)

/*
**	Main structure
*/

typedef struct s_shell
{
	char	**env;
	t_area	a;
	int		exit_value;
	int		signum;
}				t_shell;

/*
** Global variables
*/

extern t_shell	*g_shell;

/*
** Error
*/

void	internal_error(char *s, int code);

#endif

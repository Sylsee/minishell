/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 03:06:11 by spoliart          #+#    #+#             */
/*   Updated: 2021/12/06 19:45:10 by spoliart         ###   ########.fr       */
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
	t_area	a;
	t_lst	*env;
	int		signum;
	int		savefd[2];
	int		exit_code;
}			t_shell;

/*
** Global variables
*/

extern t_shell	*g_shell;

# include "test.h"

#endif

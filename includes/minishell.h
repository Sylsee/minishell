/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 03:06:11 by spoliart          #+#    #+#             */
/*   Updated: 2021/11/12 02:25:32 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "ast.h"
# include "exec.h"
# include "builtin.h"
# include "../libft/includes/libft.h"
# include <signal.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <readline/readline.h>
# include <readline/history.h>

# define ft_dprintf(X, str, ...) dprintf(X, str, __VA_ARGS__)

typedef struct s_shell
{
	char	**env;
	t_area	a;
	int		exit_value;
}				t_shell;

/*
** Global variables
*/
extern t_shell	*g_shell;

/*
** Error
*/
void	internal_error(char *s, int code);

char	*ft_getenv(char *s);
char	*get_path(char *cmd);

#endif

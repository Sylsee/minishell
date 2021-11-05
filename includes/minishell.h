/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 03:06:11 by spoliart          #+#    #+#             */
/*   Updated: 2021/11/05 16:55:17 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "builtin.h"
# include "../libft/includes/libft.h"
# include <readline/readline.h>
# include <readline/history.h>
# include <stdbool.h>

typedef struct s_shell
{
	char	**env;
	t_area	a;
}				t_shell;

/*
** Global variables
*/
extern t_shell	*g_shell;

typedef short	t_bool;

/*
** Error
*/
void	internal_error(char *s, int code);
char	*ft_getenv(char *s);

#endif

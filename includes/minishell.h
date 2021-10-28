/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 03:06:11 by spoliart          #+#    #+#             */
/*   Updated: 2021/10/27 17:15:53 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "builtin.h"
# include "../libft/includes/libft.h"
# include <readline/readline.h>
# include <readline/history.h>

typedef struct	s_shell
{
	char	**env;
	t_area	a;
}				t_shell;

/*			GLOBAL			*/
extern t_shell	*g_shell;
/*			ERROR			*/
void	internal_error(char *s, int code);
char	*ft_getenv(char *s);

#endif

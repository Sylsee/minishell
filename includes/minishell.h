/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 03:06:11 by spoliart          #+#    #+#             */
/*   Updated: 2021/10/22 18:43:27 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "alloc.h"
# include "builtin.h"
# include "../libft/includes/libft.h"
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdint.h>

typedef struct	s_env
{
	t_area	area;
}				t_env;

/*			GLOBAL			*/
extern t_env	*genv;
/*			ERROR			*/
void	internal_error(char *s);
/*			UTILS			*/
char	*get_env(char *s);

#endif

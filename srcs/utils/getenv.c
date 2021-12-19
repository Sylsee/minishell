/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 16:40:29 by spoliart          #+#    #+#             */
/*   Updated: 2021/12/06 18:09:14 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	Get the content of the global variable
**
**	@param	name	=>	The name of the variable resqueted
**
**	@return	the content of the global variable or NULL if not found or empty
*/

char	*ft_getenv(char *name)
{
	t_lst	*tmp;

	if (!name || !*name || !g_shell->env)
		return (NULL);
	tmp = g_shell->env;
	while (tmp)
	{
		if (ft_strequ(tmp->name, name))
			return (tmp->content);
		tmp = tmp->next;
	}
	return (NULL);
}

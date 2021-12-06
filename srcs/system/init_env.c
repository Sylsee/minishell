/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 01:03:27 by spoliart          #+#    #+#             */
/*   Updated: 2021/12/06 21:02:12 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	Initialize the environment variable
**
**	@param	envp	=>	The environment variable supplied by the system
*/

void	init_env(char **envp)
{
	size_t	i;

	g_shell->env = NULL;
	i = 0;
	while (envp[i])
	{
		lst_addback(&g_shell->env, lstnew(envp[i]));
		i++;
	}
}

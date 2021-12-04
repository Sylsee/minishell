/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 10:25:03 by spoliart          #+#    #+#             */
/*   Updated: 2021/12/03 01:28:55 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	Get the string associated with the request variable
**
**	@param	s	=>	The variable resqueted in env
**
**	@return	the string or NULL if not found or empty
*/

char	*ft_getenv(char *s)
{
	char	**env;
	size_t	len_s;

	if (!s || !*s || !g_shell->env)
		return (NULL);
	env = g_shell->env;
	len_s = ft_strlen(s);
	while (*env)
	{
		if (ft_strncmp(*env, s, len_s) == 0)
		{
			if ((*env)[len_s] == '=')
				return (&((*env)[len_s + 1]));
			else if ((*env)[len_s] == '\0')
				return (NULL);
		}
		env++;
	}
	return (NULL);
}

/*
**	Reproduction of env function without any arguments
*/

void	run_env(void)
{
	char	**env;

	env = g_shell->env;
	while (*env)
	{
		ft_putendl_fd(*env, 1);
		env++;
	}
}

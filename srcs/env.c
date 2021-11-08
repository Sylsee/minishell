/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 10:25:03 by spoliart          #+#    #+#             */
/*   Updated: 2021/11/03 18:54:57 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_getenv(char *s)
{
	char	**env;
	size_t	len_s;

	if (!s || !*s || !g_shell->env)
		return (NULL);
	env = g_shell->env;
	len_s = ft_strlen(s);
	while (*env && ft_strncmp(*env, s, len_s))
		env++;
	if (*env && !ft_strncmp(*env, s, len_s))
		return (&((*env)[len_s + 1]));
	return (NULL);
}

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
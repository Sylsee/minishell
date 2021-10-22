/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 10:25:03 by spoliart          #+#    #+#             */
/*   Updated: 2021/10/20 18:44:18 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_env(char *s)
{
	size_t		len_s;
	extern char	**environ;

	if (!s || !*s)
		return (NULL);
	len_s = ft_strlen(s);
	while (*environ && ft_strncmp(*environ, s, len_s))
		environ++;
	return (*environ);
}

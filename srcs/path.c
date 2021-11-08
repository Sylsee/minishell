/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 15:24:13 by spoliart          #+#    #+#             */
/*   Updated: 2021/10/27 15:24:25 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*get_relative(char *cmd)
{
	if (access(cmd, F_OK))
		return (cmd);
	return (NULL);
}

static char	*get_absolute(char *cmd, char **env)
{
	bool	pass;
	char	*tmp;
	char	*path;

	tmp = NULL;
	pass = false;
	while (*env)
	{
		path = ft_strjoin(*env, cmd);
		if (pass == false && access(path, F_OK))
		{
			pass = true;
			tmp = path;
		}
		if (access(path, R_OK | X_OK))
			return (path);
		free(path);
		env++;
	}
	return (tmp);
}

char	*get_path(char *cmd)
{
	char		*path;
	char		**env;

	if (ft_strchr(cmd, '/') == NULL)
		return (get_relative_path(cmd));
	cmd = ft_strjoin("/", cmd);
	env = ft_split(getenv("PATH"), ":");
	path = get_absolute(cmd, env);
	ft_free_tab(env);
	free(cmd);
	return (path);
}
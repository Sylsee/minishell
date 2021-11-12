/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 15:24:13 by spoliart          #+#    #+#             */
/*   Updated: 2021/11/12 03:28:09 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*get_relative(char *cmd)
{
	if (access(cmd, F_OK) == 0)
		return (ft_strdup(cmd));
	return (NULL);
}

static char	*is_valid_path(char *path, char **tmp)
{
	if (*tmp == NULL && access(path, F_OK) == 0)
		tmp = &path;
	if (access(path, X_OK) == 0)
		return (path);
	if (*tmp != path)
		free_one(path, NULL);
	return (NULL);
}

static char	*get_absolute(char *cmd)
{
	char	*tmp;
	char	*path;
	char	**env;

	tmp = NULL;
	cmd = ft_strjoin("/", cmd);
	env = ft_split(getenv("PATH"), ":");
	while (*env)
	{
		path = ft_strjoin(*env, cmd);
		path = is_valid_path(path, &tmp);
		if (path)
		{
			if (tmp && tmp != path)
				free_one(tmp, NULL);
			free_one(cmd, NULL);
			ft_free_tab(env, NULL);
			return (path);
		}
		env++;
	}
	free_one(cmd, NULL);
	ft_free_tab(env, NULL);
	return (tmp);
}

/* Get complete path of the provide command */

char	*get_path(char *cmd)
{
	char		*path;

	if (ft_strchr(cmd, '/'))
		path = get_relative(cmd);
	else
		path = get_absolute(cmd);
	return (path);
}

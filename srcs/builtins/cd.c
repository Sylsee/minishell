/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 15:45:22 by spoliart          #+#    #+#             */
/*   Updated: 2021/12/28 15:20:31 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	Set the current working directory to PWD env variable
*/

static void	set_env_pwd(void)
{
	char	*pwd;

	pwd = getcwd((char *) NULL, 0);
	if (pwd == NULL)
	{
		perror("getcwd");
		return ;
	}
	set_env2("PWD", pwd);
	free(pwd);
}

/*
**	Get path if no supply or if it's a special path
**
**	@param	path	=>	The path to go
**
**	@return the path. On error return NULL
*/

static char	*get_special_path(char *path)
{
	if (path == NULL || ft_strequ(path, "--"))
	{
		path = ft_getenv("HOME");
		if (path == NULL)
		{
			ft_putendl_fd("minishell: cd: HOME not set", STDERR_FILENO);
			return (NULL);
		}
	}
	else if (ft_strequ(path, "-"))
	{
		path = ft_getenv("OLDPWD");
		if (path == NULL)
		{
			ft_putendl_fd("minishell: cd: OLDPWD not set", STDERR_FILENO);
			return (NULL);
		}
		ft_putendl_fd(path, STDOUT_FILENO);
	}
	return (path);
}

/*
**	Reproduction of cd function without options
*/

int	run_cd(int argc, char **argv)
{
	char	*path;
	char	*oldpwd;

	if (argc > 2)
	{
		ft_putstr_fd("minishell: cd: too many arguments\n", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	oldpwd = ft_getenv("PWD");
	path = get_special_path(argv[1]);
	if (path == NULL)
		return (EXIT_FAILURE);
	if (chdir(path) == -1)
	{
		ft_dprintf(STDERR_FILENO, "minishell: cd: %s: %s\n",
			path, strerror(errno));
		return (EXIT_FAILURE);
	}
	set_env2("OLDPWD", oldpwd);
	set_env_pwd();
	return (EXIT_SUCCESS);
}

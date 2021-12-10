/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 01:03:27 by spoliart          #+#    #+#             */
/*   Updated: 2021/12/10 17:42:40 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	Sets the default environment variables if none are provided
**	by the parent process.
*/

static void	set_default_env(void)
{
	char	*pwd;
	char	*shlvl;

	shlvl = ft_getenv("SHLVL");
	if (shlvl == NULL)
		shlvl = "0";
	shlvl = ft_itoa(ft_atoi(shlvl) + 1);
	set_env2("SHLVL", shlvl);
	set_env2("PATH", DEF_PATH);
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
**	Initialize the environment variables
**
**	@param	envp	=>	The environment variables provided by the parent process
*/

void	init_env(char **envp)
{
	char	*shlvl;

	g_shell->env = NULL;
	if (*envp == NULL)
		set_default_env();
	else
	{
		while (*envp)
		{
			lst_addback(&g_shell->env, lstnew(*envp));
			envp++;
		}
		shlvl = ft_getenv("SHLVL");
		if (shlvl == NULL)
			shlvl = "0";
		shlvl = ft_itoa(ft_atoi(shlvl) + 1);
		set_env2("SHLVL", shlvl);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 03:04:51 by spoliart          #+#    #+#             */
/*   Updated: 2021/10/25 11:59:27 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*g_env;

void	free_leaks(void) __attribute__((destructor));

void	free_leaks(void)
{
	printf("salut\n");
	fflush(stdout);
}

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

int	main(int argc, char **argv)
{
	char	*s;

	while (true)
	{
		s = readline("$ ");
		if (!s)
			break;
		free(s);
	}
	rl_clear_history();
	(void)argc;
	(void)argv;
	exit(0);
	return (0);
}
/*	int	*s;
	t_env	env;

	init_area(&env.area);
	genv = &env;
	s = alloc(sizeof(int) * 3, &genv->area);
	s[0] = 1;
	s[1] = 100;
	s[2] = 200;
	printf("s[0]: [%d]\ns[1]: [%d]\ns[2]: [%d]\n", s[0], s[1], s[2]);
	free_one(s, &genv->area);
		if (!ft_strncmp(s, "echo", 4))
			run_echo(s);*/

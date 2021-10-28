/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 03:04:51 by spoliart          #+#    #+#             */
/*   Updated: 2021/10/28 22:54:17 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_shell	*g_shell;

void	free_leaks(void) __attribute__((destructor));

void	free_leaks(void)
{
	free_area(&g_shell->a);
	free_area(NULL);
}

void	init_env(char **envp)
{
	size_t	i;

	init_area(NULL);
	g_shell->env = alloc(sizeof(char *) * (ft_tablen(envp) + 1), &g_shell->a);
	if (!g_shell->env)
		internal_error("Unable to allocate memory", EXIT_FAILURE);
	i = -1;
	while (envp[++i])
		g_shell->env[i] = ft_strdup(envp[i]);
	g_shell->env[i] = NULL;
}

int	main(int argc, char **argv, char **envp)
{
	char	*ls;
	char	*s;
	t_shell	shell;

	ft_memset(&shell, 0, sizeof(shell));
	init_area(&shell.a);
	g_shell = &shell;
	init_env(envp);
	while (true)
	{
		s = readline("$ ");
		if (!s)
			break ;
		ls = ft_getenv(s);
		if (ls)
			printf("%s\n", ls);
		free(s);
	}
	free(s);
	(void)argc;
	(void)argv;
	exit(0);
	return (0);
}

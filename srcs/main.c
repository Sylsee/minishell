/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 03:04:51 by spoliart          #+#    #+#             */
/*   Updated: 2021/11/14 11:41:36 by arguilla         ###   ########.fr       */
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

static void	init_env(char **envp)
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

static void	minishell(void)
{
	char	*s;
	t_token	*tokens;

	tokens = NULL;
#define DEBUG 0
#if DEBUG == 0
	while (true)
	{
		s = readline("$ ");
		if (!s)
		{
			printf("ayaaaa\n");
			break ;
		}
		tokenization(s, &tokens);
		clear_tokens(&tokens);
		free(s);
	}
	free(s);
#else
		tokenization(" s s s s", &tokens);
		clear_tokens(&tokens);
		tokenization("s s s s s s s s s s s ", &tokens);
		clear_tokens(&tokens);
#endif
		(void)s;

}

int	main(int argc, char **argv, char **envp)
{
	t_shell	shell;

	(void)argc;
	(void)argv;

	ft_memset(&shell, 0, sizeof(shell));
	init_area(&shell.a);
	g_shell = &shell;
	init_env(envp);
//	init_signal();
	minishell();
	exit(0);
	return (0);
}

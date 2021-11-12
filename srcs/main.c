/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 03:04:51 by spoliart          #+#    #+#             */
/*   Updated: 2021/11/12 03:15:17 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_shell	*g_shell;
/*
void	free_leaks(void) __attribute__((destructor));

void	free_leaks(void)
{
	free_area(&g_shell->a);
	free_area(NULL);
}
*/
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

static t_node	ast(char *s)
{
	t_node	ast;

	ast.type = CMD_NODE;
	ast.content.cmd.argv = ft_split(s, " ");
	ast.content.cmd.fd_in = STDIN_FILENO;
	ast.content.cmd.fd_out = STDOUT_FILENO;
	return (ast);
}

static void	minishell(void)
{
	t_node	tast;
	char	*s;

	while (true)
	{
		s = readline("$ ");
		if (!s)
			break ;
		// tokenizer();
		tast = ast(s);
		exec(&tast);
		ft_free_tab(tast.content.cmd.argv, NULL);
		free(s);
	}
	free(s);
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
	minishell();
	exit(0);
	return (0);
}

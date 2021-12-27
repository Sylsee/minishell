/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 03:04:51 by spoliart          #+#    #+#             */
/*   Updated: 2021/12/27 15:39:37 by spoliart         ###   ########.fr       */
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

char	*rl_gets(void)
{
	static char	*rl_line = NULL;

	if (rl_line)
	{
		free(rl_line);
		rl_line = NULL;
	}
	rl_line = readline("$ ");
	if (rl_line && *rl_line)
		add_history(rl_line);
	else if (!rl_line)
		write(STDOUT_FILENO, "exit\n", 5);
	g_shell->line_count++;
	return (rl_line);
}

static void	minishell(void)
{
	t_node	*ast;
	char	*rl_line;

	ast = NULL;
	while (true)
	{
		signal_on_input();
		rl_line = rl_gets();
		if (!rl_line)
			break ;
		if (*rl_line)
		{
			ast = get_ast(rl_line);
			if (ast != NULL)
			{
				exec(ast);
				free_ast(&ast);
			}
		}
	}
	if (rl_line != NULL)
		free(rl_line);
}

static void	inline_mode(void)
{
	int		ret;
	t_node	*ast;
	char	*line;

	ast = NULL;
	while (true)
	{
		ret = get_next_line(STDIN_FILENO, &line);
		if (ret == -1)
			internal_error("get_next_line error", EXIT_FAILURE);
		if (!line)
			break ;
		ast = get_ast(line);
		if (ast != NULL)
		{
			exec(ast);
			free_ast(&ast);
		}
		free(line);
		if (ret == 0)
			break ;
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_shell	shell;

	(void)argc;
	(void)argv;
	init_area(NULL);
	ft_memset(&shell, 0, sizeof(shell));
	init_area(&shell.a);
	shell.exit_code = NO_ERR;
	shell.line_count = 0;
	g_shell = &shell;
	init_env(envp);
	if (isatty(STDIN_FILENO) == 0)
		inline_mode();
	else
		minishell();
	free_lst(g_shell->env);
	exit(g_shell->exit_code);
	return (0);
}

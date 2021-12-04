/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 03:04:51 by spoliart          #+#    #+#             */
/*   Updated: 2021/12/03 02:58:49 by spoliart         ###   ########.fr       */
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
	return (rl_line);
}

static void	minishell(void)
{
	t_node	_ast;
	t_area	test;
	char	*rl_line;

	init_area(&test);
	while (true)
	{
		signal_on_input();
		rl_line = rl_gets();
		if (!rl_line)
			break ;
		if (*rl_line)
		{
			/* token = tokenizer(line); */
			_ast = ast(rl_line, test);
			exec(&_ast);
		}
	}
	free(rl_line);
}

static void	inline_mode(void)
{
	char	*line;
	t_node	_ast;
	t_area	test;

	init_area(&test);
	while (get_next_line(STDIN_FILENO, &line) > 0)
	{
		if (!line)
			break ;
		/* token = tokenizer(line); */
		_ast = ast(line, test);
		exec(&_ast);
		free(line);
	}
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
	if (isatty(STDIN_FILENO) == 0)
		inline_mode();
	else
		minishell();
	ft_free_tab(g_shell->env, NULL);
	exit(0);
	return (0);
}

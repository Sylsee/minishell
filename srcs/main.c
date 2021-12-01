/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 03:04:51 by spoliart          #+#    #+#             */
/*   Updated: 2021/12/01 19:06:19 by spoliart         ###   ########.fr       */
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
	g_shell->env = alloc(sizeof(char *) * (ft_tablen(envp) + 1), NULL);
	if (!g_shell->env)
		internal_error("Unable to allocate memory", EXIT_FAILURE);
	i = -1;
	while (envp[++i])
		g_shell->env[i] = ft_strdup(envp[i]);
	g_shell->env[i] = NULL;
}

static char	**until(char **args, char *c, t_area test)
{
	char	**ret;
	int		i;

	i = -1;
	ret = alloc(sizeof(char *) * 5, &test);
	while (args[++i] && ft_strcmp(args[i], c))
		ret[i] = strdup(args[i]);
	ret[i] = NULL;
	return (ret);
}

static char	**after(char **args, char *c, t_area test)
{
	char	**ret;
	int		i;
	int		j;

	i = 0;
	j = 0;
	ret = alloc(sizeof(char *) * 5, &test);
	while (args[i] && ft_strcmp(args[i], c))
		i++;
	while (args[++i])
		ret[j++] = strdup(args[i]);
	ret[j] = NULL;
	return (ret);
}

static t_node	ast(char *s, t_area test)
{
	t_node	ast;
	char	**args;

	if (ft_strchr(s, '|'))
	{
		args = ft_split(s, " ");
		ast.type = PIPE_NODE;
		ast.content.left = alloc(sizeof(t_node), &test);
		ast.content.right = alloc(sizeof(t_node), &test);
		ast.content.left->type = CMD_NODE;
		ast.content.left->content.cmd.argv = until(args, "|", test);
		ast.content.left->content.cmd.fd_in = STDIN_FILENO;
		ast.content.left->content.cmd.fd_out = STDOUT_FILENO;
		ast.content.right->type = CMD_NODE;
		ast.content.right->content.cmd.argv = after(args, "|", test);
		ast.content.right->content.cmd.fd_in = STDIN_FILENO;
		ast.content.right->content.cmd.fd_out = STDOUT_FILENO;
	}
	else
	{
		ast.type = CMD_NODE;
		ast.content.cmd.argv = ft_split(s, " ");
		ast.content.cmd.fd_in = STDIN_FILENO;
		ast.content.cmd.fd_out = STDOUT_FILENO;
	}
	return (ast);
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
		write(STDOUT_FILENO, "exit\n", 6);
	return (rl_line);
}

static void	minishell(void)
{
	t_node	tast;
	t_area	test;
	char	*rl_line;

	init_area(&test);
	while (true)
	{
		signal_on_input();
		rl_line = rl_gets();
		if (!rl_line)
			break ;
		/* token = tokenizer(line); */
		if (*rl_line)
		{
			tast = ast(rl_line, test);
			exec(&tast);
		}
	}
	free(rl_line);
}

static void	inline_mode(void)
{
	t_node	tast;
	char	*line;
	t_area test;

	init_area(&test);
	while (get_next_line(STDIN_FILENO, &line) > 0)
	{
		if (!line)
			break ;
		/* token = tokenizer(line); */
		tast = ast(line, test);
		exec(&tast);
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 03:04:51 by spoliart          #+#    #+#             */
/*   Updated: 2021/12/03 07:52:00 by arguilla         ###   ########.fr       */
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
	t_node	*ast;

	tokens = NULL;
	ast = NULL;
	while (true)
	{
		s = readline("$ ");
		g_shell->line_count++;
		if (!s)
			break ;
		add_history(s);
		if (tokenization(s, &tokens))
		{
			if (!create_ast(&tokens, &ast) || tokens)
				ast_error(tokens);
			else
			{
				printf("%s\n", ast->content.left->content.cmd.argv[0]);
			/*	"a | b"

				ast->type = PIPE_NODE
						->content.left = node qui contient "a"
						->content.right = node qui contient "b"
*/
				exec(ast);
			}
			//print_ast(ast);
			free_ast(&ast);
		}
		else
			g_shell->exit_code = SYNTAX_ERR;
		clear_tokens(&tokens);
		free(s);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_shell	shell;

	(void)argc;
	(void)argv;

	ft_memset(&shell, 0, sizeof(shell));
	init_area(&shell.a);
	shell.exit_code = NO_ERR;
	shell.line_count = 0;
	g_shell = &shell;
	init_env(envp);
//	init_signal();
	minishell();
	exit(0);
	return (0);
}

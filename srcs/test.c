/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 02:55:21 by spoliart          #+#    #+#             */
/*   Updated: 2021/12/03 02:58:15 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**until(char **args, char *c, t_area test)
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

char	**after(char **args, char *c, t_area test)
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

t_node	ast(char *s, t_area test)
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

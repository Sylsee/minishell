/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ast.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 08:29:52 by arguilla          #+#    #+#             */
/*   Updated: 2021/11/28 13:03:58 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_cmd(t_cmd *cmd)
{
	int	i;

	i = -1;
	printf("%s\n", "struct cmd:");
	printf("fd_in: %5d\nfd_out: %5d\n", cmd->fd_in, cmd->fd_out);
	printf("argv:\n");
	while (cmd->argv[++i])
		printf("%*s\n",(int) (10 + ft_strlen(cmd->argv[i])), cmd->argv[i]);
}

void	print_ast(t_node *ast)
{
	static int i = 0;
	if (ast)
	{
		printf("Couche %d:\n", i);
		i++;
		printf("%20s%d\n", "Ast type: ", ast->type);
		if (ast->type == CMD_NODE)
			print_cmd(&ast->content.cmd);
		else
		{
			print_ast(ast->content.left);
			print_ast(ast->content.right);
		}
	}
}

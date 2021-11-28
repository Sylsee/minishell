/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_ast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <arguilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 09:15:40 by arguilla          #+#    #+#             */
/*   Updated: 2021/11/28 13:03:31 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	Close the fds of a command structure.
**
**	@param	cmd	=> the command structure.
**
**	@return	void.
*/

static void	close_fd(t_cmd cmd)
{
	if (cmd.fd_in > 0 && cmd.fd_in != STDIN_FILENO)
		close(cmd.fd_in);
	if (cmd.fd_out > 0 && cmd.fd_out != STDOUT_FILENO)
		close(cmd.fd_out);
}

/*
**	Free a command node.
**
**	@param	ast	=>	the node to free.
**
**	@return	void.
*/

static void	free_cmd_node(t_node **node)
{
	int	i;

	i = 0;
	if (!*node)
		return ;
	while ((*node)->content.cmd.argv[i] != NULL)
	{
		free_one((*node)->content.cmd.argv[i], NULL);
		i++;
	}
	free_one((*node)->content.cmd.argv, &g_shell->a);
	close_fd((*node)->content.cmd);
	free_one(*node, &g_shell->a);
}

/*
**	Free a node and its child.
**
**	@param	node	=>	the ast to free.
**
**	@return	void.
*/

void	free_ast(t_node **node)
{
	if (!*node)
		return ;
	if ((*node)->type == CMD_NODE)
		free_cmd_node(node);
	else
	{
		free_ast(&((*node)->content.left));
		free_ast(&((*node)->content.right));
		free_one(*node, &g_shell->a);
	}
}

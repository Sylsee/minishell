/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_argv_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <arguilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 16:42:40 by arguilla          #+#    #+#             */
/*   Updated: 2021/11/28 13:02:51 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	Get the size of the argv of a command structure.
**
**	@param	tokens	=>	the list of tokens used to calculate the size.
**
**	@return	the size of argv.
*/

static int	get_argv_size(t_token *tokens)
{
	t_token	*head;
	int		nb;

	nb = 0;
	head = tokens;
	while (head && (head->type == Word_token
			|| is_redirection(head->type)))
	{
		head = head->next;
		nb++;
	}
	return (nb);
}

/*
**	Malloc and fill the argv array of a command structure.
**
**	@param	cmd	=>	the command structure containing the argv array.
**	@param	tokens	=>	the list of tokens to store in the array.
**
**	@return	a boolean value.
*/

bool	create_argv_cmd(t_cmd *cmd, t_token **tokens)
{
	int	i;

	i = -1;
	cmd->argv = NULL;
	cmd->argv = alloc(sizeof(char *) * (get_argv_size(*tokens) + 1),
			&g_shell->a);
	if (!cmd->argv)
		exit(1);
	while (++i != get_argv_size(*tokens))
		cmd->argv[i] = NULL;
	i = 0;
	while (*tokens
		&& ((*tokens)->type == Word_token || is_redirection((*tokens)->type)))
	{	
		if (!check_redirection(tokens))
			return (false);
		cmd->argv[i++] = ft_strdup((*tokens)->data);
		exit_if_equal(cmd->argv[i - 1], NULL, 1);
		skip_token(tokens);
	}
	cmd->argv[i] = NULL;
	return (true);
}

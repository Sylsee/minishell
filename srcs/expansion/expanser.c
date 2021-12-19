/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expanser.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 07:25:22 by arguilla          #+#    #+#             */
/*   Updated: 2021/12/19 18:20:41 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	Check if a argument contains a quotes.
**
**	@param	argv	=>	the list of arguments.
**	@param	i	=>	the cursor to identify the current argument.
**
**	@return	a boolean value.
*/

static t_bool	has_quotes(char **argv, int i)
{
	return (ft_strchr(argv[i + 1], '\'') != NULL
		|| ft_strchr(argv[i + 1], '"') != NULL);
}

/*
**	Manage the expansion of each argument.
**	
**	@param	cmd	=>	the cmd structure.
**
**	@return	a boolean value.
*/

t_bool	expanser(t_cmd *cmd)
{
	int	i;

	i = -1;
	while (cmd->argv[++i])
		if (check_var_pos(cmd->argv, i))
			if (!expand_vars(cmd, i))
				return (false);
	i = -1;
	while (cmd->argv[++i])
	{
		if (ft_strcmp(cmd->argv[i], "<<") == 0)
			cmd->has_quotes = has_quotes(cmd->argv, i);
		remove_quotes(&cmd->argv[i]);
	}
	return (true);
}

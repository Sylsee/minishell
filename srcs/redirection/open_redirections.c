/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_redirections.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 08:09:21 by arguilla          #+#    #+#             */
/*   Updated: 2021/12/19 20:27:50 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_bool	open_redirections(t_cmd *cmd)
{
	int	i;

	i = 0;
	while (cmd->argv[i])
	{
		if (!str_is_redirection(cmd->argv[i]))
		{
			i++;
			continue ;
		}
		if (!check_arg(cmd->argv[i + 1]))
			return (false);
		if (!redirections(cmd, &cmd->argv[i]))
			return (false);
		remove_redirections(&cmd->argv[i]);
	}
	return (true);
}

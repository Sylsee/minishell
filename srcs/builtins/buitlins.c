/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buitlins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 17:57:49 by spoliart          #+#    #+#             */
/*   Updated: 2021/12/01 17:58:27 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**
*/

int	is_builtin(char *cmd)
{
	int			i;
	const char	*builtin_cmd[8] = {
	[0] = "echo",
	[1] = "cd",
	[2] = "pwd",
	[3] = "export",
	[4] = "unset",
	[5] = "env",
	[6] = "exit",
	[7] = NULL
	};

	i = 0;
	while (builtin_cmd[i] && !ft_strequ(builtin_cmd[i], cmd))
		i++;
	if (builtin_cmd[i])
		return (ft_strequ(builtin_cmd[i], cmd));
	return (0);
}

/*
**
*/

void	run_builtin(t_cmd *cmd)
{
	if (ft_strequ(cmd->argv[0], "env"))
	{
		if (cmd->argv[1])
			printf("%s \n", ft_getenv(cmd->argv[1]));
		else
			run_env();
	}
	else if (ft_strequ(cmd->argv[0], "echo"))
		run_echo(&(cmd->argv[1]));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 17:57:49 by spoliart          #+#    #+#             */
/*   Updated: 2021/12/06 20:31:12 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	Check if this is a builtin command or not
**
**	@param	cmd	=>	The name of the command
**
**	@return 1 if the command is a builtin, else 0.
*/

int	is_builtin(char *cmd)
{
	int			i;
	const char	*builtins[] = {
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
	while (builtins[i] && ft_strequ(builtins[i], cmd) == 0)
		i++;
	return (builtins[i] != NULL);
}

/*
**	Run minishell builtins
**
**	@param	cmd	=>	The structure which contains the name of the commmand and
**					its arguments.
*/

void	run_builtin(t_cmd *cmd)
{
	short					i;
	const t_call_builtins	builtins[] = {
	{.name = "echo", .func = &run_echo},
	{.name = "cd", .func = &run_cd},
	{.name = "pwd", .func = &run_pwd},
	{.name = "export", .func = &run_export},
	{.name = "unset", .func = &run_unset},
	{.name = "env", .func = &run_env},
	{.name = "exit", .func = &run_exit},
	{.name = NULL, .func = NULL}
	};

	i = 0;
	while (builtins[i].name && ft_strequ(cmd->argv[0], builtins[i].name) == 0)
		i++;
	if (builtins[i].name)
		g_shell->exit_code = builtins[i].func(ft_tablen(cmd->argv), cmd->argv);
	else
		ft_dprintf(STDERR_FILENO, "minishell: %s: command not found\n",
			cmd->argv[0]);
}

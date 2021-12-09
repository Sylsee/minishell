/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 18:31:19 by spoliart          #+#    #+#             */
/*   Updated: 2021/12/09 02:39:28 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	Reproduction of exit function without any options
*/

int	run_exit(int argc, char **argv)
{
	if (argc <= 2)
	{
		close(g_shell->savefd[INPUT]);
		close(g_shell->savefd[OUTPUT]);
	}
	ft_putstr_fd("exit\n", STDERR_FILENO);
	if (argc == 1)
		exit(g_shell->exit_code);
	else if (ft_isnumeric(argv[1]) == 0)
	{
		ft_dprintf(STDERR_FILENO, "minishell: exit: %s: numeric argument "
			"required\n", argv[1]);
		exit(2);
	}
	else if (argc > 2)
	{
		ft_putstr_fd("minishell: exit: too many arguments\n", STDERR_FILENO);
		return (1);
	}
	exit(ft_atoi(argv[1]));
}

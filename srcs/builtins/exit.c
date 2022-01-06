/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 18:31:19 by spoliart          #+#    #+#             */
/*   Updated: 2022/01/06 22:56:48 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	Reproduction of exit function without any options
*/

void	exit_check_thread(unsigned char code)
{
	if (g_shell->is_multithreaded == false)
		exit(code);
}

int	run_exit(int argc, char **argv)
{
	if (argc <= 2 && g_shell->is_multithreaded == false)
	{
		close(g_shell->savefd[INPUT]);
		close(g_shell->savefd[OUTPUT]);
	}
	if (g_shell->is_multithreaded == false)
		ft_putstr_fd("exit\n", STDERR_FILENO);
	if (argc == 1)
		exit_check_thread((unsigned char)g_shell->exit_code);
	else if (argc > 1 && ft_isnumeric(argv[1]) == 0 && argv[1][0] != '-' &&
		argv[1][0] != '+' && ft_isnumeric(&argv[1][1]) == 0)
	{
		ft_dprintf(STDERR_FILENO, "minishell: exit: %s: numeric argument "
			"required\n", argv[1]);
		exit_check_thread(2);
	}
	else if (argc > 2)
	{
		ft_putstr_fd("minishell: exit: too many arguments\n", STDERR_FILENO);
		return (1);
	}
	if (argc > 1)
		exit_check_thread((unsigned char)ft_atoi(argv[1]));
	return (0);
}

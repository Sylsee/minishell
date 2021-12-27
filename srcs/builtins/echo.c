/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 05:35:10 by spoliart          #+#    #+#             */
/*   Updated: 2021/12/27 15:25:13 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	Print an array of string with '\n' if necessary
**
**	@param	s				=>	The array of strings
**	@param	display_return	=>	True if it's needed to display '\n' else false
*/

static void	print_tab(int argc, char **s, bool display_return)
{
	int	i;

	(void)argc;
	if (!s)
	{
		if (display_return == true)
			write(STDOUT_FILENO, "\n", 1);
		return ;
	}
	i = 0;
	while (s[i])
	{
		ft_putstr_fd(s[i], STDOUT_FILENO);
		i++;
		if (s[i])
			write(STDOUT_FILENO, " ", 1);
	}
	if (display_return == true)
		write(STDOUT_FILENO, "\n", 1);
}

/*
**	Reproduction of echo command with '-n' argument available
*/

int	run_echo(int argc, char **argv)
{
	size_t	i;
	bool	display_return;

	i = 0;
	display_return = true;
	if (*(++argv) && (*argv)[0] == '-' && (*argv)[1])
	{
		while ((*argv)[++i] == 'n')
			display_return = false;
		if ((*argv)[i])
			display_return = true;
		else
			argv++;
	}
	while (display_return == false && *argv && (*argv)[0] == '-')
	{
		i = 1;
		while ((*argv)[i] == 'n')
			i++;
		if ((*argv)[i])
			break ;
		argv++;
	}
	print_tab(argc, argv, display_return);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 05:35:10 by spoliart          #+#    #+#             */
/*   Updated: 2021/12/03 01:17:44 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	Print an array of string with '\n' if necessary
**
**	@param	s				=>	The array of strings
**	@param	display_return	=>	True if it's needed to display '\n' else false
*/

static void	print_tab(char **s, bool display_return)
{
	int	i;

	if (!s)
	{
		if (display_return == true)
			write(1, "\n", 1);
		return ;
	}
	i = 0;
	while (s[i])
	{
		ft_putstr_fd(s[i], 1);
		i++;
		if (s[i])
			write(1, " ", 1);
	}
	if (display_return == true)
		write(1, "\n", 1);
}

/*
**	Reproduction of echo command with '-n' argument available
**
**	@param	args	=>	The arguments to print
*/

void	run_echo(char **args)
{
	size_t	i;
	bool	display_return;

	i = 0;
	display_return = true;
	if (*args && (*args)[0] == '-' && (*args)[1])
	{
		while ((*args)[++i] == 'n')
			display_return = false;
		if ((*args)[i])
			display_return = true;
		else
			args++;
	}
	while (display_return == false && *args && (*args)[0] == '-')
	{
		i = 1;
		while ((*args)[i] == 'n')
			i++;
		if ((*args)[i])
			break ;
		args++;
	}
	print_tab(args, display_return);
}

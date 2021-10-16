/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 05:35:10 by spoliart          #+#    #+#             */
/*   Updated: 2021/10/16 09:06:43 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_tab(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		ft_putstr_fd(s[i], 1);
		i++;
		if (s[i])
			ft_putstr_fd(" ", 1);
	}
}

void	run_echo(char **arg)
{
	int	i;
	int	param;

	i = 0;
	param = 0;
	while (!ft_strcmp(arg[++i], "-n"))
		param = 1;
	if (param)
		print_tab(&arg[i]);
	else
	{
		print_tab(&arg[i]);
		ft_putstr_fd("\n", 1);
	}
}

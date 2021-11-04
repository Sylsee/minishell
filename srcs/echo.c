/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 05:35:10 by spoliart          #+#    #+#             */
/*   Updated: 2021/11/03 18:43:34 by spoliart         ###   ########.fr       */
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
			ft_putchar_fd(' ', 1);
	}
}

void	run_echo(char **arg)
{
	int	i;
	int	j;
	int	param;

	i = -1;
	j = -1;
	param = 0;
	while (arg[++i][0] == '-')
		while (arg[i][++j] == 'n')
			param = 1;
	print_tab(&arg[i]);
	if (!param)
		ft_putchar_fd('\n', 1);
}

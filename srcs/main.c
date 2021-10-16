/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 03:04:51 by spoliart          #+#    #+#             */
/*   Updated: 2021/10/16 09:09:48 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv)
{
	char	*s;
	char	**split;

	while ((s = readline("\e[32m$> \e[0m")))
	{
		split = ft_split(s, " ");
		if (!ft_strcmp(split[0], "echo"))
			run_echo(split);
		ft_free_tab(split);
		free(s);
	}
	rl_clear_history(s);
	(void)argc;
	(void)argv;
	return (0);
}

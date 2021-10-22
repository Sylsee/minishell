/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 03:04:51 by spoliart          #+#    #+#             */
/*   Updated: 2021/10/22 17:33:58 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*genv;

int	main(int argc, char **argv)
{
	int	*s;
	t_env	env;

	init_area(&env.area);
	genv = &env;
	s = alloc(sizeof(int) * 3, &genv->area);
	s[0] = 1;
	s[1] = 100;
	s[2] = 200;
	printf("s[0]: [%d]\ns[1]: [%d]\ns[2]: [%d]\n", s[0], s[1], s[2]);
	free_one(s, &genv->area);
/*	char	*s;

	while ((s = readline("$")))
	{
//		if (!ft_strncmp(s, "echo", 4))
//			run_echo(s);
		free(s);
	}
	rl_clear_history();*/
	(void)argc;
	(void)argv;
	return (0);
}

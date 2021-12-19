/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 10:25:03 by spoliart          #+#    #+#             */
/*   Updated: 2021/12/09 02:38:33 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	Reproduction of env function without any options or arguments
*/

int	run_env(int argc, char **argv)
{
	t_lst	*tmp;

	(void)argc;
	(void)argv;
	tmp = g_shell->env;
	while (tmp)
	{
		ft_dprintf(STDOUT_FILENO, "%s=%s\n", tmp->name, tmp->content);
		tmp = tmp->next;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 20:08:45 by spoliart          #+#    #+#             */
/*   Updated: 2021/12/09 02:41:47 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	Reproduction of unset function without any options
*/

int	run_unset(int argc, char **argv)
{
	if (argc == 1)
		return (0);
	argv++;
	while (*argv)
	{
		lstdelone(*argv);
		argv++;
	}
	return (0);
}

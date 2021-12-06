/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 16:00:28 by spoliart          #+#    #+#             */
/*   Updated: 2021/12/06 20:06:20 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	run_export(int argc, char **argv)
{
	(void)argc;
	if (argv[1] && ft_isdigit(argv[1][0]))
	{
		ft_dprintf(STDERR_FILENO, "minishell: export: `%s': not a valid "
			"identifier\n", argv[1]);
		return (1);
	}
	return (0);
}

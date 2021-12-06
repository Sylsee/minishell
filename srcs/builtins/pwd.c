/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 23:37:32 by spoliart          #+#    #+#             */
/*   Updated: 2021/12/06 20:21:17 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	run_pwd(int argc, char **argv)
{
	char	*dir;

	(void)argc;
	(void)argv;
	dir = getcwd((char *) NULL, 0);
	if (dir == NULL)
	{
		perror("getcwd");
		return (EXIT_FAILURE);
	}
	ft_putendl_fd(dir, STDOUT_FILENO);
	free(dir);
	return (EXIT_SUCCESS);
}

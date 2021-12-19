/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_redirections.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 14:47:04 by arguilla          #+#    #+#             */
/*   Updated: 2021/12/03 14:47:05 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	Remove a redirections of a array of redirections.
**
**	@param	argv	=>	the array contains elements to remove.
**
**	@return	void.
*/

void	remove_redirections(char **argv)
{
	int	i;

	i = 1;
	while (argv[++i] != NULL)
		argv[i - 2] = argv[i];
	argv[i - 2] = argv[i];
}

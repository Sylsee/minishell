/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstdelone.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 02:30:45 by spoliart          #+#    #+#             */
/*   Updated: 2021/12/10 17:31:03 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	Delete and free the matching environment variable
**
**	@param	name	=>	The name of the variable to delete
*/

void	lstdelone(char *name)
{
	t_lst	*current;
	t_lst	*to_delete;

	if (g_shell->env && ft_strequ(g_shell->env->name, name) == 1)
	{
		to_delete = g_shell->env;
		g_shell->env = to_delete->next;
		free_one(to_delete->name, NULL);
		free_one(to_delete->content, NULL);
		free_one(to_delete, NULL);
		return ;
	}
	current = g_shell->env;
	while (current && current->next
		&& ft_strequ(current->next->name, name) == 0)
		current = current->next;
	if (current && current->next)
	{
		to_delete = current->next;
		current->next = to_delete->next;
		free_one(to_delete->name, NULL);
		free_one(to_delete->content, NULL);
		free_one(to_delete, NULL);
	}
}

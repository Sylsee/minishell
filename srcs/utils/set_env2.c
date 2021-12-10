/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 15:01:14 by spoliart          #+#    #+#             */
/*   Updated: 2021/12/10 17:41:41 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	Check if name is an environment variable
**
**	@param	name	=>	The name of the variable to check
**
**	@return true if there is already an environment variable with this name,
**	else false
*/

static bool	in_env(char *name)
{
	t_lst	*tmp;

	tmp = g_shell->env;
	while (tmp)
	{
		if (ft_strequ(name, tmp->name))
			return (true);
		tmp = tmp->next;
	}
	return (false);
}

/*
**	Modify environment variable content
**
**	@param	name	=>	The name of the environment variable
**	@param	content	=>	The new content of the environment variable
*/

static void	modify_content(char *name, char *content)
{
	t_lst	*tmp;

	tmp = g_shell->env;
	while (tmp && ft_strequ(name, tmp->name) == 0)
		tmp = tmp->next;
	if (tmp)
	{
		free_one(tmp->content, NULL);
		tmp->content = ft_strdup(content);
		if (tmp->content == NULL)
			internal_error("unable to allocate memory", EXIT_FAILURE);
	}
}

/*
**	Set environment variable either by changing his content or by creating one
**
**	@param	name	=>	The name of the environment variable
**	@param	content	=>	The content to set of the environment variable
*/

void	set_env2(char *name, char *content)
{
	char	*new;

	if (in_env(name) == true)
		modify_content(name, content);
	else
	{
		new = ft_str3join(name, "=", content);
		lst_addback(&g_shell->env, lstnew(new));
		free_one(new, NULL);
	}
}

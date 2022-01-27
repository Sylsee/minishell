/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 19:14:46 by spoliart          #+#    #+#             */
/*   Updated: 2021/12/27 22:14:57 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	Check if this is the same variable name
**
**	@param	content	=>	The variable name to check
**	@param	name	=>	The environment variable
**
**	@return true if they are same, else false
*/

static bool	check_name(char *content, char *name)
{
	size_t	i;

	i = 0;
	while (content[i] && name[i] && content[i] == name[i])
		i++;
	if ((content[i] == '=' || content[i] == '\0') && name[i] == '\0')
		return (true);
	return (false);
}

/*
**	Check if name is an environment variable
**
**	@param	content	=>	The name of the variable to check
**
**	@return true if there is already an environment variable with this name,
**	else false
*/

static bool	in_env(char *content)
{
	t_lst	*tmp;

	tmp = g_shell->env;
	while (tmp)
	{
		if (check_name(content, tmp->name) == true)
			return (true);
		tmp = tmp->next;
	}
	return (false);
}

/*
**	Modify environment variable content
**
**	@param	content	=>	The new content of the environment variable
*/

static void	modify_content(char *content)
{
	size_t	i;
	t_lst	*tmp;

	tmp = g_shell->env;
	while (tmp && check_name(content, tmp->name) == false)
		tmp = tmp->next;
	if (tmp)
	{
		i = 0;
		while (content[i] && content[i] != '=')
			i++;
		if (content[i] == '=')
		{
			free_one(tmp->content, NULL);
			tmp->content = ft_strdup(&content[i + 1]);
			if (tmp->content == NULL)
				internal_error("unable to allocate memory", EXIT_FAILURE);
		}
	}
}

/*
**	Set environment variable either by changing his content or by creating one
**
**	@param	content	=>	The content to set of the environment variable
*/

void	set_env(char *content)
{
	if (in_env(content) == true)
		modify_content(content);
	else
		lst_addback(&g_shell->env, lstnew(content));
}

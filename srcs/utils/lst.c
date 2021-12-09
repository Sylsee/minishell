/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 19:03:59 by spoliart          #+#    #+#             */
/*   Updated: 2021/12/07 19:47:15 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	Add a token a front of the t_lst chained list
**
**	@param	alst	=>	The chained list
**	@param	new		=>	The new token
*/

void	lst_addback(t_lst **alst, t_lst *new)
{
	t_lst	*tmp;

	tmp = *alst;
	if (tmp)
		while (tmp->next)
			tmp = tmp->next;
	if (tmp)
		tmp->next = new;
	else
		*alst = new;
}

/*
**	Create a new token for t_lst chained list
**
**	@param	content	=>	The information to stock in the token
*/

t_lst	*lstnew(char *content)
{
	size_t	i;
	t_lst	*new;

	new = alloc(sizeof(t_lst), NULL);
	if (new == NULL)
		internal_error("unable to allocate memory", EXIT_FAILURE);
	new->name = alloc(sizeof(char) * (ft_strchr(content, '=') - content + 1),
			NULL);
	if (new->name == NULL)
		internal_error("unable to allocate memory", EXIT_FAILURE);
	i = -1;
	while (content[++i] && content[i] != '=')
		new->name[i] = content[i];
	new->name[i] = '\0';
	if (content[i] == '=')
	{
		new->content = ft_strdup(&(content[i + 1]));
		if (new->content == NULL)
			internal_error("unable to allocate memory", EXIT_FAILURE);
	}
	else
		new->content = NULL;
	new->next = NULL;
	return (new);
}

/*
**	Free a chained list and his content
**
**	@param	lst	=>	The chained list to free
*/

void	free_lst(t_lst *lst)
{
	t_lst	*tmp;

	while (lst)
	{
		tmp = lst->next;
		free_one(lst->name, NULL);
		free_one(lst->content, NULL);
		free_one(lst, NULL);
		lst = tmp;
	}
	lst = NULL;
}

/*
**	Get the size of the chained list
**
**	@param	lst	=>	The chained list
**
**	@return the size of the chained list
*/

size_t	lstsize(t_lst *lst)
{
	size_t	len;
	t_lst	*tmp;

	len = 0;
	tmp = lst;
	while (tmp)
	{
		len++;
		tmp = tmp->next;
	}
	return (len);
}

/*
**	Transform the chained list to an array of string
**
**	@param	lst	=>	The chained list containing the environment variable
**
**	@return the array of string containing the environment variable
*/

char	**lst_to_array(t_lst *lst)
{
	size_t	i;
	t_lst	*tmp;
	char	**env;

	env = alloc(sizeof(char *) * (lstsize(lst) + 1), NULL);
	if (env == NULL)
		internal_error("unable to allocate memory", EXIT_FAILURE);
	i = 0;
	tmp = lst;
	while (tmp)
	{
		env[i] = ft_str3join(tmp->name, "=", tmp->content);
		tmp = tmp->next;
		i++;
	}
	env[i] = NULL;
	return (env);
}

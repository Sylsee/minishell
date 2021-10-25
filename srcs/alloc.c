/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 12:35:21 by spoliart          #+#    #+#             */
/*   Updated: 2021/10/23 09:13:31 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
 * area-based allocation built on malloc/free
 */

t_area	*init_area(t_area *area)
{
	area->freelist = NULL;
	return (area);
}

/*
 * Malloc a link and put it in area freelist
 */

void	*alloc(size_t size, t_area *area)
{
	t_link	*l;

	if (size > SIZE_MAX - sizeof(t_link))
		internal_error("Unable to allocate memory");
	l = malloc(sizeof(t_link) + size);
	if (!l)
		internal_error("Unable to allocate memory");
	l->next = area->freelist;
	l->prev = NULL;
	if (area->freelist)
		area->freelist->prev = l;
	area->freelist = l;
	return ((void *)(((char *)(l)) + sizeof(t_link)));
}

/*
 * Free the link provided on the linked list (freelist) in area
 */

void	free_one(void *link, t_area *area)
{
	t_link	*l;

	if (!link)
		return ;
	l = (t_link *)(((char *)(link)) - sizeof(t_link));
	if (l->prev != NULL)
		l->prev->next = l->next;
	else
		area->freelist = l->next;
	if (l->next)
		l->next->prev = l->prev;
	free(l);
}

/*
 * Free the linked list (freelist) in area
 */

void	free_area(t_area *area)
{
	t_link	*freelist;
	t_link	*tmp;

	freelist = area->freelist;
	while (freelist != NULL)
	{
		tmp = freelist->next;
		free(freelist);
		freelist = tmp;
	}
	area->freelist = NULL;
}

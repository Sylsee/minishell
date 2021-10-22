/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 13:41:11 by spoliart          #+#    #+#             */
/*   Updated: 2021/10/22 18:12:51 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALLOC_H
# define ALLOC_H

# include <stddef.h>

typedef struct	s_link
{
	struct s_link	*prev;
	struct s_link	*next;
}				t_link;

typedef struct	s_area
{
	struct s_link	*freelist;
}				t_area;

t_area	*init_area(t_area	*area);
void	*alloc(size_t size, t_area *area);
void	free_one(void *ptr, t_area *area);
void	free_area(t_area *area);

#endif

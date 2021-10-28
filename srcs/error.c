/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 13:31:54 by spoliart          #+#    #+#             */
/*   Updated: 2021/10/27 17:06:54 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	internal_error(char *s, int code)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putendl_fd(s, 2);
	exit(code);
}

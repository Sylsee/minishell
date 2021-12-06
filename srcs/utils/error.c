/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 13:31:54 by spoliart          #+#    #+#             */
/*   Updated: 2021/12/03 01:12:40 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	Error function who print the error and exit the program
**
**	@param	s		=>	The error string
**	@param	code	=>	The value for exiting the program
*/

void	internal_error(char *s, int code)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putendl_fd(s, 2);
	exit(code);
}

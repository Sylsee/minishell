/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   incorrect_syntax_var.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 07:25:54 by arguilla          #+#    #+#             */
/*   Updated: 2021/12/19 07:26:34 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	Check if a variable name is correct, char by char.
**
**	@param	c	=>	the current character.
**
**	@return	a boolean value.
*/

bool	incorrect_syntax_var(char c)
{
	return (c == '\0' || ((ft_isalnum(c) == 0 && c != '_') && c != '?'));
}

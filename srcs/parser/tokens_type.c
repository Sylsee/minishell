/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <arguilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:38:19 by arguilla          #+#    #+#             */
/*   Updated: 2021/11/23 15:42:12 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	Check if the type of a token is a redirection.
**
**	@param	type	=>	the type of a token.
**
**	@return	a boolean value.
*/

t_bool	is_redirection(enum e_token_type type)
{
	return (type == Iheredoc_token || type == Oheredoc_token
		|| type == Iredir_token || type == Oredir_token);
}

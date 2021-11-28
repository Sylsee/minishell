/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <arguilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 14:25:48 by arguilla          #+#    #+#             */
/*   Updated: 2021/11/26 05:35:41 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	Check if there are a token after a pipe token.
**
**	@param	tokens	=>	the list of tokens.
**
**	@return	a boolean value.
*/

t_bool	check_pipe(t_token *tokens)
{
	if (tokens)
		return (true);
	ft_dprintf(STDERR_FILENO, "%s", error_msg(ERR_NEWFILE));
	return (false);
}

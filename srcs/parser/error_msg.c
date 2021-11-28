/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <arguilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 14:33:06 by arguilla          #+#    #+#             */
/*   Updated: 2021/11/28 13:01:54 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	Get a specific error message.
**
**	@param	id	=>	the identifier to get a specific message.
**
**	@return	a specific error message.
*/

const char	*error_msg(int id)
{
	const char	*errors[ERROR_MSG_LENGTH] = {
		"\nminishell: syntax error near unexpected token `newline'\n",
		"\nminishell: syntax error: unexpected end of file\n",
		"\nminishell: syntax error near unexpected token`"
	};

	return (errors[id]);
}

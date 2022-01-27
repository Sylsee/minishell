/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <arguilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 14:33:06 by arguilla          #+#    #+#             */
/*   Updated: 2021/12/03 09:35:21 by arguilla         ###   ########.fr       */
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
		"minishell: syntax error near unexpected token `newline'\n",
		"minishell: syntax error: unexpected end of file\n",
		"minishell: syntax error near unexpected token`",
		"File name too long\n",
		"No such file or directory\n",
		"ambiguous redirect\n"
	};

	return (errors[id]);
}

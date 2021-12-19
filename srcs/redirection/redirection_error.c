/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_error.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 14:46:08 by arguilla          #+#    #+#             */
/*   Updated: 2021/12/19 20:27:34 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	Display a error message if a redirecton fails
**
**	@param	filename	=>	the filename in the message.
**
**	@return	a boolean value.
*/

t_bool	redirection_error(char *filename)
{
	ft_dprintf(STDERR_FILENO, "minishell: %s : %s",
		filename, error_msg(ERR_NO_FILE));
	g_shell->exit_code = FAILURE_ERR;
	return (-1);
}

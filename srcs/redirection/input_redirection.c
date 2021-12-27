/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_redirection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 14:45:26 by arguilla          #+#    #+#             */
/*   Updated: 2021/12/03 14:53:35 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	Manage the input file redirection
**
**	@param	cmd	=>	the cmd structure.
**	@param	argv	=>	the array with arguments after the Iredir token.
**
**	@return	a boolean value.
*/

bool	input_redirection(t_cmd *cmd, char **argv)
{
	if (cmd->fd_in != STDIN_FILENO)
		close(cmd->fd_in);
	cmd->fd_in = open(argv[1], O_RDONLY);
	if (cmd->fd_in < 0)
		return (redirection_error(argv[1]));
	return (true);
}

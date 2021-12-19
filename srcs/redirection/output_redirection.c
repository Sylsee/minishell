/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_redirection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 14:45:47 by arguilla          #+#    #+#             */
/*   Updated: 2021/12/03 14:45:48 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	Manage the output redirection
**
**	@param	cmd	=>	the cmd structure.
**	@param	argv	=>	the array with arguments after the Oredir
**	or Oheredoc token.
**
**	@return	a boolean value.
*/

t_bool	output_redirection(t_cmd *cmd, char **argv)
{
	int	flag;

	if (cmd->fd_out != STDOUT_FILENO)
		close(cmd->fd_out);
	flag = O_APPEND;
	if (ft_strcmp(">", *argv) == 0)
		flag = O_TRUNC;
	argv++;
	cmd->fd_out = open(*argv, O_WRONLY | O_CREAT | flag,
			S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (!cmd->fd_out)
		return (redirection_error(*argv));
	return (true);
}

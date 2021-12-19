/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 14:46:45 by arguilla          #+#    #+#             */
/*   Updated: 2021/12/03 14:46:46 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	Manage all redirections.
**
**	@param	cmd	=>	the cmd structure.
**	@param	argv	=>	the current array of arguments.
**
**	@return	a boolean value.
*/

bool	redirections(t_cmd *cmd, char **argv)
{
	if (ft_strcmp("<", *argv) == 0)
		return (input_redirection(cmd, argv));
	if (ft_strcmp("<<", *argv) == 0)
		return (heredoc_redirection(cmd, argv));
	return (output_redirection(cmd, argv));
}

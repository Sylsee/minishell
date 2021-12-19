/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pipe_token.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <arguilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 09:41:38 by arguilla          #+#    #+#             */
/*   Updated: 2021/11/16 11:23:04 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	This function check the current pipe token and if the token is valid,
**	then return a new token structure.
**
**	@param	line	=>	the string starting by the new token.
**
**	@return	a token structure.
*/

t_token	*get_pipe_token(char **line)
{
	(*line)++;
	return (create_token(ft_strdup("|"), Pipe_token));
}

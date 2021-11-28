/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <arguilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 05:43:09 by arguilla          #+#    #+#             */
/*   Updated: 2021/11/26 16:28:15 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	Call if the token parsing failed, and the ast could not be filled.
**
**	@param	tokens	=>	the list of tokens.
**
**	@return	void.
*/

void	ast_error(t_token *tokens)
{
	if (tokens)
		ft_dprintf(STDERR_FILENO, "%s %s'\n", error_msg(ERR_TOK), tokens->data);
	g_shell->exit_code = SYNTAX_ERR;
}

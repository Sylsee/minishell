/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_redirection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <arguilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 18:02:55 by arguilla          #+#    #+#             */
/*   Updated: 2021/12/19 07:45:03 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	Check if the current token is a redirection and if the next token is valid
**	for a redirections pattern.
**
**	@param	tokens	=>	the list of tokens.
**
**	@return	a boolean value.
*/

bool	check_redirection(t_token **tokens)
{
	if (is_redirection((*tokens)->type) && (!(*tokens)->next
			|| (*tokens)->next->type != Word_token))
	{
		skip_token(tokens);
		if (!*tokens)
			ft_dprintf(STDERR_FILENO, "%s", error_msg(ERR_EOL));
		if (!*tokens || (*tokens)->type != Word_token)
			return (false);
	}
	return (true);
}

bool	str_is_redirection(char *str)
{
	return (ft_strcmp("<", str) == 0 || ft_strcmp("<<", str) == 0
		|| ft_strcmp(">", str) == 0 || ft_strcmp(">>", str) == 0);
}

bool	check_arg(char *arg)
{
	if (ft_strlen(arg) > MAX_REDIR_ARG_LENGTH)
	{
		ft_dprintf(STDERR_FILENO, "minishell: %s: %s",
			arg, error_msg(ERR_TOO_LONG));
		return (false);
	}
	return (true);
}

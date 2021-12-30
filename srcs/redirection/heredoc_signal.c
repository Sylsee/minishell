/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_signal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 18:52:03 by arguilla          #+#    #+#             */
/*   Updated: 2021/12/30 19:03:48 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
 **	This function set the ctrl c signum and the heredo_signal variable to true.
 **	Its call when we have a ctrl c signal.
 **
 **	@param	sig	=>	the signal.
 **
 **	@return	void.
 */

void	sigint_handler(int sig)
{
	g_shell->heredoc_signal = true;
	g_shell->signum = sig;
	rl_done = 1;
}

/*
 **	Hook call when readline is waiting for terminal input.
 **
 **
 **	@return	void.
 **/

int	event_hook(void)
{
	if (g_shell->heredoc_signal)
	{
		rl_replace_line("\1", 1);
		rl_done = 1;
	}
	return (0);
}

/*
 **	Check if the readline input contains ctrl c signal,
 **	and free the doc file with the current line.
 **
 **	@param	doc	=>	the heredoc file.
 **	@param	line	=>	the current line.
 **
 **	@return	a boolean value.
 **/

bool	catch_signal(char *doc, char *line)
{
	if (g_shell->heredoc_signal)
	{
		g_shell->heredoc_signal = false;
		if (line)
			free(line);
		if (doc)
			free_one(doc, NULL);
		return (true);
	}
	return (false);
}

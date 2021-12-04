/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 17:49:58 by spoliart          #+#    #+#             */
/*   Updated: 2021/12/03 01:35:14 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	redisplay_prompt(int signum)
{
	g_shell->exit_value = 128 + signum;
	write(1, "\n", 1);
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}

static void	interrupt_process(int signum)
{
	g_shell->exit_value = 128 + signum;
	write(1, "\n", 1);
}

/*
**	Sets the signals when the shell execute a command
*/

void	signal_on_exec(void)
{
	signal(SIGINT, &interrupt_process);
	signal(SIGQUIT, SIG_DFL);
}

/*
**	Sets the signals when the shell waits for a command
*/

void	signal_on_input(void)
{
	signal(SIGINT, &redisplay_prompt);
	signal(SIGQUIT, SIG_IGN);
}

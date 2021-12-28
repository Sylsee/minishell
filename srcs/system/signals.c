/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 17:49:58 by spoliart          #+#    #+#             */
/*   Updated: 2021/12/28 14:56:23 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	redisplay_prompt(int signum)
{
	g_shell->exit_code = 128 + signum;
	write(STDERR_FILENO, "\n", 1);
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}

static void	interrupt_process(int signum)
{
	g_shell->exit_code = 128 + signum;
	write(STDERR_FILENO, "\n", 1);
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

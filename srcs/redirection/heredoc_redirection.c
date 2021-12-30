/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_redirection.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 14:45:09 by arguilla          #+#    #+#             */
/*   Updated: 2021/12/29 00:42:12 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
 **	Join the last heredoc file with the new line.
 **
 **	@param	doc	=>	the heredoc content.
 **	@param	line	=>	the new line.
 **
 **	@return	void.
 */

static void	join(char **doc, char *line)
{
	char	*tmp;

	tmp = *doc;
	if (tmp == NULL)
	{
		*doc = ft_strdup(line);
		exit_if_equal(*doc, NULL, 1);
	}
	else
	{
		*doc = fill_doc(tmp, line, "\n");
		exit_if_equal(*doc, NULL, 1);
	}
	free_one(tmp, NULL);
	free(line);
}

static bool	catch_signal(char *doc, char *line)
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

/*
 ** Create the heredoc content by reading stdin.
 **
 **	@param	delimiter	=>	the heredoc delimiter.
 **
 **	@return	the heredoc content.
 */

static char	*heredoc(char *delimiter)
{
	char	*line;
	char	*doc;

	doc = NULL;
	while (true)
	{
		g_shell->heredoc_signal = false;
		line = readline("> ");
		if (catch_signal(doc, line))
			return (NULL);
		if (heredoc_control(delimiter, line))
			break ;
		//ft_putchar_fd('\n', STDERR_FILENO);
		join(&doc, line);
	}
	if (line)
		free(line);
	join(&doc, NULL);
	return (doc);
}

/*
 **	Get the fd of a heredoc file.
 **
 **	@param	str	=>	the heredoc delimiter.
 **	@param	has_quotes	=>	a boolean to say if
 **	the current delimiter contains quotes.
 **
 **	@return	the heredoc fd.
 */

static void	sigint_handler(int sig)
{
	g_shell->heredoc_signal = true;
	g_shell->signum = sig;
	rl_done = 1;
}

static int	event_hook(void)
{
	if (g_shell->heredoc_signal)
	{
		rl_replace_line("\1", 1);
		rl_done = 1;
	}
	return (0);
}

static int	get_heredoc_fd(char *str, bool has_quotes)
{
	char	*doc;
	int		fd[2];

	signal(SIGINT, &sigint_handler);
	rl_event_hook = &event_hook;
	doc = heredoc(str);
	rl_event_hook = NULL;
	if (!doc)
	{
		g_shell->exit_code = CTRLC_ERR;
		return (-1);
	}
	if (!has_quotes && doc)
		expand_stream_vars(&doc);
	if (pipe(fd) == -1)
		exit(1);
	if (doc)
		ft_putstr_fd(doc, fd[1]);
	close(fd[1]);
	if (doc)
		free_one(doc, NULL);
	return (fd[0]);
}

/*
 **	Manage the input of the heredoc redirection
 **
 **	@param	cmd	=>	the cmd structure.
 **	@param	argv	=>	the array with arguments after the heredoc token.
 **
 **	@return	a boolean value.
 */

bool	heredoc_redirection(t_cmd *cmd, char **argv)
{
	if (cmd->fd_in != STDIN_FILENO)
		close(cmd->fd_in);
	cmd->fd_in = get_heredoc_fd(*(argv + 1), cmd->has_quotes);
	if (cmd->fd_in < 0)
		return (false);
	return (true);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_redirection.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 14:45:09 by arguilla          #+#    #+#             */
/*   Updated: 2021/12/19 20:25:47 by arguilla         ###   ########.fr       */
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
		line = readline("> ");
		//if (catch_sigint(doc, line))
		//	return (NULL);
		if (heredoc_control(delimiter, line))
			break ;
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

static int	get_heredoc_fd(char *str, bool has_quotes)
{
	char	*doc;
	int		fd[2];

	doc = heredoc(str);
	if (!doc)
	{
		g_shell->exit_code = CTRLC_ERR;
		return (-1);
	}
	if (!has_quotes && !doc)
		expand_stream_vars(&doc);
	if (pipe(fd) == -1)
		exit(1);
	if (doc)
		ft_putstr_fd(doc, fd[1]);
	close(fd[1]);
	free_one(doc, NULL);
	return (fd[0]);
}

/*
**	Manage the input heredoc redirection
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
	if (!cmd->fd_in)
		return (false);
	return (1);
}

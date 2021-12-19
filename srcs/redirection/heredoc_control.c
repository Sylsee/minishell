#include "minishell.h"

/*
**	Display a message when CTRL-D is activated.
**
**	@param	delimiter	=>	this value will be displayed on the message.
**
**	@return	void.
*/

static void	ctrl_d_heredoc(char const *delimiter)
{
	ft_dprintf(STDERR_FILENO, "minishell: warning: here-document at line %d \
delimited by end-of-file (wanted `%s')\n",
		g_shell->line_count, delimiter);
}

/*
**	Check if a delimiter is the good.
**
**	@param	delimiter	=>	the delimiter to compare.
**	@param	line	=>	the line to compare.
**
**	@return	a boolean value.
*/

bool	heredoc_control(char *delimiter, char *line)
{
	if (!line && ft_strcmp(delimiter, "") == 0)
		return (true);
	else if (line)
	{
		if (line[0] == EOF)
		{
			ctrl_d_heredoc(delimiter);
			return (true);
		}
		if (ft_strcmp(line, delimiter) == 0)
			return (true);
		return (false);
	}
	return (false);
}

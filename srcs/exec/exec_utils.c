/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 14:28:03 by spoliart          #+#    #+#             */
/*   Updated: 2021/11/21 01:24:18 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	manage_error(char *path, char *cmd, char *error, int ret)
{
	free_one(path, NULL);
	ft_dprintf(STDERR_FILENO, "minishell: %s: %s\n", cmd, error);
	return (ret);
}

/*
**	Check error before execution
**
**	@param	path	=> Path of command
**	@param	cmd		=> Command to print if there is an error
**
**	@return	On success 0. On error the exit value.
*/

int	check_error(char *path, char *cmd)
{
	int	ret;

	if (!path)
	{
		if (ft_getenv("PATH") == NULL || ft_strchr(cmd, '/'))
			return (manage_error(NULL, cmd, strerror(ENOENT),
					127));
		else
			return (manage_error(NULL, cmd, "command not found",
					127));
	}
	ret = is_dir(path);
	if (ret == -1)
		return (manage_error(path, cmd, strerror(errno),
				126));
	else if (ret == 1)
		return (manage_error(path, cmd, strerror(EISDIR),
				127));
	if (access(path, X_OK) != 0)
		return (manage_error(path, cmd, strerror(errno),
				126));
	return (EXIT_SUCCESS);
}

/*
**	Print execution error
**
**	@param	sig	=>	The signal to print
*/

void	print_signal(int sig)
{
	const char	*tab[32] = {
	[SIGINT] = "\n",
	[SIGSEGV] = "Segmentation fault\n",
	[SIGBUS] = "Bus error\n",
	[SIGABRT] = "Aborted\n",
	[SIGQUIT] = "Quit\n",
	[SIGTERM] = "Terminated\n",
	[SIGTRAP] = "Trace/breakpoint trap\n",
	[SIGPIPE] = ""
	};

	if (tab[sig])
		ft_dprintf(STDERR_FILENO, "%s", tab[sig]);
	g_shell->exit_value = sig + 128;
}

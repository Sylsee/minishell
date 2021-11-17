/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 15:25:35 by spoliart          #+#    #+#             */
/*   Updated: 2021/11/17 15:51:35 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	Check if it's a directory
**
**	@param	path	=> The path to check
**
**	@return	1 if it's a directory, 0 otherwise
*/

int	is_dir(const char *path)
{
	struct stat	buf;

	if (stat(path, &buf) == -1)
		return (-1);
	return (S_ISDIR(buf.st_mode));
}

/*
**	A dup2() with error checking
**
**	@param	ofd	=>	the old file descriptor
**	@param	fd	=>	the new file descriptor
**	
**	@return	the new file descriptor
*/

int	ft_dup2(int ofd, int fd)
{
	int	ret;

	ret = dup2(ofd, fd);
	if (ret == -1)
		internal_error(strerror(errno), 1);
	return (ret);
}

/*
**	Set a new file descriptor and close the old one
**
**	@param	fd	=>	the new file descriptor
**	@param	ofd	=>	the old file descriptor
*/

void	restfd(int fd, int ofd)
{
	if (fd != ofd)
	{
		ft_dup2(ofd, fd);
		close(ofd);
	}
}

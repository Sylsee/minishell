/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 14:33:50 by spoliart          #+#    #+#             */
/*   Updated: 2021/11/23 22:54:25 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

int		is_dir(const char *path);
void	ft_dup2(int ofd, int fd);
void	restfd(int fd, int ofd);
char	*ft_getenv(char *s);
char	*get_path(char *cmd);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 14:33:50 by spoliart          #+#    #+#             */
/*   Updated: 2021/12/27 19:08:09 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

/* *** fd *** */
int		is_dir(const char *path);
void	ft_dup2(int ofd, int fd);
void	restfd(int fd, int ofd);

/* *** lst *** */
typedef struct s_lst
{
	char			*name;
	char			*content;
	struct s_lst	*next;
}					t_lst;

t_lst	*lstnew(char *content);
void	lst_addback(t_lst **alst, t_lst *new);
size_t	lstsize(t_lst *lst);
void	free_lst(t_lst *lst);
char	*ft_getenv(char *name);
char	**lst_to_array(t_lst *lst);
void	lstdelone(char *name);
void	set_env(char *content);
void	set_env2(char *name, char *content);

/* *** path *** */
char	*get_path(char *cmd);

/* *** Error *** */
void	internal_error(char *s, int code);

/* *** dprintf *** */
int		ft_dprintf(int fd, const char *fmt, ...);

#endif

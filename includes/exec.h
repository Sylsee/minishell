/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 02:13:32 by spoliart          #+#    #+#             */
/*   Updated: 2021/12/06 19:40:19 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# define INPUT 0
# define OUTPUT 1

void	exec(t_node *ast);
void	exec_cmd(t_cmd *cmd);
void	exec_pipe(t_content *pipe);

void	print_signal(int sig);
int		check_error(char *path, char *cmd);
int		manage_error(char *path, char *cmd, char *error, int ret);

#endif

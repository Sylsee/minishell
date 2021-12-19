/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 07:56:17 by arguilla          #+#    #+#             */
/*   Updated: 2021/12/19 20:08:19 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIRECTION_H
# define REDIRECTION_H

# define MAX_REDIR_ARG_LENGTH 255

t_bool	clear_redirections(t_node *ast);
t_bool	open_redirections(t_cmd *cmd);
t_bool	heredoc_redirection(t_cmd *cmd, char **argv);
t_bool	input_redirection(t_cmd *cmd, char **argv);
t_bool	output_redirection(t_cmd *cmd, char **argv);
t_bool	redirection_error(char *filename);
t_bool	redirections(t_cmd *cmd, char **argv);
t_bool	heredoc_control(char *delimiter, char *line);
void	remove_redirections(char **argv);
char	*fill_doc(char *s1, char *s2, char *s3);

#endif

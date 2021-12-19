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

bool	clear_redirections(t_node *ast);
bool	open_redirections(t_cmd *cmd);
bool	heredoc_redirection(t_cmd *cmd, char **argv);
bool	input_redirection(t_cmd *cmd, char **argv);
bool	output_redirection(t_cmd *cmd, char **argv);
bool	redirection_error(char *filename);
bool	redirections(t_cmd *cmd, char **argv);
bool	heredoc_control(char *delimiter, char *line);
void	remove_redirections(char **argv);
char	*fill_doc(char *s1, char *s2, char *s3);

#endif

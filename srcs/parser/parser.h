/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <arguilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:21:26 by arguilla          #+#    #+#             */
/*   Updated: 2021/12/19 22:55:55 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

t_node		*get_ast(char *line);
t_node		*create_pipe(t_node **node, t_node **ast);
const char	*error_msg(int id);
bool		create_ast(t_token **tokens, t_node **ast);
bool		parse_tokens(t_token **tokens, t_node **ast);
bool		is_redirection(enum e_token_type type);
bool		create_cmd(t_node **node, t_token **tokens);
bool		create_argv_cmd(t_cmd *node, t_token **tokens);
bool		check_redirection(t_token **tokens);
bool		parse_pipe(t_token **tokens, t_node **ast);
bool		check_pipe(t_token *tokens);
void		ast_error(t_token *tokens);
void		free_ast(t_node **node);
void		skip_token(t_token **tokens);
void		print_ast(t_node *ast);
bool		str_is_redirection(char *str);
bool		check_arg(char *arg);

#endif

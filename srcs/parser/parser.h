/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <arguilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:21:26 by arguilla          #+#    #+#             */
/*   Updated: 2021/11/28 13:00:54 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

t_node		*create_pipe(t_node **node, t_node **ast);
const char	*error_msg(int id);
t_bool		create_ast(t_token **tokens, t_node **ast);
t_bool		parse_tokens(t_token **tokens, t_node **ast);
t_bool		is_redirection(enum e_token_type type);
t_bool		create_cmd(t_node **node, t_token **tokens);
t_bool		create_argv_cmd(t_cmd *node, t_token **tokens);
t_bool		check_redirection(t_token **tokens);
t_bool		parse_pipe(t_token **tokens, t_node **ast);
t_bool		check_pipe(t_token *tokens);
void		ast_error(t_token *tokens);
void		free_ast(t_node **node);
void		skip_token(t_token **tokens);
void		print_ast(t_node *ast);

#endif

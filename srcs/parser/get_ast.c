/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 22:54:56 by spoliart          #+#    #+#             */
/*   Updated: 2021/12/19 22:55:06 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_node	*get_ast(char *line)
{
	t_node	*ast;
	t_token	*tokens;

	ast = NULL;
	tokens = NULL;
	if (tokenization(line, &tokens) == true)
	{
		if (create_ast(&tokens, &ast) == false || tokens != NULL)
			ast_error(tokens);
		clear_tokens(&tokens);
	}
	else
		g_shell->exit_code = SYNTAX_ERR;
	return (ast);
}

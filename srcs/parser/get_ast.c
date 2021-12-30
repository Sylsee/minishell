/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 22:54:56 by spoliart          #+#    #+#             */
/*   Updated: 2021/12/28 16:38:35 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	Create an ast with the tokenization method
**
**	@param	line	=>	The line returns from user
**
**	@return the ast
*/

t_node	*get_ast(char *line)
{
	t_node	*ast;
	t_token	*tokens;

	ast = NULL;
	tokens = NULL;
	if (tokenization(line, &tokens) == true)
	{
		if (create_ast(&tokens, &ast) == false || tokens != NULL)
		{
			ast_error(tokens);
			free_ast(&ast);
			ast = NULL;
		}
	}
	else
		g_shell->exit_code = SYNTAX_ERR;
	clear_tokens(&tokens);
	return (ast);
}

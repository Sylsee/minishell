/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_vars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 07:25:12 by arguilla          #+#    #+#             */
/*   Updated: 2021/12/19 07:30:16 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	Analyze a argument and expand its variables.
**
**	@param	cmd	=>	the cmd structure.
**	@param	cursor	=>	the cursor to identify the current argument.
**
**	return	a boolean value.
*/

bool	expand_vars(t_cmd *cmd, int cursor)
{
	int		j;
	bool	squotes;
	bool	dquotes;

	j = 0;
	dquotes = false;
	squotes = false;
	while (cmd->argv[cursor] != NULL && cmd->argv[cursor][j])
	{
		if (cmd->argv[cursor][j] == '$' && !squotes)
		{
			if (incorrect_syntax_var(cmd->argv[cursor][j + 1]))
				cmd->argv[cursor] = update_argv(
						&cmd->argv[cursor], 0, j++, "$");
			else
				if (expand_var(cmd, cursor, &j, dquotes) == false)
					return (false);
		}
		else
		{
			update_quotes(cmd->argv[cursor][j], &squotes, &dquotes);
			j++;
		}
	}
	return (true);
}

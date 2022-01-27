/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_vars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 07:25:12 by arguilla          #+#    #+#             */
/*   Updated: 2022/01/08 16:39:16 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*newstr(char *str, int j)
{
	char	*nstr;
	int		i;
	int		k;

	i = 0;
	k = 0;
	nstr = alloc(sizeof(char) * ft_strlen(str), &g_ftarea);
	exit_if_equal(NULL, nstr, 1);
	while (str[k])
	{
		if (i != j)
		{
			nstr[i] = str[k];
			i++;
		}
		else
			j = -1;
		k++;
	}
	nstr[i] = '\0';
	return (nstr);
}

static void	set_value(int *j, bool *dquotes, bool *squotes)
{
	*j = 0;
	*dquotes = false;
	*squotes = false;
}

static bool	check_quotes_dollars(char **argv, int cursor, int j, bool dquotes)
{
	if ((argv[cursor][j + 1] == '\''
		|| argv[cursor][j + 1] == '"') && !dquotes)
	{
		argv[cursor] = newstr(argv[cursor], j);
		return (true);
	}
	return (false);
}

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

	set_value(&j, &dquotes, &squotes);
	while (cmd->argv[cursor] != NULL && cmd->argv[cursor][j])
	{
		if (cmd->argv[cursor][j] == '$' && !squotes)
		{
			if (check_quotes_dollars(cmd->argv, cursor, j, dquotes))
				continue ;
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc_argv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 07:26:05 by arguilla          #+#    #+#             */
/*   Updated: 2021/12/19 07:37:50 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**  Check if the current expansion is correct.
**  Indeed, if the expansion is preceded by a redirection
**	(except heredoc input), and that this one contains several words
**	or is equal to an undefined result,
**  we say that the redirection is ambiguous.
**
**  @param  i   =>  the cursor to identify the current argument
**  @param  splitted    =>  the array of the list of word
**	containing in the variable_value
**  @param  argv    =>  the argv array containing the current argument
**	of a cmd structure
**
**  @return a boolean value.
*/

static t_bool	check_expansion(int i, char **splitted, char **argv)
{
	if (i > 0 && get_array_len(splitted) > 1
		&& str_is_redirection(argv[i - 1]))
	{
		ft_dprintf(STDERR_FILENO, "minishell: %s: %s", argv[i],
			error_msg(ERR_REDIRECT));
		free_tab(splitted, &g_shell->a);
		return (false);
	}
	return (true);
}

/*
**  Allocate a new array of arguments to include the new arguments
**	related to the expansion.
**
**  @param  cmd =>  the cmd structure.
**  @param  i   =>  the cursor to identify the current argument
**  @param  j   =>  the cursor to identify the current character
**  @param  char_value  =>  the value of a variable content
**
**  @return a boolean value.
*/

t_bool	realloc_argv(t_cmd *cmd, int i, int *j, char *var_value)
{
	t_expand	expand;

	expand.splitted = ft_split(var_value, " ");
	if (!check_expansion(i, expand.splitted, cmd->argv))
		return (false);
	init_expand(cmd->argv, var_value, &expand);
	expand.index_dollar = *j;
	expand.new_argv = alloc(sizeof(char *) * (expand.len_new_argv + 1),
			&g_shell->a);
	if (!expand.new_argv)
		exit(1);
	fill_new_argv(cmd, &expand, i);
	return (true);
}

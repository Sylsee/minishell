/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 07:24:58 by arguilla          #+#    #+#             */
/*   Updated: 2021/12/19 07:32:24 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**  Return a status code and free the variable name and content.
**
**  @param  var_name    =>  the variable name.
**  @param  var_value    =>  the variable content.
**
**  return  a boolean value.
*/

t_bool	exit_and_free_var(char *var_name, char *var_value, t_bool code)
{
	free_one(var_name, NULL);
	if (var_value)
		free_one(var_value, NULL);
	return (code);
}

/*
**  Expand a variable in a argument.
**
**  @param  cmd =>  the cmd structure.
**  @param  i   =>  the cursor to identify the current argument.
**  @param  j   =>  the cursor to identify the current character.
**  @param  dquotes =>  the boolean to check if we are
**  in a double quotes string.
**
**  @return a boolean value.
*/

t_bool	expand_var(t_cmd *cmd, int i, int *j, t_bool dquotes)
{
	char	*var_name;
	char	*var_value;

	get_var_infos(&cmd->argv[i][*j], &var_name, &var_value);
	if (dquotes == false && var_value != NULL
		&& *var_value != '\0' && has_space(var_value))
	{
		if (realloc_argv(cmd, i, j, var_value) == false)
			return (exit_and_free_var(var_name, var_value, true));
	}
	else
	{
		cmd->argv[i] = update_argv(&cmd->argv[i],
				ft_strlen(var_name), *j, var_value);
		*j += ft_strlen(var_value);
	}
	return (exit_and_free_var(var_name, var_value, true));
}

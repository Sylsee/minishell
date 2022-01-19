/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 07:24:58 by arguilla          #+#    #+#             */
/*   Updated: 2021/12/30 22:55:52 by arguilla         ###   ########.fr       */
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

bool	exit_and_free_var(char *var_name, char *var_value, bool code)
{
	free_one(var_name, NULL);
	if (var_value)
		free_one(var_value, NULL);
	return (code);
}

/*
 **	Remove a argument from the argv array.
 **
 **	@param	cmd	=>	the command structure.
 **	@param	i	=>	the id to the argument to delete.
 **	@param	j	=>	the cursor of characters in the
 **	current argument.
 **
 **	@return	void.
 */

static void	remove_arg(t_cmd *cmd, int i, int *j)
{
	char	*tmp;

	tmp = cmd->argv[i];
	*j = 0;
	while (cmd->argv[i])
	{
		cmd->argv[i] = cmd->argv[i + 1];
		i++;
	}
	free_one(tmp, NULL);
}

static bool	check_pos(char **argv, int i)
{
	if (i == 0)
		return (true);
	if (str_is_redirection(argv[i - 1]))
		return (false);
	return (true);
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

bool	expand_var(t_cmd *cmd, int i, int *j, bool dquotes)
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
		if (check_pos(cmd->argv, i) && var_value[0] == '\0'
			&& ft_strequ(&cmd->argv[i][1], var_name) == 1 && *j == 0)
			remove_arg(cmd, i, j);
		else
		{
			cmd->argv[i] = update_argv(&cmd->argv[i],
					ft_strlen(var_name), *j, var_value);
			*j += ft_strlen(var_value);
		}
	}
	return (exit_and_free_var(var_name, var_value, true));
}

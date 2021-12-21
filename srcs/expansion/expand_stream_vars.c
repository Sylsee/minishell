/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_stream_vars.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 18:21:07 by arguilla          #+#    #+#             */
/*   Updated: 2021/12/21 19:09:16 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**  Expand a variable in a argument from a heredoc file.
**
**	@param	arg	=>	the heredoc content.
**
**  @return void.
*/

void	expand_stream_vars(char **arg)
{
	int		i;
	char	*var_name;
	char	*var_value;

	i = 0;
	while ((*arg)[i])
	{
		if ((*arg)[i] == '$')
		{
			if ((*arg)[i] == '\0' || (ft_isalnum((*arg)[i + 1])
				&& (*arg)[i + 1] != '_'))
				*arg = update_argv(arg, 0, i++, "$");
			else
			{
				get_var_infos(*arg + i, &var_name, &var_value);
				*arg = update_argv(arg, ft_strlen(var_name), i, var_value);
				i += ft_strlen(var_value);
				exit_and_free_var(var_name, var_value, 0);
			}
		}
		else
			i++;
	}
}

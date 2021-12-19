/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_var_pos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 07:24:48 by arguilla          #+#    #+#             */
/*   Updated: 2021/12/19 07:30:29 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**  Check if a argument is eligible for expansion
**  depending on its position relative to the other
**  arguments.
**
**  @param  argv    =>  the array of arguments.
**  @param  cursor  =>  the cursor to identify the current argument.
**
**  @return a boolean value.
*/

t_bool	check_var_pos(char **argv, int cursor)
{
	return (ft_strchr(argv[cursor], '$') != NULL
		&& !(cursor > 0 && ft_strcmp(argv[cursor - 1], "<<") == 0));
}

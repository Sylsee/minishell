/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_expand.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 07:26:01 by arguilla          #+#    #+#             */
/*   Updated: 2021/12/19 07:29:29 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**  Calculates the new size of the argv array.
**
**  @param  expand  =>  the expand structure.
**
**  @return the new size.
*/

static int	len_new_arg(t_expand expand)
{
	return (expand.len_old_argv + expand.len_argv_to_add
		- (expand.first_join == false) - (expand.last_join == false)
		+ (expand.has_space == true));
}

/*
**  Initiailze the datas of the expand structure.
**
**  @param  argv    =>  the argv array containing the current arguments
**  of a cmd structure.
**  @param  var_value   =>  the variable value.
**  @param  expand      =>  the expand structure to fill.
**
**  @return void.
*/

void	init_expand(char **argv, char *var_value, t_expand *expand)
{
	expand->has_space = has_space(var_value);
	expand->first_join = (ft_isspace(var_value[0]) == 0);
	expand->last_join = (ft_isspace(var_value[ft_strlen(var_value) - 1]) == 0);
	expand->len_old_argv = get_array_len(argv);
	expand->len_argv_to_add = get_array_len(expand->splitted);
	expand->len_new_argv = len_new_arg(*expand);
	expand->i_old = 0;
	expand->i_new = 0;
	expand->i_split = 0;
}

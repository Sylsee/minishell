/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_new_argv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 07:25:32 by arguilla          #+#    #+#             */
/*   Updated: 2021/12/19 07:41:58 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**  Fill the new argv array with the new and last arguments.
**
**  @param  cmd =>  the cmd structure.
**  @param  expand  =>  the expand structure.
**  @param  i   =>  the cursor to identify the current argument.
**
**  @return void.
*/

void	fill_new_argv(t_cmd *cmd, t_expand *expand, int i)
{
	while (expand->i_new < i)
		expand->new_argv[expand->i_new++] = ft_strdup(
				cmd->argv[expand->i_old++]);
	handle_left(cmd->argv[i], expand);
	while (expand->i_split < expand->len_argv_to_add)
		expand->new_argv[expand->i_new++] = ft_strdup(
				expand->splitted[expand->i_split++]);
	handle_right(cmd->argv[i], expand);
	expand->i_old++;
	while (cmd->argv[expand->i_old])
		expand->new_argv[expand->i_new++] = ft_strdup(
				cmd->argv[expand->i_old++]);
	expand->new_argv[expand->i_new] = NULL;
	free_tab(cmd->argv, &g_shell->a);
	free_tab(expand->splitted, NULL);
	cmd->argv = expand->new_argv;
}

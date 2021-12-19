/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 07:25:46 by arguilla          #+#    #+#             */
/*   Updated: 2021/12/19 07:40:37 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**  Increment a pointer to the end of a variable name.
**
**  @param  str =>  the string containing the variable name.
**
**  @return the string after the variable name.
*/

static char	*skip_var_name(char *str)
{
	while (ft_isalnum(*str))
		str++;
	return (str);
}

/*
**  Join the left side content of a variable with the content of a variable.
**
**  @param  arg =>  the global content.
**  @param  expand  =>  the expand to structure.
**
**  @return void.
*/

void	handle_left(char *arg, t_expand *expand)
{
	char	*left;

	left = ft_strndup(arg, expand->index_dollar);
	if (expand->first_join)
	{
		expand->new_argv[expand->i_new] = ft_strjoin(left,
				expand->splitted[expand->i_split]);
		expand->i_new++;
		expand->i_split++;
		free_one(left, NULL);
	}
	else if (*left)
	{
		expand->new_argv[expand->i_new] = left;
		expand->i_new++;
	}
	else
		free_one(left, NULL);
}

/*
**  Join the right side content of a variable with the content of a variable.
**
**  @param  arg =>  the global content.
**  @param  expand  =>  the expand to structure.
**
**  @return void.
*/

void	handle_right(char *arg, t_expand *expand)
{
	char	*right;

	right = skip_var_name(&arg[expand->index_dollar + 1]);
	if (expand->last_join && *right)
	{
		free_one(expand->new_argv[expand->i_new - 1], NULL);
		expand->new_argv[expand->i_new - 1] = ft_strjoin(
				expand->splitted[expand->i_split - 1], right);
		if (!expand->new_argv[expand->i_new - 1])
			exit(1);
		expand->i_split++;
	}
	else if (*right != '\0')
	{
		expand->new_argv[expand->i_new++] = ft_strdup(right);
		if (!expand->new_argv[expand->i_new - 1])
			exit(1);
	}
}

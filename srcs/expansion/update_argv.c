/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_argv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 07:26:10 by arguilla          #+#    #+#             */
/*   Updated: 2021/12/19 07:35:27 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	Alloc a new argument.
**
**	@param	str	=>	the string that will be added to the new argument
**	@param	name_len	=>	the length of the variable name in the old argument.
**	@param	var	=>	the content of the variable
**
**	@return	the new argument allocates.
*/

static char	*stralloc(char *str, int name_len, char *var)
{
	char	*nstr;
	int		var_len;

	var_len = ft_strlen(var);
	nstr = alloc(sizeof(char) * (ft_strlen(str) - name_len + var_len),
			&g_ftarea);
	if (!nstr)
		exit(1);
	return (nstr);
}

/*
**	Update a current argument with its expanse.
**
**	@param	arg	=>	the last argument
**	@param	name_len	=>	the length of a variable name
**	@param	i	=>	the	current cursor
**	@param	var	=>	the content of a variable
**
**	@return	a new argument.
*/

char	*update_argv(char **arg, int name_len, int i, char *var)
{
	int		j;
	int		k;
	char	*nstr;

	j = -1;
	nstr = stralloc(*arg, name_len, var);
	while (++j < i)
		nstr[j] = (*arg)[j];
	k = -1;
	while (var[++k])
		nstr[j++] = var[k];
	i = i + name_len + 1;
	while ((*arg)[i] != '\0')
		nstr[j++] = (*arg)[i++];
	nstr[j] = '\0';
	free_one(*arg, NULL);
	return (nstr);
}

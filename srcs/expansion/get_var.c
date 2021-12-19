/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_var.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 07:25:41 by arguilla          #+#    #+#             */
/*   Updated: 2021/12/19 18:19:37 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	Set a negative value for the quotes characters.
**
**	@param	var_value	=>	the content of a variable.
**
**	@return	a str with quotes replaced by a character less than 0.
*/

char	*reverse_quotes(char *var_value)
{
	char	*str;
	int		i;

	if (var_value == NULL)
		return (NULL);
	i = -1;
	str = alloc(sizeof(*str) * (ft_strlen(var_value) + 1), &g_ftarea);
	if (!str)
		exit (1);
	while (var_value[++i] != '\0')
	{
		if (var_value[i] == '\'' || var_value[i] == '"')
			str[i] = -var_value[i];
		else
			str[i] = var_value[i];
	}
	str[i] = '\0';
	return (str);
}

/*
**  Get the name of a variable.
**
**  @param  arg =>  the argument contains the variable name.
**
**  @return a variable name.
*/

static char	*get_var_name(char *arg)
{
	int		i;
	int		size;
	char	*var_name;

	size = 0;
	i = -1;
	while (ft_isalnum(arg[size]) != 0 && arg[size])
		size++;
	var_name = alloc(sizeof(char) * (size + 1), &g_ftarea);
	if (!var_name)
		exit(1);
	while (ft_isalnum(arg[++i]) && arg[i])
		var_name[i - 1] = arg[i];
	var_name[i - 1] = '\0';
	return (var_name);
}

/*
**  Fill variables with the name and the content
**  of a bash variable.
**
**  @param  arg =>  the current argument.
**  @param  var_name    =>  the variable to fill.
**  @param  var_value   =>  the variable to fill.
**
**  @return void.
*/

void	get_var_infos(char *arg, char **var_name, char **var_value)
{
	if (*(arg + 1) == '?')
	{
		*var_name = ft_strdup("?");
		*var_value = ft_itoa(g_shell->exit_code);
		return ;
	}
	*var_name = get_var_name(arg);
	*var_value = reverse_quotes("bonjour' a tous");
	if (*var_value == NULL)
		*var_value = "";
}

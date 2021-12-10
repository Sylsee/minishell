/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 16:00:28 by spoliart          #+#    #+#             */
/*   Updated: 2021/12/10 17:31:35 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	Print the environment variable with special format
**
**	@return 0
*/

static int	export_print_env(void)
{
	t_lst	*tmp;

	tmp = g_shell->env;
	while (tmp)
	{
		ft_dprintf(STDOUT_FILENO, "declare -x %s=\"%s\"\n", tmp->name,
			tmp->content);
		tmp = tmp->next;
	}
	return (0);
}

/*
**	Check if the format of the variable to export is correct
**
**	@param	var	=>	The variable to export
**
**	@return true if the format is correct, else false
*/

static bool	check_format_export(char *var)
{
	if (ft_isdigit(*var))
		return (false);
	while (*var && *var != '=')
	{
		if (ft_isalnum(*var) == 0 && *var != '_')
			return (false);
		var++;
	}
	return (true);
}

/*
**	Reproduction of export function without any options
*/

int	run_export(int argc, char **argv)
{
	int	i;
	int	ret;

	if (argc == 1)
		return (export_print_env());
	i = 0;
	ret = 0;
	while (argv[++i])
	{
		if (check_format_export(argv[i]) == false)
		{
			ft_dprintf(STDERR_FILENO, "minishell: export: `%s': not a valid "
				"identifier\n", argv[i]);
			ret = 1;
		}
		else if (ft_strchr(argv[i], '='))
			set_env(argv[i]);
	}
	return (ret);
}

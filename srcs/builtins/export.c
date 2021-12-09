/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 16:00:28 by spoliart          #+#    #+#             */
/*   Updated: 2021/12/09 02:39:52 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

static bool	check_format_export(char *s)
{
	while (*s)
	{
		if (ft_isalnum(*s) == 0 && *s != '_' && *s != '=')
			return (false);
		s++;
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

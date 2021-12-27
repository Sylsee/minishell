/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 16:00:28 by spoliart          #+#    #+#             */
/*   Updated: 2021/12/27 22:55:17 by spoliart         ###   ########.fr       */
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

static int	check_format_export(char *var)
{
	int	i;

	i = 0;
	if (ft_isdigit(var[i]))
		return (-1);
	while (var[i] && var[i] != '=' && ft_strncmp(&var[i], "+=", 2) != 0)
	{
		if (ft_isalnum(var[i]) == 0 && var[i] != '_')
			return (-1);
		i++;
	}
	if (i == 0 && var[i] == '=')
		return (-1);
	if (var[i] && var[i + 1] && var[i] == '+' && var[i + 1] == '=')
	{
		if (i == 0)
			return (-1);
		return (1);
	}
	return (2);
}

/*
**	Add to environment variable a variabel with old and new content concatenated
**
**	@param	var	=>	The string contains name and content to add
*/

void	add_to_env(char *var)
{
	int		len;
	char	*name;
	char	*var_content;
	char	*env_content;

	len = ft_strchr(var, '+') - var;
	name = ft_strndup(var, len);
	if (name == NULL)
		internal_error("unable to allocate memory", EXIT_FAILURE);
	var_content = ft_strdup(&var[len + 2]);
	if (var_content == NULL)
		internal_error("unable to allocate memory", EXIT_FAILURE);
	env_content = ft_getenv(name);
	if (env_content == NULL)
		env_content = ft_strdup(var_content);
	else
		env_content = ft_strjoin(env_content, var_content);
	if (env_content == NULL)
		internal_error("unable to allocate memory", EXIT_FAILURE);
	free_one(var_content, NULL);
	set_env2(name, env_content);
	free_one(env_content, NULL);
	free_one(name, NULL);
}

/*
**	Reproduction of export function without any options
*/

int	run_export(int argc, char **argv)
{
	int	i;
	int	ret;
	int	format;

	if (argc == 1)
		return (export_print_env());
	i = 0;
	ret = 0;
	while (argv[++i])
	{
		format = check_format_export(argv[i]);
		if (format == -1)
		{
			ft_dprintf(STDERR_FILENO, "minishell: export: `%s': not a valid "
				"identifier\n", argv[i]);
			ret = 1;
		}
		else if (format == 1)
			add_to_env(argv[i]);
		else
			set_env(argv[i]);
	}
	return (ret);
}

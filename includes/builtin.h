/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 13:54:49 by spoliart          #+#    #+#             */
/*   Updated: 2021/12/06 19:46:22 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

typedef struct s_call_builtins
{
	char		*name;
	int			(*func)(int, char **);
}				t_call_builtins;

void	run_builtin(t_cmd *cmd);
int		is_builtin(char *cmd);

/* *** builtin functions *** */
int		run_echo(int argc, char **argv);
int		run_cd(int argc, char **argv);
int		run_pwd(int argc, char **argv);
int		run_export(int argc, char **argv);
int		run_unset(int argc, char **argv);
int		run_env(int argc, char **argv);
int		run_exit(int argc, char **argv);

#endif

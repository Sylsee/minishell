/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 08:00:52 by arguilla          #+#    #+#             */
/*   Updated: 2021/12/19 18:25:48 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANSION_H
# define EXPANSION_H

/*
**  The expand structure is the set of variables needed
**  to update the argv array.
**
**  @param  len_old_argv    =>  the lenght of the old argv.
**  @param  len_argv_to_add =>  the number of new argv.
**  @param  len_new_argv    =>  the length of the new argv array.
**  @param  first_join  =>  a boolean to check if the new arguments
**  must be preceded by old arguments.
**  @param  last_join   =>  a boolean to check if the new arguments
**  must be followed by old arguments.
**  @param  has_space   =>  a boolean to check if the current argument contains
**  spaces.
**  @param  i_old   =>  the cursor for the old argv array.
**  @param  i_new   =>  the cursor for the new argv array.
**  @param  i_split =>  the cursor for the splitted current argument.
**  @param  index_dollar    =>  the cursor in the current argument.
**  @param  new_argv    =>  the new array of arguments.
**  @param  splitted    =>  the current argument splitted with a space charset.
*/

typedef struct s_expand
{
	int		len_old_argv;
	int		len_argv_to_add;
	int		len_new_argv;
	bool	first_join;
	bool	last_join;
	bool	has_space;
	int		i_old;
	int		i_new;
	int		i_split;
	int		index_dollar;
	char	**new_argv;
	char	**splitted;
}			t_expand;

t_bool	expand_node(t_node *ast);
t_bool	check_var_pos(char **argv, int cursor);
t_bool	incorrect_syntax_var(char c);
t_bool	expand_vars(t_cmd *cmd, int cursor);
t_bool	expanser(t_cmd *cmd);
t_bool	expand_var(t_cmd *cmd, int i, int *j, t_bool dquotes);
t_bool	has_space(char *str);
t_bool	realloc_argv(t_cmd *cmd, int i, int *j, char *var_value);
t_bool	exit_and_free_var(char *var_name, char *var_value, t_bool code);
int		get_array_len(char **arr);
int		get_array_len(char **arr);
char	*update_argv(char **arg, int name_len, int i, char *var);
void	remove_quotes(char **arg);
void	update_quotes(char c, t_bool *squotes, t_bool *dquotes);
void	free_tab(char **tab, t_area *area);
void	handle_left(char *arg, t_expand *expand);
void	fill_new_argv(t_cmd *cmd, t_expand *expand, int i);
void	handle_right(char *arg, t_expand *expand);
void	init_expand(char **argv, char *var_value, t_expand *expand);
void	get_var_infos(char *arg, char **var_name, char **var_value);
void	exit_if_equal(char *s1, char *s2, int code);
void	expand_stream_vars(char **arg);

#endif

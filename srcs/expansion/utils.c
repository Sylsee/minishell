/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 07:26:14 by arguilla          #+#    #+#             */
/*   Updated: 2021/12/19 18:26:04 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	Exit if two values are equals.
**
**	@param	s1	=>	the first value.
**	@param	s2	=>	the second value.
**	@param	code	=>	the exit status code.
**
**	@return	void.
*/

void	exit_if_equal(char *s1, char *s2, int code)
{
	if (s1 == s2)
		exit(code);
}

/*
**  Check if a string containing a space.
**
**  @param  str =>  the string to check.
**
**  @return a boolean value.
*/

bool	has_space(char *str)
{
	while (*str)
	{
		if (ft_isspace(*str))
			return (true);
		str++;
	}
	return (false);
}

/*
**  Update the status of a quotes if necessary.
**
**  @param  c   =>  the character to check.
**  @param  squotes =>  the representation of a simple quotes.
**  @param  dquotes =>  the representation of a double quotes.
**
**  @return void.
*/

void	update_quotes(char c, bool *squotes, bool *dquotes)
{
	if (c == '\'' && !*dquotes)
		*squotes = !(*squotes);
	else if (c == '"' && !*squotes)
		*dquotes = !(*dquotes);
}

/* 
**  Get the length of a array.
**
**  @param  arr =>  the array to get length.
**
**  @return the array length.
*/

int	get_array_len(char **arr)
{
	int	len;

	len = 0;
	while (arr[len])
		len++;
	return (len);
}

/*
**  Free a array.
**
**  @param  tab =>  the array to free.
**  @param  area    =>  the area to use to free.
**
**  @return void.
*/

void	free_tab(char **tab, t_area *area)
{
	int	i;

	i = -1;
	if (!tab)
		return ;
	while (tab[++i])
		free_one(tab[i], NULL);
	free_one(tab, area);
}

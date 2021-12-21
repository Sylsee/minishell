/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 18:26:18 by arguilla          #+#    #+#             */
/*   Updated: 2021/12/21 13:15:06 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	Get the len of the new string without quotes.
**
**	@param	str	=>	the old string.
**
**	@return	the new string length.
*/

static int	get_len_wquotes(char *str)
{
	bool	squotes;
	bool	dquotes;
	int		i;
	int		len;

	squotes = false;
	dquotes = false;
	i = 0;
	len = 0;
	while (str[i])
	{
		if ((str[i] == '\'' && !dquotes)
			|| (str[i] == '"' && !squotes))
			update_quotes(str[i], &squotes, &dquotes);
		else
			len++;
		i++;
	}
	return (len);
}

/*
**	Replace the negative value set by the reverse_quotes() function.
**
**	@param	str	=>	the string with negative characters.
**
**	@return	void.
*/

static void	restore_quotes(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] < 0)
			str[i] *= -1;
}

/*
**	Replace a string with quotes by a string without quotes.
**
**	@param	str	=>	the string with quotes.
**
**	@return	the new string without quotes.
*/

static char	*remove_quote(char *str)
{
	bool	squotes;
	bool	dquotes;
	int		i;
	int		j;
	char	*wquotes;

	squotes = false;
	dquotes = false;
	i = 0;
	j = 0;
	wquotes = alloc(sizeof(char) * (get_len_wquotes(str) + 1), NULL);
	if (!wquotes)
		exit(1);
	ft_bzero(wquotes, get_len_wquotes(str) + 1);
	while (str[i] != '\0')
	{
		if ((str[i] == '\'' && !dquotes) || (str[i] == '"' && !squotes))
			update_quotes(str[i], &squotes, &dquotes);
		else
			wquotes[j++] = str[i];
		++i;
	}
	restore_quotes(wquotes);
	return (wquotes);
}

/*
**	Remove quotes from a string.
**
**	@param	arg	=>	the string with quotes.
**
**	@return	void.
*/

void	remove_quotes(char **arg)
{
	char	*tmp;

	tmp = remove_quote(*arg);
	free_one(*arg, NULL);
	*arg = tmp;
}

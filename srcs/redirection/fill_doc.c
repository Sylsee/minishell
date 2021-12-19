/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 20:06:16 by arguilla          #+#    #+#             */
/*   Updated: 2021/12/19 20:07:31 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	Fill the s1 with the s2 characters, starting by the index j.
**
**	@param	s1	=>	the string which receives.
**	@param	s2	=>	the string which fills.
**	@param	s1	=>	the cursor where begin filling s1.
**
**	@return	void.
*/

static void	assign(char *s1, char *s2, int *j)
{
	int	i;

	i = -1;
	while (s2[++i])
		s1[(*j)++] = s2[i];
}

/*
**	Update the current heredoc file with a new line.
**
**	@param	s1	=>	the current doc.
**	@param	s2	=>	the new line.
**	@param	s3	=>	the separator between s1 and s2.
**
**	@return	the new doc file.
*/

char	*fill_doc(char *s1, char *s2, char *s3)
{
	int		i;
	char	*nstr;

	i = 0;
	if (!s1 && !s2)
		return (NULL);
	if (!s1 && s2)
		return (fill_doc(s3, s2, ""));
	if (!s2)
		return (fill_doc(s1, s3, ""));
	if (!s1[0] && !s2[0])
		return (ft_strdup(""));
	nstr = alloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)
				+ ft_strlen(s3) + 1), &g_ftarea);
	exit_if_equal(nstr, NULL, 1);
	assign(nstr, s1, &i);
	assign(nstr, s3, &i);
	assign(nstr, s2, &i);
	nstr[i] = '\0';
	return (nstr);
}

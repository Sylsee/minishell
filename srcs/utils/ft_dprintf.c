/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 18:33:24 by arguilla          #+#    #+#             */
/*   Updated: 2021/12/27 20:44:10 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	convert(int fd, va_list *ap, const char *fmt, int *i)
{
	char	*r;

	r = NULL;
	if (fmt[1] == 's')
		r = va_arg(*ap, char *);
	else if (fmt[1] == 'd')
		r = ft_itoa(va_arg(*ap, int));
	else
		ft_putchar_fd(fmt[1], fd);
	if (r)
	{
		ft_putstr_fd(r, fd);
		(*i)++;
	}
	(*i)++;
}

static void	read_fmt(int fd, va_list *ap, const char *fmt)
{
	int	i;

	i = 0;
	while (fmt[i])
	{
		if (fmt[i] == '%')
			convert(fd, ap, &fmt[i], &i);
		else
		{
			write(fd, &fmt[i], 1);
			i++;
		}
	}
}

int	ft_dprintf(int fd, const char *fmt, ...)
{
	va_list	ap;

	if (!fmt)
		return (-1);
	va_start(ap, fmt);
	read_fmt(fd, &ap, fmt);
	va_end(ap);
	return (0);
}

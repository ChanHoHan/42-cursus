/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 13:43:48 by chan              #+#    #+#             */
/*   Updated: 2021/04/20 01:15:04 by chan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	s_printf_parsing(t_point *pt, char *s, char ch)
{
	int	len;
	int	i;

	i = 0;
	len = ft_strlen(s);
	if (pt->dot && pt->pre >= 0)
		len = compare_val(len, pt->pre, 0);
	if (pt->width > len)
	{
		if (pt->minus)
		{
			write(1, s, len);
			printf_zs(ch, pt->width - len);
		}
		else
		{
			printf_zs(ch, pt->width - len);
			write(1, s, len);
		}
		len = pt->width;
	}
	else
		write(1, s, len);
	return (len);
}

int	s_printf(t_point *pt, char *s)
{
	char	ch;

	if (!s)
		s = "(null)";
	if (pt->zero)
		ch = '0';
	else
		ch = ' ';
	return (s_printf_parsing(pt, s, ch));
}

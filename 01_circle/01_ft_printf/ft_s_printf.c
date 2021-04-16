/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 13:43:48 by chan              #+#    #+#             */
/*   Updated: 2021/04/15 21:49:33 by chan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		s_printf_parsing(t_point *pt, char *s)
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
			printf_zs(' ', pt->width - len);
		}
		else
		{
			printf_zs(' ', pt->width - len);
			write(1, s, len);
		}
		len = pt->width;
	}
	else
		write(1, s, len);
	return (len);
}

int		s_printf(t_point *pt, char *s)
{
	if (!s)
		s = "(null)";
	if (pt->width < 0)
		pt->width = -pt->width;
	return (s_printf_parsing(pt, s));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 13:43:48 by chan              #+#    #+#             */
/*   Updated: 2021/03/16 18:50:19 by chan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		s_printf_parsing(t_point *pt, char *s)
{
	int	len;
	int	i;
	
	i = 0;
	len = ft_strlen(s);
	if (pt->dot)
		len = compare_val(ft_strlen(s), pt->pre, 0);
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
	return (s_printf_parsing(pt, s));
}

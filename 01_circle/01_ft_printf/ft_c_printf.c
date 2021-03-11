/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chan <chan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 14:42:49 by chan              #+#    #+#             */
/*   Updated: 2021/03/11 13:33:03 by chan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	c_printf_zs(char val, int width)
{
	int		i;

	i = 1;
	while (i < width)
	{
		write(1, &val, 1);
		i++;
	}
}

void	c_printf_core(t_point *pt, int ch)
{
		if (pt->zero)
			c_printf_zs('0', pt->width);
		else
			c_printf_zs(' ', pt->width);
}

void	c_printf(t_point *pt, int ch)
{
	int		i;

	i = 0;
	if (pt->width)
	{
		if (pt->minus)
		{
			write(1, &ch, 1);
			c_printf_core(pt, ch);
		}
		else
		{
			c_printf_core(pt, ch);
			write(1, &ch, 1);
		}
	}
	else
		write(1, &ch, 1);
	return ;
}

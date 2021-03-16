/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chan <chan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 14:42:49 by chan              #+#    #+#             */
/*   Updated: 2021/03/16 18:39:38 by chan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	c_printf_core(t_point *pt)
{
		if (pt->zero)
			printf_zs('0', pt->width - 1);
		else
			printf_zs(' ', pt->width - 1);
}

int	c_printf(t_point *pt, int ch)
{
	int		rtn;

	rtn = 1;
	if (pt->width > 1)
	{
		if (pt->minus)
		{
			write(1, &ch, 1);
			c_printf_core(pt);
		}
		else
		{
			c_printf_core(pt);
			write(1, &ch, 1);
		}
		rtn = pt->width;
	}
	else
		write(1, &ch, 1);
	return (rtn);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lx_printf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chan <chan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 14:31:26 by chan              #+#    #+#             */
/*   Updated: 2021/04/19 15:48:56 by chan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	X_putnbr_printf(long long num)
{
	long long	quo;
	long long	rem;

	quo = num / 16;
	rem = num % 16;
	if (num > 15)
		X_putnbr_printf(quo);
	write(1, &LARGE[rem], 1);
}

void	X_num_padding_operation(t_point *pt, long long num, int *len)
{
	if (pt->sign)
		write (1, "-", 1);
	if (pt->padding > 0)
		printf_zs('0', pt->padding);
	if (!num && !pt->pre_ast && pt->dot && pt->pre <= 0)
	{
		if (!pt->width)
			(*len)--;
		return ;
	}
	if (pt->pre_ast && !pt->pre && !num)
	{
		(*len)--;
		return ;
	}
	X_putnbr_printf(num);
}

void	X_width_operation(t_point *pt, int *len, long long num)
{
	if (!num && !pt->pre_ast && pt->dot && pt->pre <= 0)
	{
		printf_zs(' ', pt->width);
		if (pt->width > 0)
			*len += pt->width - *len;
		return;
	}
	if (!pt->minus && !num && !pt->pre && pt->pre_ast)
		pt->width++;
	if (pt->width - *len <= 0)
		return ;
	printf_zs(' ', pt->width - *len);
	*len += pt->width - *len;
}

int	X_printf(t_point *pt, long long num)
{
	int	len;
	
	if (pt->pre < 0 && !pt->pre_ast)
		pt->width = -pt->pre;
	len = num_len(&num, pt, 16);
	if (pt->pre > len)
		pt->padding = pt->pre - len;
	if (pt->zero && pt->width - len > pt->padding)
		pt->padding = pt->width - len;
	len += pt->padding;
	if (pt->minus)
	{
		X_num_padding_operation(pt, num, &len);
		X_width_operation(pt, &len, num);
	}
	else
	{
		X_width_operation(pt, &len, num);
		X_num_padding_operation(pt, num, &len);
	}
	return (len);
}

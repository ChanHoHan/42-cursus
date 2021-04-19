/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 17:30:24 by chan              #+#    #+#             */
/*   Updated: 2021/04/19 16:48:25 by chan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	p_num_len(unsigned long long	num)
{
	int		len;

	len = 0;
	if (!num)
		return (1);
	while (num)
	{
		num = num / 16;
		len++;
	}
	return (len);
}

void		p_printf_print(t_point *pt, unsigned long long p)
{
	write(1, "0x", 2);
	if (pt->padding > 0)
		printf_zs('0', pt->padding);
	if (!(pt->dot && !p) || pt->pre < 0)
		putnbr_printf(p, 16, SMALL);
}

int		p_printf(t_point *pt, unsigned long long p)
{
	int	len;

	if (!p && pt->dot && pt->pre >=0)
		len = 2;
	else
		len = p_num_len(p) + 2;
	pt->padding = pt->pre - len + 2;
	if (pt->minus)
	{
		p_printf_print(pt, p);
		printf_zs(' ', pt->width - len);
	}
	else
	{
		printf_zs(' ' , pt->width - len);
		p_printf_print(pt, p);
	}
	if (pt->width > len)
		len = pt->width;
	if (pt->pre > len - 2)
		len = pt->pre + 2;
	return (len);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 17:30:24 by chan              #+#    #+#             */
/*   Updated: 2021/04/16 20:46:47 by chan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		p_printf_to_hex(unsigned long long p)
{
	unsigned long long	quo;
	unsigned long long	rem;

	quo = p / 16;
	rem = p % 16;
	if (p > 15)
		p_printf_to_hex(quo);
	write(1, &SMALL[rem], 1);
}

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

int		p_printf(t_point *pt, unsigned long long p)
{
	int	len;

	len = p_num_len(p) + 2;
	if (pt->width > len)
	{
		if (pt->minus)
		{
			write(1, "0x", 2);
			p_printf_to_hex(p);
			printf_zs(' ', pt->width - len);
		}
		else
		{
			printf_zs(' ' , pt->width - len);
			write(1, "0x", 2);
			p_printf_to_hex(p);
		}
		len = pt->width;
	}
	else
	{
		write (1, "0x", 2);
		p_printf_to_hex(p);
	}
	return (len);
}

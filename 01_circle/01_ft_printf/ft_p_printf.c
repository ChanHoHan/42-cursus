/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 17:30:24 by chan              #+#    #+#             */
/*   Updated: 2021/03/11 20:37:54 by chan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned long long	p_printf_to_hex(unsigned long long p, int *len)
{
	unsigned long long	quo;
	int			rem;

	quo = p / 16;
	rem = p % 16;
	if (quo > 15)
		p_printf_to_hex(quo);
	else
	{
		write(1, SMALL[quo], 1);
		(*len)++;
	}
	write(1, SMALL[rem], 1);
	(*len)++;
}

int		p_printf(t_point *pt, unsigned long long p)//구조체 받을 필요있는지 생각해보기
{
	int	len;

	write(1, "0x", 2); // dot 있으면 0x만 출력 
	len = 2;
	p_printf(p, &len);
	return (len);
}

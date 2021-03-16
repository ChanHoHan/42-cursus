/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 17:30:24 by chan              #+#    #+#             */
/*   Updated: 2021/03/16 16:46:25 by chan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		p_printf_to_hex(unsigned long long p, int *len)
{
	if (p > 16)
		p_printf_to_hex(p / 16, len);
	write(1, &SMALL[p % 16], 1);
	(*len)++;
}

int		p_printf(t_point *pt, unsigned long long p)
{
	int	len;

	write(1, "0x", 2); // pre 있으면 0x만 출력 
	len = 2;
	if (!p && pt->dot)
		return (len);
	p_printf_to_hex(p, &len);
	return (len);
}

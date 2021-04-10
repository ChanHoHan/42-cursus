/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chan <chan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 21:04:08 by chan              #+#    #+#             */
/*   Updated: 2021/04/09 21:32:28 by chan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	u_num_len(unsigned int *num, t_point *pt)
{
	int		len;
	int		_num;

	len = 0;
	_num = *num;
	if (*num < 0)
	{
		pt->sign = 1;
		*num = -(*num);
	}
	while (_num)
	{
		_num = _num / 10;
		len++;
	}
	return (len);
}

void	u_putnbr_printf(long long num)
{
	long long	quo;
	long long	rem;
	char		ch;

	quo = num / 10;
	rem = num % 10;
	if (quo > 10)
		u_putnbr_printf(quo);
	else
	{
		ch = '0' + quo;
		write(1, &ch, 1);
	}
	ch = '0' + rem;
	write(1, &ch, 1);
}

void	u_padding_operation(t_point *pt)
{
	if (pt->sign)
		write (1, "-", 1);
	if (pt->padding > 0)
		printf_zs('0', pt->padding);
}

void	u_width_operation(t_point *pt, int *len)
{
	if (pt->width - *len <= 0)
		return ;
	printf_zs(' ', pt->width - *len);
	*len = pt->width;
}

int	u_printf(t_point *pt, unsigned int num)
{
	int	len;
	
	len = u_num_len(&num, pt);
	if (pt->pre > len)
		pt->padding = pt->pre - len;//숫자 앞에 zero padding
	if (pt->zero && pt->width - len > pt->padding)
		pt->padding = pt->width - len;
	len += pt->padding;
	if (pt->minus)
	{
		u_padding_operation(pt);
		u_putnbr_printf(num);
		u_width_operation(pt, &len);
	}
	else
	{
		u_width_operation(pt, &len);
		u_padding_operation(pt);
		u_putnbr_printf(num);
	}
	return (len + pt->padding);//수정
}

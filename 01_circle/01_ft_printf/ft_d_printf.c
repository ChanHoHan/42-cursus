/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chan <chan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 14:31:26 by chan              #+#    #+#             */
/*   Updated: 2021/04/09 18:52:59 by chan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	num_len(int *num, t_point *pt)
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

void	putnbr_printf(long long num)
{
	long long	quo;
	long long	rem;
	char		ch;

	quo = num / 10;
	rem = num % 10;
	if (quo > 10)
		putnbr_printf(quo);
	else
	{
		ch = '0' + quo;
		write(1, &ch, 1);
	}
	ch = '0' + rem;
	write(1, &ch, 1);
}

void	padding_operation(t_point *pt)
{
	if (pt->sign)
		write (1, "-", 1);
	if (pt->padding > 0)
		printf_zs('0', pt->padding);
}

void	width_operation(t_point *pt, int *len)
{
	if (pt->width - *len <= 0)
		return ;
	printf_zs(' ', pt->width - *len);
	*len = pt->width;
}

int	d_printf(t_point *pt, int num)
{
	int	len;
// 출력할 자릿수, 띄어쓰기 또는 제로 padding, minus flag 체크
	len = num_len(&num, pt);
	if (pt->pre > len)
		pt->padding = pt->pre - len;//숫자 앞에 zero padding
	if (pt->sign == 1)
		len++;
	if (pt->zero && pt->width - len > pt->padding)
		pt->padding = pt->width - len;
	if (len + pt->padding >= pt->width)
		pt->width = 0;
	if (pt->minus)
	{
		padding_operation(pt);
		putnbr_printf(num);
		width_operation(pt, &len);
	}
	else
	{
		width_operation(pt, &len);
		padding_operation(pt);
		putnbr_printf(num);
	}
	return (len + pt->padding);//수정
}

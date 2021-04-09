/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chan <chan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 14:31:26 by chan              #+#    #+#             */
/*   Updated: 2021/04/09 16:48:24 by chan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	num_len(long long *num)
{
	int		len;

	len = 0;
	if (*num < 0)
		*num = -(*num);
	while (*num)
	{
		*num = *num / 10;
		len++;
	}
	return (len);
}

void	putnbr_printf(long long num)
{
	long long	quo;
	long long	rem;

	quo = num / 10;
	rem = num % 10;
	if (quo > 10)
		putnbr_printf(quo);
	write(1, &rem, 1);
}

void	padding_operation(t_point *pt)
{
	if (pt->sign)
		write (1, "-", 1);
	if (pt->padding > 0)
	{
		if (pt->zero)
			printf_zs('0', pt->padding);
		else
			printf_zs(' ', pt->padding);
	}
}

void	width_operation(t_point *pt, int len)
{
	if (len <= 0)
		return ;
	write(1, " ", len);
}

int	d_printf(t_point *pt, long long num)
{
	int	len;
// 출력할 자릿수, 띄어쓰기 또는 제로 padding, minus flag 체크

	//printf("%lld", num);
	if (num < 0)
		pt->sign = 1;
	printf("%d", pt->sign);
	len = num_len(&num);
	if (pt->pre > len)
		pt->padding = len - pt->pre;//숫자 앞에 zero padding
	if (pt->sign < 0)
		len++;
	if (pt->zero && pt->width - len > pt->padding)
		pt->padding = pt->width;
	if (pt->minus)
	{
		width_operation(pt, pt->width - len);
		padding_operation(pt);
		putnbr_printf(num);
	}
	else
	{
		padding_operation(pt);
		putnbr_printf(num);
		width_operation(pt, pt->width - len);
	}
	return (0);//수정
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chan <chan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 14:31:26 by chan              #+#    #+#             */
/*   Updated: 2021/04/16 19:50:07 by chan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	num_len(long long *num, t_point *pt)
{
	int		len;
	long long	_num;

	len = 0;
	if (*num < 0)
	{
		pt->sign = 1;
		*num = -(*num);
	}
	_num = *num;
	if (*num == 0)
		return (1);
	if (!pt->pre_ast && pt->pre > 0)
		pt->zero = 0;
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
	if (num > 10)
		putnbr_printf(quo);
	ch = '0' + rem;
	write(1, &ch, 1);
}

void	num_padding_operation(t_point *pt, long long num, int *len)
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
	putnbr_printf(num);
}

void	width_operation(t_point *pt, int *len, long long num)//
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
	//printf("%d %d", pt->width, *len);
	if (pt->width - *len <= 0)
		return ;
	printf_zs(' ', pt->width - *len);
	*len += pt->width - *len;
}

int	d_printf(t_point *pt, long long num)
{
	int	len;
// 출력할 자릿수, 띄어쓰기 또는 제로 padding, minus flag 체크
	if (pt->pre < 0 && !pt->pre_ast)
		pt->width = -pt->pre;
	len = num_len(&num, pt);
	if (pt->pre > len)
		pt->padding = pt->pre - len;//숫자 앞에 zero padding
	if (pt->sign == 1)
		len++;
	if (pt->zero && pt->width - len > pt->padding)
		pt->padding = pt->width - len;
	len += pt->padding;	
	if (pt->minus)
	{
		num_padding_operation(pt, num, &len);
		width_operation(pt, &len, num);//
	}
	else
	{
		width_operation(pt, &len, num);//
		num_padding_operation(pt, num, &len);
	}
	return (len);//수정
}

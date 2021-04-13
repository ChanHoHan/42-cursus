/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chan <chan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 14:31:26 by chan              #+#    #+#             */
/*   Updated: 2021/04/13 20:53:35 by chan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	num_len(long long *num, t_point *pt)
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
	if (pt->zero && *num == 0)
		return (1);
	if (pt->dot && *num == 0)
		return (0);
	if (*num == 0)
		return (1);
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
	if (pt->pre_ast && pt->pre < 0 && !num)
	{
		write(1, "0", 1);
		(*len)++;
		return ;
	}
	if (!num && pt->dot && !pt->pre)
		return ;
	if (num == 0 && pt->dot) // 주의
		return;
	putnbr_printf(num);
}

void	width_operation(t_point *pt, int *len)
{
	if (pt->width - *len <= 0)
		return ;
	printf_zs(' ', pt->width - *len);
	*len = pt->width;
}

int	d_printf(t_point *pt, long long num)
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
	if (pt->pre < 0 && !pt->pre_ast)
		pt->width = -pt->pre;
	len += pt->padding;
	if (pt->minus)
	{
		num_padding_operation(pt, num, &len);
		width_operation(pt, &len);
	}
	else
	{
		width_operation(pt, &len);
		num_padding_operation(pt, num, &len);
	}
	return (len);//수정
}

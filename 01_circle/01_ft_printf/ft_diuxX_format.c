/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_diuxX_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chan <chan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 15:42:41 by chan              #+#    #+#             */
/*   Updated: 2021/04/19 21:19:25 by chan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		num_len(long long *num, t_point *pt, int d_val)
{
	int	len;

	long long _num;
	len = 0;
	if (*num < 0)
	{
		pt->sign = 1;
		*num = -(*num);
	}
	_num = *num;
	if (!pt->pre_ast && pt->pre > 0)
		pt->zero = 0;
	if (*num == 0)
		return (1);
	while (_num)
	{
		_num = _num / d_val;
		len++;
	}
	return (len);
}

void	num_padding_operation(t_point *pt, long long num, int *len, const char *p_val)
{
	if (pt->sign)
		write(1, "-", 1);
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
	putnbr_printf(num, ft_strlen(p_val), p_val);
}

void	putnbr_printf(long long num, int d_val, const char *p_val)
{
	long long	quo;
	long long	rem;
	char		ch;

	quo = num / d_val;
	rem = num % d_val;
	if (num >= d_val)
		putnbr_printf(quo, d_val, p_val);
	ch = '0' + rem;
	write(1, &p_val[rem], 1);
}

void	width_operation(t_point *pt, int *len, long long num)
{
	if (!num && !pt->pre_ast && pt->dot && pt->pre <= 0)
	{
		printf_zs(' ', pt->width);
		if (pt->width > 0)
			*len += pt->width - *len;
		return ;
	}
	if (!pt->minus && !num && !pt->pre && pt->pre_ast)
		pt->width++;
	if (pt->width - *len <= 0)
		return ;
	printf_zs(' ', pt->width - *len);
	*len += pt->width - *len;
}

int		diuxX_printf(t_point *pt, long long num, int val, const char *p)
{
	int	len;

	if (pt->pre < 0 && !pt->pre_ast)
		pt->width = -pt->pre;
	len = num_len(&num, pt, val);
	if (pt->pre > len)
		pt->padding = pt->pre - len;
	if (pt->sign == 1)
		len++;
	if (pt->zero && pt->width - len > pt->padding)
		pt->padding = pt->width - len;
	len += pt->padding;
	if (pt->minus)
	{
		num_padding_operation(pt, num, &len, p);
		width_operation(pt, &len, num);
	}
	else
	{
		width_operation(pt, &len, num);
		num_padding_operation(pt, num, &len, p);
	}
	return (len);
}

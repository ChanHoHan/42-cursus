/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chan <chan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 21:44:10 by chan              #+#    #+#             */
/*   Updated: 2021/04/18 20:25:35 by chan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_type(char ch)
{
	return (ch == 'c' || ch == 's' || ch == 'p' || ch == 'd' ||
			ch == 'i' || ch == 'u' || ch == 'x' || ch == 'X' ||
			ch == '%');
}

void		t_point_init(t_point* pt)
{
	pt->minus = 0;
	pt->zero = 0;
	pt->width = 0;
	pt->dot = 0;
	pt->pre = 0;
	pt->sign = 0;
	pt->padding = 0;
	pt->pre_ast = 0;
	pt->space = 0;
}

void		printf_zs(char val, int width)
{
	int	i;

	i = -1;
	if (width <= 0)
		return ;
	while (++i < width)
		write(1, &val, 1);
}

int		compare_val(int a, int b, int fl)
{
	if (fl)
	{
		if (a > b)
			return (a);
		return (b);
	}
	if (a > b)
		return (b);
	return (a);
}

int		width_atoi(const char *s, int *i, t_point *pt)
{
	long long	ret;
	long long	tmp;
	int			of_cnt;

	ret = 0;
	of_cnt = 0;
	while (s[*i] == ' ')
	{
		pt->space++;
		(*i)++;
	}
	while (ft_isdigit(s[*i]))
	{
		tmp = ret * 10 + (s[*i] - '0');
		if ((((1 << 31) & tmp) ^ ((1 << 31) & ret)) == 0)
			of_cnt = 1;
		ret = tmp;
		(*i)++;
	}
	if (of_cnt && ret >= 2147483647)
		return (-1);
	if (of_cnt && ret < 0)
		return (0);
	return ((int)ret);
}

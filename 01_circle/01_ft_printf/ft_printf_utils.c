/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chan <chan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 21:44:10 by chan              #+#    #+#             */
/*   Updated: 2021/03/09 20:14:34 by chan             ###   ########.fr       */
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
}

int	ft_isdigit(int c)
{
	if (48 <= c && c <= 57)
		return (1);
	return (0);
}

int		width_atoi(const char *s, int *i)
{
	long long	ret;
	long long	tmp;
	int			of_cnt;

	ret = 0;
	of_cnt = 0;
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

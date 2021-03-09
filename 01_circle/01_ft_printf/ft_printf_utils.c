/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chan <chan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 21:44:10 by chan              #+#    #+#             */
/*   Updated: 2021/03/04 18:37:35 by chan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_type(char ch)
{
	return (ch == 'c' || ch == 's' || ch == 'p' || ch == 'd' ||
			ch == 'i' || ch == 'u' || ch == 'x' || ch == 'X' ||
			ch == '%')
}

int		width_atoi(const char *s)
{
	long long	ret;
	long long	tmp;
	int			of_cnt;

	ret = 0;
	of_cnt = 0;
	while (ft_isdigit(*s))
	{
		tmp = ret * 10 + (*s++ - '0');
		if ((((1 << 31) & tmp) ^ ((1 << 31) & ret)) == 0)
			of_cnt = 1;
		ret = tmp;
	}
	if (of_cnt && ret >= 2147483647)
		return (-1);
	if (of_cnt && ret < 0)
		return (0);
	return ((int)ret);
}

void		

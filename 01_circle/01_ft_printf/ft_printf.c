/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chan <chan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 18:56:41 by chan              #+#    #+#             */
/*   Updated: 2021/03/10 09:03:46 by chan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		make_format(char type, t_point *pt, va_list ap)
{
	if (type == 'c')
		c_printf(pt, va_arg(ap, int));
	/*
	else if (type == 'd')
		d_printf(pt, ap);*/
}
/*
static void		exception_check(const char *format, int *index)
{
	if (format[*index + 1] == '%')
	{

		// width만큼 스페이스 찍고 % 출력
	}

}*/

void		format_check(const char *format, int i, t_point *pt, va_list ap)
{
	int num;

	if (format[i] == '-')
		pt->minus = 1;
	else if (format[i] == '.')
		pt->dot = 1;
	else if (!(pt->dot) && format[i] == '*')
		pt->width = va_arg(ap, int);
	else if (pt->dot && format[i] == '*')
		pt->pre = va_arg(ap, int);
	else if (format[i] == '0')
		pt->zero = 1;
	else if ((num = width_atoi(format, &i)))// 수정
	{
		if (pt->dot)
			pt->pre = num;
		else
			pt->width = num;
	}
}

int		ft_printf_core(const char *format, va_list ap)
{
	int	i;
	int	rd_size;
	char	type;
	t_point	pt;

	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			t_point_init(&pt);
			while (format[i] && !is_type(format[i]))
			{// 널 일때만 i--
				format_check(format, i, &pt, ap);
				i++;
			}
		}
		// 수
		if (format[i] == '\0')
			i--;
		else
			make_format(format[i], &pt, ap);
		//exception_check()
		i++;
	}
	return (i);
}

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	int		plen;

	va_start(ap, format);
	plen = ft_printf_core(format, ap);
	va_end(ap);
	if (plen == -1)
		return (-1);
	return (plen);
}

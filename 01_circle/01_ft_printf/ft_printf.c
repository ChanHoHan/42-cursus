/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chan <chan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 18:56:41 by chan              #+#    #+#             */
/*   Updated: 2021/03/04 18:37:31 by chan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	make_format(const char *format, int *index)
{
	int	i;

	i = *index;
	while (is_type(format[i]) && format[i] && format[i] != '%')
	{
		
		i++;
	}
	*index = i;
}

static void		exception_check(const char *format, int *index)
{
	if (format[*index + 1] == '%')
	{

		// width만큼 스페이스 찍고 % 출력
	}

}

static void		format_check(const char *format, int i, t_point *pt)
{
	if (format[i] == '-')
		pt->minus = 1;

}

static int		ft_printf_core(const char *format, va_list ap)
{
	int	i;
	int	rd_size;
	t_point	pt;

	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			while (format[i] && !istype(format[i]))
			{// 널 일때만 i--
				format_check(format, i, &pt);
				i++;
			}
			
		}
		
		make_format(format, &i);
		//exception_check()
		i++;
	}

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

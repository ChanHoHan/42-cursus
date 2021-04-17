/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chan <chan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 18:56:41 by chan              #+#    #+#             */
/*   Updated: 2021/04/18 01:35:53 by chan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		make_format(char type, t_point *pt, va_list ap)
{
	if (pt->width < 0)
	{
		pt->minus = 1;
		pt->zero = 0;
		pt->width = -(pt->width);
	}
	if (pt->pre_ast && pt->pre >= 0)
		pt->zero = 0;
	if (type == '%')
		return(c_printf(pt, '%'));
	else if (type == 'c')
		return(c_printf(pt, va_arg(ap, int)));
	else if (type == 's')
		return(s_printf(pt, va_arg(ap, char *)));
	else if (type == 'p')
		return(p_printf(pt, va_arg(ap, unsigned long long)));
	else if (type == 'd' || type == 'i')
		return(d_printf(pt, va_arg(ap, int)));
	else if (type == 'u')
		return(u_printf(pt, va_arg(ap, unsigned int)));
	else if (type == 'X')
		return(X_printf(pt, va_arg(ap, unsigned int)));
	else if (type == 'x')
		return(x_printf(pt, va_arg(ap, unsigned int)));
	return (1);
}

void		format_check(const char *format, int *i, t_point *pt, va_list ap)
{
	if (format[*i] == '-')
		pt->minus = 1;
	else if (format[*i] == '.')
		pt->dot = 1;
	else if (!(pt->dot) && format[*i] == '*')
		pt->width = va_arg(ap, int);
	else if (pt->dot && format[*i] == '*')
	{
		pt->pre = va_arg(ap, int);
		pt->pre_ast = 1;
	}
	else if (format[*i - 1] == '%' && format[*i] == '0')
		pt->zero = 1;
	else if ((pt->tmp = width_atoi(format, i, pt)) >= 0)
	{
		if (pt->dot)
			pt->pre = pt->tmp;
		else
			pt->width = pt->tmp;
		(*i)--;
	}
	(*i)++;
}

void		print_format(int *rd_size, char ch)
{
	write(1, &ch, 1);
	++(*rd_size);
}

int		ft_printf_core(const char *format, va_list ap)
{
	int	i;
	int	rd_size;
	t_point	pt;

	i = -1;
	rd_size = 0;
	while (format[++i])
	{
		if (format[i] == '%')
		{
			i++;
			t_point_init(&pt);
			while (format[i] && !is_type(format[i]))// 널 일때만 i--
				format_check(format, &i, &pt, ap);
			if (pt.space)
				printf_zs(' ', pt.space);
			if (format[i] == '\0')
				i--;
			else
				rd_size += make_format(format[i], &pt, ap);
		}
		else
			print_format(&rd_size, format[i]);
	}
	return (rd_size + pt.space);
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

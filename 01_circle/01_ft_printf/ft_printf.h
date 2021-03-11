/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chan <chan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 21:44:25 by chan              #+#    #+#             */
/*   Updated: 2021/03/10 00:15:34 by chan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
#include <stdio.h>
typedef struct	s_point
{
	int	minus;
	int	zero;
	int	width;
	int	dot;
	int	pre;
}		t_point;
int		width_atoi(const char *s, int *i);
void		t_point_init(t_point* pt);
int		is_type(char ch);
int		ft_printf(const char *format, ...);
void		c_printf(t_point *pt, int ch);
void		make_format(char type, t_point *pt, va_list ap);
#endif

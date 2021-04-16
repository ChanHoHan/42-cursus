/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chan <chan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 21:44:25 by chan              #+#    #+#             */
/*   Updated: 2021/04/16 19:44:36 by chan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# define SMALL "0123456789abcdef"
# define LARGE "0123456789ABCDEF"
#include <stdio.h>
typedef struct	s_point
{
	int	minus;
	int	zero;
	int	width;
	int	dot;
	int	pre;
	int	padding;
	int	sign;
	int	pre_ast;
	int	tmp;
}		t_point;
int		width_atoi(const char *s, int *i);
void		t_point_init(t_point* pt);
void		printf_zs(char val, int width);
int		is_type(char ch);
int		ft_isdigit(int c);
int		ft_printf(const char *format, ...);
int		c_printf(t_point *pt, int ch);
int			p_printf(t_point *pt, unsigned long long p);
int			s_printf(t_point *pt, char *s);
int			d_printf(t_point *pt, long long num);
int			u_printf(t_point *pt, long long num); 
int			x_printf(t_point *pt, long long num); 
int			X_printf(t_point *pt, long long num); 
int		make_format(char type, t_point *pt, va_list ap);
int		ft_putnbr_fd(unsigned long long n);
int		compare_val(int a, int b, int fl);
size_t		ft_strlen(const char *s);
#endif

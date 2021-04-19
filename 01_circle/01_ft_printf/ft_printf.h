/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chan <chan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 21:44:25 by chan              #+#    #+#             */
/*   Updated: 2021/04/19 18:54:04 by chan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# define SMALL "0123456789abcdef"
# define LARGE "0123456789ABCDEF"
# define NUMBER "0123456789"
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
	int	space;
}		t_point;
int		width_atoi(const char *s, int *i, t_point *pt);
void		t_point_init(t_point* pt);
void		printf_zs(char val, int width);
void		putnbr_printf(long long num, int d_val, const char* p_val); 
void		num_padding_operation(t_point *pt, long long num, int *len, const char* p_val);
void		width_operation(t_point *pt, int *len, long long num);
int		is_type(char ch);
int		ft_isdigit(int c);
int		ft_printf(const char *format, ...);
int		c_printf(t_point *pt, int ch);
int			p_printf(t_point *pt, unsigned long long p);
int			s_printf(t_point *pt, char *s);
int			diuxX_printf(t_point *pt, long long num, int val, const char* p);
int			num_len(long long *num, t_point *pt, int d_val);
int		make_format(char type, t_point *pt, va_list ap);
int		ft_putnbr_fd(unsigned long long n);
int		compare_val(int a, int b, int fl);
size_t		ft_strlen(const char *s);
#endif

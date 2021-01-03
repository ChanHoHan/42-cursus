/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chan <chan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 22:17:02 by chan              #+#    #+#             */
/*   Updated: 2021/01/02 13:52:22 by chan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*g_b;
int		g_sign;

static int		is_quo_zero(int quo)
{
	if (!quo)
		return (1);
	else if (1 <= quo && quo <= 9)
		return (2);
	return (0);
}

static int		cal_len(int quo)
{
	int	size;

	size = 0;
	if (is_quo_zero(quo) == 1)
		size += 2;
	else if (is_quo_zero(quo) == 2)
		size += 3;
	if (g_sign == -1)
		size += 1;
	return (size);
}

static int		make_arr(int size, int depth, int quo, int rem)
{
	int	i;

	if (!(g_b = (char *)malloc(size + depth)))
		return (0);
	g_b[size + depth - 1] = '\0';
	i = 0;
	if (g_sign == -1)
		g_b[i++] = '-';
	if (is_quo_zero(quo) == 1)
		g_b[i++] = rem + 48;
	else
	{
		g_b[i++] = quo + 48;
		g_b[i++] = rem + 48;
	}
	return (i);
}

static int		a(int n, int depth)
{
	int	quo;
	int	rem;
	int	size;
	int	val;
	int	tmp;

	quo = n / 10;
	rem = n % 10;
	size = cal_len(quo);
	if (size >= 2)
	{
		tmp = make_arr(size, depth, quo, rem);
		if (!tmp)
			return (0);
		return (tmp);
	}
	if (!(val = a(quo, depth + 1)))
		return (0);
	g_b[val] = rem + 48;
	return (val + 1);
}

char	*ft_itoa(int n)
{
	g_sign = 1;
	if (n < 0)
	{
		g_sign = -g_sign;
		n = -n;
	}
	if (n == -2147483648)
		n = 2147483647;
	if (!a(n, 0))
		return (NULL);
	if (n == 2147483647 && g_sign == -1)
		g_b[10] += 1;
	return (g_b);
}

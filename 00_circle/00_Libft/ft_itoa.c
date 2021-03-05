/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chan <chan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 22:17:02 by chan              #+#    #+#             */
/*   Updated: 2021/01/05 13:24:13 by chan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_set_n(int n)
{
	n = n < 0 ? -n : n;
	n = n < 0 ? n - 1 : n;
	return (n);
}

static int	ft_intlen(int n, int sign)
{
	int	size;

	size = (sign == 0) ? 2 : 1;
	if (0 <= n && n <= 9)
		return (++size);
	while (n >= 1)
	{
		n /= 10;
		size++;
	}
	return (size);
}

char		*ft_itoa(int n)
{
	int		size;
	int		i;
	int		min;
	int		sign;
	char	*a;

	min = 1;
	min = (n == (min << 31)) ? 1 : 0;
	sign = n < 0 ? 0 : 1;
	n = ft_set_n(n);
	size = ft_intlen(n, sign);
	if (!(a = (char *)malloc(size)))
		return (NULL);
	if (!sign)
		a[0] = '-';
	a[0] = (n == 0) ? '0' : a[0];
	a[size - 1] = '\0';
	i = size - 2;
	while (n >= 1)
	{
		a[i--] = (n % 10 + '0');
		n /= 10;
	}
	a[size - 2] = min ? a[size - 2] + 1 : a[size - 2];
	return (a);
}

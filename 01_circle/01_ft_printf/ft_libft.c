/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chan <chan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 20:00:54 by chan              #+#    #+#             */
/*   Updated: 2021/03/11 20:11:51 by chan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

static void	print_val(int quo, int rem, int *len)
{
	if (quo >= 10)
		print_val(quo / 10, quo % 10, len);
	else if (1 <= quo && quo <= 9)
	{
		ft_putchar_fd(quo + '0', 1);
		(*len)++;
	}
	ft_putchar_fd(rem + '0', 1);
	(*len)++;
}

int		ft_putnbr_fd(unsigned long long n)
{
	int	quo;
	int	rem;
	int	len;

	len = 0;
	if (n < 0)
	{
		write(1, "-", 1);
		len++;
	}
	quo = n / 10;
	rem = n % 10;
	quo = quo < 0 ? -quo : quo;
	rem = rem < 0 ? -rem : rem;
	print_val(quo, rem, &len);
	return (len);
}

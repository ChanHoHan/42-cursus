/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chan <chan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 20:35:55 by chan              #+#    #+#             */
/*   Updated: 2021/01/05 10:39:40 by chan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	print_val(int *fd, int quo, int rem)
{
	if (quo >= 10)
		print_val(fd, quo / 10, quo % 10);
	else if (1 <= quo && quo <= 9)
		ft_putchar_fd(quo + '0', *fd);
	ft_putchar_fd(rem + '0', *fd);
}

void		ft_putnbr_fd(int n, int fd)
{
	int	quo;
	int	rem;

	if (n < 0)
		write(fd, "-", 1);
	quo = n / 10;
	rem = n % 10;
	quo = quo < 0 ? -quo : quo;
	rem = rem < 0 ? -rem : rem;
	print_val(&fd, quo, rem);
}

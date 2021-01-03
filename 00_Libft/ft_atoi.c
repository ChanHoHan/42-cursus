/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 13:05:39 by chhan             #+#    #+#             */
/*   Updated: 2021/01/02 18:14:16 by chan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(char *str)
{
	unsigned long long	save;
	unsigned long long	save_tmp;
	int					sign;
	size_t				i;

	save = 0;
	sign = 1;
	while ((9 <= *str && *str <= 13) || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			sign = -1;
	while (ft_isdigit(*str))
	{
		save_tmp = save;
		i = -1;
		while (++i < 9)
			if (save > (save_tmp += save))
				return (sign == -1 ? 0 : -1);
		if (save > (save_tmp += (*str++ - '0')))
			return (sign == -1 ? 0 : -1);
		save = save_tmp;
	}
	return (sign * (int)save);
}

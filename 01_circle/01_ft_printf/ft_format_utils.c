/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chan <chan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 15:42:41 by chan              #+#    #+#             */
/*   Updated: 2021/04/19 15:53:32 by chan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	num_len(long long *num, t_point *pt, int val)
{
	int		len;
	long long	_num;

	len = 0;
	if (*num < 0)
	{
		pt->sign = 1;
		*num = -(*num);
	}
	_num = *num;
	if (!pt->pre_ast && pt->pre > 0)
		pt->zero = 0;
	if (*num == 0)
		return (1);
	while (_num)
	{
		_num = _num / val;
		len++;
	}
	return (len);
}

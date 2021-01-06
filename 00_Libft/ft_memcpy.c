/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 17:09:26 by chhan             #+#    #+#             */
/*   Updated: 2021/01/06 16:44:01 by chan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t size)
{
	size_t	i;

	i = -1;
	if ((unsigned char *)dest != (unsigned char *)src && size)
		while (++i < size)
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
	return (dest);
}

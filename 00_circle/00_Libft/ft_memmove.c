/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 20:19:22 by chhan             #+#    #+#             */
/*   Updated: 2020/12/31 11:41:42 by chan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t size)
{
	size_t	i;

	i = -1;
	if (!size || dest == src)
		return (dest);
	if ((unsigned char *)dest > (unsigned char *)src)
		while (++i < size)
			((unsigned char *)dest)[size - i - 1] = \
				((unsigned char *)src)[size - i - 1];
	else
		while (++i < size)
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
	return (dest);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 17:09:26 by chhan             #+#    #+#             */
/*   Updated: 2020/12/30 15:26:38 by chan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t size)
{
	size_t	i;

	i = -1;
	if ((unsigned char *)dest != (unsigned char *)src)
		while (++i < size)
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
	return (dest);
}

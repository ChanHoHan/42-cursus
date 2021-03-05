/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 09:22:21 by chhan             #+#    #+#             */
/*   Updated: 2020/12/30 15:44:56 by chan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		i;

	i = -1;
	while (++i < n && (unsigned char)c != ((unsigned char *)s)[i])
		;
	if (i == n)
		return (NULL);
	return ((void *)(s + i));
}

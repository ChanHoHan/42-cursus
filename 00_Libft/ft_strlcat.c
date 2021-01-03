/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 17:13:22 by chhan             #+#    #+#             */
/*   Updated: 2020/12/31 10:09:11 by chan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	d_len;
	size_t	s_len;
	size_t	i;
	size_t	j;

	i = -1;
	j = -1;
	d_len = ft_strlen(dest);
	s_len = ft_strlen(src);
	if (d_len > n)
		return (s_len + n);
	while (dest[++i])
		;
	while (i + 1 < n && src[++j])
		dest[i++] = src[j];
	dest[i] = '\0';
	return (d_len + s_len);
}

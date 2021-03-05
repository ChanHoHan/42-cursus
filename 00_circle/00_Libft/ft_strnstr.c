/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 18:25:55 by chhan             #+#    #+#             */
/*   Updated: 2021/01/06 17:52:17 by chan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	s1_len;
	size_t	s2_len;

	i = -1;
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (s2_len == 0)
		return ((char *)s1);
	while (++i < n && s1_len >= s2_len + i)
	{
		if (*(s1 + i) == *s2 && n >= s2_len + i && \
				(ft_strncmp(s1 + i, s2, s2_len) == 0))
			return ((char *)(s1 + i));
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chan <chan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 15:31:54 by chan              #+#    #+#             */
/*   Updated: 2021/03/06 23:26:11 by chan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (!src)
		return (0);
	if (dstsize)
	{
		while (i < dstsize - 1 && src[i])
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	while (src[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*a;
	size_t	s1_len;

	s1_len = ft_strlen(s1);
	if (!(a = (char *)malloc(sizeof(char) * (s1_len + 1))))
		return (NULL);
	ft_strlcpy(a, s1, s1_len + 1);
	return (a);
}

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

int		ft_gnljoin(char **save, char *buff)
{
	size_t	s1_l;
	size_t	s2_l;
	char	*a;

	if (!(*save) || !(buff))
		return (0);
	s1_l = ft_strlen(*save);
	s2_l = ft_strlen(buff);
	if (!(a = (char *)malloc(s1_l + s2_l + 1)))
		return (0);
	ft_strlcpy(a, *save, s1_l + 1);
	ft_strlcat(a, buff, s1_l + s2_l + 1);
	free(*save);
	*save = a;
	return (1);
}

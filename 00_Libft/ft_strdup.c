/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chan <chan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 11:47:54 by chan              #+#    #+#             */
/*   Updated: 2020/12/31 12:07:02 by chan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*a;
	size_t	s1_len;
	size_t	i;

	i = -1;
	s1_len = ft_strlen(s1);
	if (!(a = (char *)malloc(sizeof(char) * (s1_len + 1))))
		return (NULL);
	while (++i < s1_len)
		a[i] = s1[i];
	a[i] = '\0';
	return (a);
}

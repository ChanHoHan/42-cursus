/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chan <chan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 11:47:54 by chan              #+#    #+#             */
/*   Updated: 2021/01/06 18:03:48 by chan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

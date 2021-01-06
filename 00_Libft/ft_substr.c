/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chan <chan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 12:06:41 by chan              #+#    #+#             */
/*   Updated: 2021/01/06 17:13:14 by chan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*a;

	if (!s || !(a = (char *)malloc(len + 1)))
		return (NULL);
	if ((size_t)start >= ft_strlen(s) || !ft_strlcpy(a, s + start, len + 1))
		a[0] = '\0';
	return (a);
}

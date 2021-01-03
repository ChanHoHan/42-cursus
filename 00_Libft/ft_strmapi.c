/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chan <chan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 23:53:18 by chan              #+#    #+#             */
/*   Updated: 2021/01/02 11:40:20 by chan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	s_len;
	char	*a;

	if (!s || !f)
		return (NULL);
	i = -1;
	s_len = ft_strlen((const char *)s);
	if (!(a = (char *)malloc(s_len + 1)))
		return (NULL);
	a[s_len] = '\0';
	while(s[++i])
		a[i] = f(i, s[i]);
	return (a);
}

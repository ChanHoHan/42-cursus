/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chan <chan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 17:27:55 by chan              #+#    #+#             */
/*   Updated: 2021/01/05 10:40:13 by chan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_l;
	size_t	s2_l;
	char	*a;

	if (!s1 || !s2)
		return (NULL);
	s1_l = ft_strlen(s1);
	s2_l = ft_strlen(s2);
	if (!(a = (char*)malloc(s1_l + s2_l + 1)))
		return (NULL);
	ft_strlcpy(a, s1, s1_l + 1);
	ft_strlcpy(a + s1_l, s2, s2_l + 1);
	return (a);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chan <chan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 18:20:18 by chan              #+#    #+#             */
/*   Updated: 2021/01/02 15:28:30 by chan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	end;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	while (s1[i] && ft_strchr(set, (int)s1[i]))
		i++;
	j = i + 1;
	end = j;
	if (s1[i])
		while (s1[j])
		{
			if (!ft_strchr(set, (int)s1[j]))
				end = j;
			j++;
		}
	return (ft_substr(s1, (unsigned int)i, end - i + 1));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chan <chan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 14:53:51 by chan              #+#    #+#             */
/*   Updated: 2021/01/06 13:29:44 by chan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_array(char **b, size_t len)
{
	size_t	i;

	i = -1;
	if (len <= 0)
		return ;
	while (++i < len)
		free(b[i]);
	free(b);
}

static char	**make_array(char const *s, char c, size_t s_len)
{
	size_t	s_n_words;
	size_t	begin;
	size_t	end;
	char	**a;

	begin = -1;
	s_n_words = 0;
	while (++begin < s_len)
	{
		end = begin;
		while (s[end] && s[end] != c)
			end++;
		if (end == begin)
			continue ;
		s_n_words++;
		begin = end;
	}
	if (!(a = (char **)malloc(sizeof(char *) * (s_n_words + 1))))
		return (NULL);
	a[s_n_words] = NULL;
	return (a);
}

static char	**input_value(char **b, char const *s, char c, size_t s_len)
{
	size_t	i;
	size_t	begin;
	size_t	end;

	begin = -1;
	i = -1;
	while (++begin < s_len)
	{
		end = begin;
		while (s[end] && s[end] != c)
			end++;
		if (end == begin)
			continue ;
		if (!(b[++i] = (char *)malloc(end - begin + 1)))
		{
			if (i != 0)
				free_array(b, i);
			return (NULL);
		}
		ft_strlcpy(b[i], s + begin, end - begin + 1);
		begin = end;
	}
	return (b);
}

char		**ft_split(char const *s, char c)
{
	char	**b;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (!(b = make_array(s, c, s_len)))
		return (NULL);
	if (!(b = input_value(b, s, c, s_len)))
		return (NULL);
	return (b);
}

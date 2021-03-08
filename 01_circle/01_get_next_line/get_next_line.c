/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chan <chan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 15:31:22 by chan              #+#    #+#             */
/*   Updated: 2021/03/08 09:57:01 by chan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	nl_split(int *ind, char **save, char **line)
{
	char	*r;
	int		i;

	i = 1;
	(*save)[*ind] = '\0';
	if (!(*line = ft_strdup(*save)))
		return (0);
	r = NULL;
	if ((*save)[*ind + i])
		if (!(r = ft_strdup(*save + *ind + i)))
			return (0);
	free(*save);
	*save = r;
	*ind = 0;
	return (1);
}

int	nl_operation(int *ind, char **save, char **line)
{
	if (!(*save))
		return (1);
	while ((*save)[*ind] && (*save)[*ind] != '\n')
		(*ind)++;
	if ((*save)[*ind] != '\n')
		return (1);
	if (!nl_split(ind, save, line))
		return (-1);
	return (0);
}

int	exception_check(char **save, int num_line, char **line, int *check)
{
	int	i;

	i = 0;
	if (num_line == -1 || *check == -1)
		return (ERROR);
	if (num_line > 0)
		return (LINE_R);
	if (!(*save) && !num_line)
	{
		if (!(*line = ft_strdup("")))
			return (ERROR);
		return (_EOF);
	}
	if (*check)
		if (!(*line = ft_strdup(*save)))
			return (ERROR);
	free(*save);
	*save = NULL;
	return (_EOF);
}

int	buff_operation(char **save, char *buff)
{
	if (*save)
	{
		if (!(ft_gnljoin(save, buff)))
			return (0);
	}
	else
	{
		if (!(*save = ft_strdup(buff)))
			return (0);
	}
	return (1);
}

int	get_next_line(int fd, char **line)
{
	static char	*save[OPEN_MAX];
	char		*buff;
	ssize_t		num_line;
	int			i;
	int			check;

	i = 0;
	num_line = 1;
	if (fd < 0 || fd >= OPEN_MAX || !line || BUFFER_SIZE <= 0 ||
		!(buff = (char *)malloc(BUFFER_SIZE + 1)))
		return (ERROR);
	while ((check = nl_operation(&i, &save[fd], line)) == 1 &&
			(num_line = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[num_line] = '\0';
		if (!(buff_operation(&save[fd], buff)))
			return (ERROR);
	}
	free(buff);
	buff = NULL;
	return (exception_check(&save[fd], num_line, line, &check));
}

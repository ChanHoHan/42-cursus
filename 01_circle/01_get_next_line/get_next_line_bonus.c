/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chan <chan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 15:31:22 by chan              #+#    #+#             */
/*   Updated: 2021/02/28 21:26:07 by chan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	nl_split(int *ind, char **arr, char **line)
{
	char	*r;
	int		i;

	i = 1;
	(*arr)[*ind] = '\0';
	if (!(*line = ft_strdup(*arr)))
		return ;
	r = NULL;
	if ((*arr)[*ind + i])
		r = ft_strdup(*arr + *ind + i);
	free(*arr);
	*arr = r;
	*ind = 0;
}

void	ft_gnljoin(char **save, char *buff)
{
	char	*tmp;

	if (!(tmp = ft_strjoin(*save, buff)))
		return ;
	if (*save && tmp)
	{
		free(*save);
		*save = NULL;
		*save = tmp;
	}
}

int		nl_operation(int *ind, char **arr, char **line)
{
	if (!(*arr))
		return (1);
	while ((*arr)[*ind] && (*arr)[*ind] != '\n')
		(*ind)++;
	if ((*arr)[*ind] == '\n')
	{
		nl_split(ind, arr, line);
		return (0);
	}
	return (1);
}

int		exception_check(char **save, int num_line, char **line)
{
	int	i;

	i = 0;
	if (num_line == -1)
		return (ERROR);
	if (num_line > 0)
		return (LINE_R);
	if (*save == NULL && !num_line)
	{
		*line = (char *)malloc(sizeof(char));
		*line[0] = '\0';
		return (_EOF);
	}
	while ((*save)[i] && (*save)[i] != '\n')
		i++;
	if (!(*save)[i])
	{
		*line = ft_strdup(*save);
		free(*save);
		*save = NULL;
		return (_EOF);
	}
	if (!nl_operation(&i, save, line))
		return (LINE_R);
	return (_EOF);
}

int		get_next_line(int fd, char **line)
{
	static char	*save[OPEN_MAX + 1];
	char		*buff;
	ssize_t		num_line;
	int			i;

	i = 0;
	num_line = 1;
	if (fd < 0 || fd > OPEN_MAX || !line || BUFFER_SIZE <= 0 ||\
		!(buff = (char *)malloc(BUFFER_SIZE + 1)))
		return (ERROR);
	while (nl_operation(&i, &save[fd], line) && \
			(num_line = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[num_line] = '\0';
		if (save[fd])
			ft_gnljoin(&save[fd], buff);
		else
			save[fd] = ft_strdup(buff);
	}
	free(buff);
	buff = NULL;
	return (num_line > 0 ? LINE_R : exception_check(&save[fd], num_line, line));
}

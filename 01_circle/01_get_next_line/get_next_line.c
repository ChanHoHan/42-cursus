/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chan <chan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 15:31:22 by chan              #+#    #+#             */
/*   Updated: 2021/03/05 21:13:50 by chan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	nl_split(int *ind, char **save, char **line)
{
	char	*r;
	int		i;

	i = 1;
	(*save)[*ind] = '\0';
	if (!(*line = ft_strdup(*save)))
		return ;
	r = NULL;
	if ((*save)[*ind + i])
		r = ft_strdup(*save + *ind + i);
	free(*save);
	*save = r;
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

int		nl_operation(int *ind, char **save, char **line)
{
	if (!(*save))
		return (1);
	while ((*save)[*ind] && (*save)[*ind] != '\n')
		(*ind)++;
	if ((*save)[*ind] != '\n')
		return (1);
	nl_split(ind, save, line);
	return (0);
}

int		exception_check(char **save, int num_line, char **line)
{
	int	i;

	i = 0;
	if (num_line == -1)
		return (ERROR);
	if (num_line > 0)
		return (LINE_R);
	if (!(*save) && !num_line)
	{
		*line = ft_strdup("");
		return (_EOF);
	}
	while ((*save)[i] && (*save)[i] != '\n')
		i++;
	if (!(*save)[i])
		*line = ft_strdup(*save);
	else if (!nl_operation(&i, save, line))
		return (LINE_R);
	free(*save);
	*save = NULL;
	return (_EOF);
}

int		get_next_line(int fd, char **line)
{
	static char	*save[OPEN_MAX];
	char		*buff;
	ssize_t		num_line;
	int			i;

	i = 0;
	num_line = 1;
	if (fd < 0 || fd >= OPEN_MAX || !line || BUFFER_SIZE <= 0 ||
		!(buff = (char *)malloc(BUFFER_SIZE + 1)))
		return (ERROR);
	while (nl_operation(&i, &save[fd], line) &&
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
	return (exception_check(&save[fd], num_line, line));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chan <chan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 15:32:06 by chan              #+#    #+#             */
/*   Updated: 2021/03/06 23:45:06 by chan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

# define ERROR -1
# define _EOF 0
# define LINE_R 1

# ifndef OPEN_MAX
#  define OPEN_MAX 4096
# endif

char	*ft_strdup(const char *s1);
int		get_next_line(int fd, char **line);
int		nl_split(int *ind, char **arr, char **line);
int		nl_operation(int *ind, char **arr, char **line);
int		ft_gnljoin(char **save, char *buff);
int		buff_operation(char **save, char *buff);
int		exception_check(char **save, int num_line, char **line, int *error);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dest, const char *src, size_t n);

#endif

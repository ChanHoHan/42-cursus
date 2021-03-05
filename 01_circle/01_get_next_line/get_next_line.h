/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chan <chan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 15:32:06 by chan              #+#    #+#             */
/*   Updated: 2021/03/05 21:34:33 by chan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# define ERROR -1
# define _EOF 0
# define LINE_R 1

# ifndef OPEN_MAX
#  define OPEN_MAX 4096
# endif

char	*ft_strdup(const char *s1);
char	*ft_strjoin(char *s1, char const *s2);
int		get_next_line(int fd, char **line);
void	nl_split(int *ind, char **arr, char **line);
int		nl_operation(int *ind, char **arr, char **line);
void	ft_gnljoin(char **save, char *buff);
int		exception_check(char **save, int num_line, char **line);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dest, const char *src, size_t n);

#endif

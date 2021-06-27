/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnorma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 23:05:15 by cnorma            #+#    #+#             */
/*   Updated: 2021/06/24 22:24:17 by cnorma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BUF_SIZE
#  define BUF_SIZE BUFFER_SIZE
# endif

char	*check_rem(char **rem, char **line);
char	*ft_strchr(char *s, int c);
size_t	ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_stremp(size_t n);
char	*ft_strdup(char *s1);
int		get_next_line(int fd, char **line);
char	*ft_strcpy(char *dest, char *src);

#endif

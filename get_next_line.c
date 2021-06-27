/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnorma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 23:11:15 by cnorma            #+#    #+#             */
/*   Updated: 2021/06/25 00:15:06 by cnorma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
			return (s);
		s++;
	}
	if ((char)c == '\0')
		return (s);
	return (NULL);
}

char	*check_rem(char **rem, char **line)
{
	char	*p_n;

	p_n = NULL;
	if (!(*rem))
		*rem = ft_stremp(0);
	p_n = ft_strchr(*rem, '\n');
	if (p_n)
	{
		*p_n = '\0';
		*line = ft_strdup(*rem);
		*rem = ft_strcpy(*rem, (p_n + 1));
	}
	else
	{
		*line = ft_strdup(*rem);
		free(*rem);
		*rem = NULL;
	}
	return (p_n);
}

int	get_next_line(int fd, char **line)
{
	char		buf[BUF_SIZE + 1];
	char		*p_n;
	ssize_t		read_size;
	static char	*rem[256];

	if (fd < 0 || !line || BUF_SIZE <= 0 || read(fd, buf, 0) == -1 || fd > 256)
		return (-1);
	p_n = check_rem(&rem[fd], line);
	while (!p_n)
	{
		read_size = read(fd, buf, BUFFER_SIZE);
		if (!(read_size))
			return (0);
		buf[read_size] = '\0';
		p_n = ft_strchr(buf, '\n');
		if (p_n)
		{
			*p_n = '\0';
			rem[fd] = ft_strcpy(rem[fd], (p_n + 1));
		}
		*line = ft_strjoin(*line, buf);
	}
	if ((read(fd, buf, 0) >= 0 || (ft_strlen(*line))) && (p_n))
		return (1);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnorma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 23:51:47 by cnorma            #+#    #+#             */
/*   Updated: 2021/06/25 00:14:58 by cnorma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ss;
	size_t	i;
	size_t	len;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	ss = (char *)malloc(len * sizeof(char) + 1);
	if (ss == NULL)
		return (NULL);
	while (s1[i])
	{
		ss[i] = s1[i];
		i++;
	}
	free(s1);
	s1 = NULL;
	while (*s2)
	{
		ss[i++] = *s2;
		s2++;
	}
	ss[i] = '\0';
	return (ss);
}

char	*ft_stremp(size_t n)
{
	char	*str;

	str = (char *)malloc((n + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (n > 0)
	{
		*str++ = '\0';
		n--;
	}
	*str = '\0';
	return (str);
}

char	*ft_strdup(char *s1)
{
	int		i;
	char	*dest;

	dest = (char *)malloc(ft_strlen(s1) * sizeof(char) + 1);
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strcpy(char *dest, char *src)
{
	int		i;
	char	*result;

	result = (char *)malloc(ft_strlen(src) * sizeof(char) + 1);
	if (result == NULL)
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		result[i] = src[i];
		i++;
	}
	result[i] = '\0';
	if (dest)
	{
		free(dest);
		dest = NULL;
	}
	return (result);
}

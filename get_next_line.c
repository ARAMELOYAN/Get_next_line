/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeloyan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 19:08:17 by aeloyan           #+#    #+#             */
/*   Updated: 2022/06/19 19:10:00 by aeloyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h> 

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	size_t	i;

	i = my_strlen(s1);
	ptr = (char *)malloc(i * sizeof(char) + 1);
	if (!ptr)
		return (0);
	i = my_strlcpy(ptr, s1, i + 1);
	return (ptr);
}

static char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;

	if (!s)
		return (0);
	if (start >= (unsigned int)my_strlen(s))
		return (0);
	if (len > my_strlen(s) - start)
		len = my_strlen(s) - start;
	ptr = (char *)malloc(len * sizeof(char) + 1);
	if (!ptr)
		return (0);
	ptr = ft_strncpy(ptr, s + start, len);
	return (ptr);
}

char	*get_next_line(int fd)
{
	static char	*line = NULL;
	char		bufer[BUFFER_SIZE + 1];
	int			i;

	if (my_strchr(line, '\n'))
		return (my_strcut(&line));
	while (!my_strchr(line, '\n'))
	{
		i = read(fd, bufer, BUFFER_SIZE);
		if (i < 0)
			return (0);
		if (i == 0)
			return (my_strcut(&line));
		bufer[i] = '\0';
		line = my_strjoin(line, bufer);
	}
	return (my_strcut(&line));
}

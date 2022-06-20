/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeloyan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 15:33:06 by aeloyan           #+#    #+#             */
/*   Updated: 2022/06/20 17:30:13 by aeloyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h> 

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;

	if (!s)
		return (0);
	if (start >= (unsigned int)my_strlen(s))
		return (0);
	ptr = (char *)malloc(len * sizeof(char) + 1);
	if (!ptr)
		return (0);
	my_strlcpy(ptr, s + start, len + 1);
	return (ptr);
}

char	*get_next_line(int fd)
{
	static char	*line[OPEN_MAX];
	char		bufer[BUFFER_SIZE + 1];
	int			i;

	if (fd >= OPEN_MAX || BUFFER_SIZE < 1)
		return (0);
	if (my_strchr(line[fd], '\n'))
		return (my_strcut(&line[fd]));
	while (!my_strchr(line[fd], '\n'))
	{
		i = read(fd, bufer, BUFFER_SIZE);
		if (i < 0)
			return (0);
		if (i == 0)
			return (my_strcut(&line[fd]));
		bufer[i] = '\0';
		line[fd] = my_strjoin(line[fd], bufer);
	}
	return (my_strcut(&line[fd]));
}

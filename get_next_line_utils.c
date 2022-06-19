/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeloyan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 18:39:59 by aeloyan           #+#    #+#             */
/*   Updated: 2022/06/19 19:09:55 by aeloyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*my_strcut(char **str)
{
	char	*ptr;
	char	*transmit;
	char	*temp;

	if (!*str || !**str)
		return (0);
	ptr = my_strchr(*str, '\n');
	if (!ptr)
	{
		temp = ft_strdup(*str);
		free(*str);
		*str = NULL;
		return (temp);
	}
	transmit = ft_substr(*str, 0, ptr - (*str) + 1);
	temp = ft_substr(ptr, 0 + sizeof(char), my_strlen(ptr) - 1);
	free(*str);
	*str = temp;
	return (transmit);
}

char	*my_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)(s + i));
	return (0);
}

size_t	my_strlen(const char *str)
{
	size_t	k;

	k = 0;
	if (!str)
		return (0);
	while (str[k++] != '\0')
		;
	return (--k);
}

size_t	my_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize == 0)
		return (my_strlen(src));
	while (i < dstsize - 1 && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	if (src)
		while (src[i] != '\0')
			i++;
	return (i);
}

char	*my_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	size_t	i;
	size_t	j;

	i = my_strlen(s1);
	j = my_strlen(s2);
	ptr = (char *)malloc(sizeof(char) * (i + j + 1));
	if (!ptr)
		return (0);
	my_strlcpy(ptr, s1, i + 1);
	if (s1)
		free((void *)s1);
	my_strlcpy(ptr + i, s2, j + 1);
	return (ptr);
}

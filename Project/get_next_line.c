/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnasse <abdnasse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:50:09 by abdnasse          #+#    #+#             */
/*   Updated: 2024/11/23 13:07:14 by abdnasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	static char *cache;
	char	*buffer;
	ssize_t	bytes;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	if (!cache && ((cache = f_malloc(BUFFER_SIZE + 1)) == NULL))
		return (NULL);
	while (!f_newline(cache))
	{
		if ((buffer = f_malloc(BUFFER_SIZE + 1)) == NULL)
		{
			free(cache);
			return (cache = NULL);
		}
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (f_buffer_to_cache(buffer, &cache, bytes) == 1)
			break ;
		if (bytes < 0)
			return (NULL);
	}
	buffer = f_set_line(&cache);
	return (buffer);
}

char	*f_set_line(char **cache)
{
	char	*line;
	char	*next_cache;
	size_t	index;

	index = f_newline(*cache);
	if (index > 0)
	{
		next_cache = ft_strdup(*cache + index);
		if (!next_cache)
		{
			free(*cache);
			return (*cache = NULL);
		}
		line = f_realloc(*cache, index);
		if (!line)
			return (NULL);
		*cache = next_cache;
		return (line);
	}
	if (**cache)
	{
		line = ft_strdup(*cache);
		free(*cache);
		*cache = NULL;
		return (line);
	}
	free(*cache);
	return (*cache = NULL);
}

int	f_buffer_to_cache(char *buffer,char **cache, ssize_t bytes)
{
	if (bytes  > 0)
	{
		buffer[bytes] = '\0';
		*cache = f_realloc(*cache, ft_strlen(*cache) + bytes);
		if (!(*cache))
		{
			free(*cache);
			*cache = NULL;
			return (0);
		}
		ft_strcat(*cache, buffer);
		free(buffer);
		if (f_newline(*cache))
			return (1);
		return (-1);
	}
	free(buffer);
	if (bytes == 0)
		return (1);
	free(*cache);
	*cache = NULL;
	return (0);
}

char	*ft_strdup(const char *s)
{
	char	*p;
	size_t	len;

	len = ft_strlen(s);
	p = (char *)malloc((len + 1) * sizeof(char));
	if (!p)
		return (0);
	*(p + len) = 0;
	while (len--)
		*(p + len) = *(s + len);
	return (p);
}

char	*f_malloc(size_t size)
{
	char	*p;

	p = (char *)malloc(size);
	if (!p)
		return (NULL);
	ft_bzero(p, size);
	return (p);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnasse <abdnasse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:50:09 by abdnasse          #+#    #+#             */
/*   Updated: 2024/11/22 00:06:22 by abdnasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

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

char	*f_set_line(char **cache)
{
	size_t	index;
	char	*buffer;
	char	*up;

	index = f_newline(*cache);
	if (index > 0)
	{
		up = ft_strdup(*cache + index);
		if (!up)
		{
			free(*cache);
			return (*cache = NULL);
		}
		buffer = f_realloc(*cache, index);
		if(!buffer)
		{
			free(up);
			return (NULL);
		}
		*cache = up;
	}
	else 
	{
		buffer = *cache;
		*cache = NULL;
	}
	return (buffer);
}

int	f_line2buffer(char *buffer, char **cache, ssize_t bytes)
{
	if (bytes > 0)
	{
		buffer[bytes] = 0;
		*cache = f_realloc(*cache, ft_strlen(*cache) + bytes);
		if (!*cache)
		{
			free(buffer);
			return (0);
		}
		ft_strcat(*cache, buffer);
		if (!f_newline(buffer))
		{
			free(buffer);
			return (-1);
		}
		free(buffer);
		return (1);
	}
	free(buffer);
	if (bytes == 0)
		return (0);
	free(*cache);
	*cache = NULL;
	return (0);
}

char	*get_next_line(int fd)
{
	static char *cache;
	char	*buffer;
	ssize_t	bytes;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	if (!cache)
	{
		cache = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!cache)
			return (NULL);
		ft_bzero(cache, BUFFER_SIZE + 1);
	}
	while (!f_newline(cache))
	{
		buffer = (char *)malloc(BUFFER_SIZE + 1);
		ft_bzero(buffer, BUFFER_SIZE + 1);
		if (!buffer)
			return (NULL);
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (f_line2buffer(buffer, &cache, bytes) == 1) 
			break ;
		if (bytes == 0 || !cache)
			break ;
	}
	buffer = f_set_line(&cache);
	if(buffer && buffer[0] == 0)
	{
		free(buffer);
		return NULL;
	}
	return (buffer);
}

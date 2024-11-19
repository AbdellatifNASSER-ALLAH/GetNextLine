/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnasse <abdnasse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:50:09 by abdnasse          #+#    #+#             */
/*   Updated: 2024/11/19 20:53:05 by abdnasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <stdio.h>
#include <string.h>

char	*_set_line(char **buffer)
{
	size_t	newline;
	char	*line;
	char	*cache;

	newline = _newline(*buffer);
	if (newline > 0)
	{
		cache = strdup(*buffer + newline);
		line = _realloc(*buffer, newline);
		if(!line)
			return (NULL);
		*buffer = cache;
	}
	else 
	{
		line = _realloc(*buffer, ft_strlen(*buffer));
		if (!line)
			return (NULL);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char *buffer;
	char	*line;
	ssize_t	bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer)
	{
		buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!buffer)
			return (NULL);
		ft_bzero(buffer, BUFFER_SIZE + 1);
	}
	while (!_newline(buffer))
	{
		line = (char *)malloc(BUFFER_SIZE + 1);
		if (!line)
			return (NULL);
		bytes = read(fd, line, BUFFER_SIZE);
		if (bytes < 0)
		{
			free(buffer);
			return (NULL);
		}
		line[bytes] = '\0';
		buffer = _realloc(buffer, ft_strlen(buffer) + bytes);
		if (!buffer)
		{
			free(line);
			return (NULL);
		}
		strcat(buffer, line);
		free(line);
		if (bytes == 0 && !buffer[0])
		{
			free(buffer);
			return (NULL);
		}
		if (bytes == 0)
			break ;
	}
	line = _set_line(&buffer);
	return (line);
}

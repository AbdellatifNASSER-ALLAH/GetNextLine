/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnasse <abdnasse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:50:09 by abdnasse          #+#    #+#             */
/*   Updated: 2024/11/19 19:48:37 by abdnasse         ###   ########.fr       */
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

	newline = ft_newline(*buffer);
	if (newline > 0)
	{
		cache = strdup(*buffer + newline);
		line = ft_realloc(*buffer, newline);
		if(!line)
			return (NULL);
		*buffer = cache;
	}
	else 
	{
		line = ft_realloc(*buffer, ft_strlen(*buffer));
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
	while (!ft_newline(buffer))
	{
		line = (char *)malloc(BUFFER_SIZE + 1);
		if (!line)
			return (NULL);
		bytes = read(fd, line, BUFFER_SIZE);
		if (bytes == 0)
			break ;
		if (bytes < 0)
		{
			free(buffer);
			return (NULL);
		}
		line[bytes] = '\0';
		buffer = ft_realloc(buffer, ft_strlen(buffer) + bytes);
		if (!buffer)
		{
			free(line);
			return (NULL);
		}
		strcat(buffer, line);
		free(line);
	}
	line = _set_line(&buffer);
	return (line);
}

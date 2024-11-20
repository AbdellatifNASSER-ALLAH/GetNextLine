/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnasse <abdnasse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:50:09 by abdnasse          #+#    #+#             */
/*   Updated: 2024/11/20 13:56:22 by abdnasse         ###   ########.fr       */
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

char	*_set_line(char **buffer)
{
	size_t	index;
	char	*line;
	char	*cache;

	index = _newline(*buffer);
	if (index > 0)
	{
		cache = ft_strdup(*buffer + index);
		line = _realloc(*buffer, index);
		if(!line)
			return (NULL);
		*buffer = cache;
	}
	else 
	{
		line = _realloc(*buffer, ft_strlen(*buffer));
		if (!line)
			return (NULL);
		*buffer = NULL;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char *buffer;
	char	*line;
	ssize_t	bytes;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
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
		ft_strcat(buffer, line);
		free(line);
		if (bytes == 0)
			break ;
	}
	line = _set_line(&buffer);
	return (line);
}

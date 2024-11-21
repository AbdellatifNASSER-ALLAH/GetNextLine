/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnasse <abdnasse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:50:09 by abdnasse          #+#    #+#             */
/*   Updated: 2024/11/21 21:13:23 by abdnasse         ###   ########.fr       */
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

char	*f_set_line(char **buffer)
{
	size_t	index;
	char	*line;
	char	*cache;

	index = f_newline(*buffer);
	if (index > 0)
	{
		cache = ft_strdup(*buffer + index);
		line = f_realloc(*buffer, index);
		if(!line)
			return (NULL);
		*buffer = cache;
	}
	else 
	{
		line = *buffer;
		*buffer = NULL;
	}
	return (line);
}

int	f_line2buffer(char *line, char **buffer, ssize_t bytes)
{
	if (bytes > 0)
	{
		line[bytes] = 0;
		*buffer = f_realloc(*buffer, ft_strlen(*buffer) + bytes);
		if (!*buffer)
		{
			free(line);
			return (0);
		}
		ft_strcat(*buffer, line);
		if (!f_newline(line))
		{
			free(line);
			return (-1);
		}
		free(line);
		return (1);
	}
	free(line);
	if (bytes == 0)
		return (0);
	free(*buffer);
	*buffer = NULL;
	return (0);
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
	while (!f_newline(buffer))
	{
		line = (char *)malloc(BUFFER_SIZE + 1);
		if (!line)
			return (NULL);
		bytes = read(fd, line, BUFFER_SIZE);
		if (f_line2buffer(line, &buffer, bytes) == 1)
			break ;
		else if (bytes == 0)
			break ;
	}
	line = f_set_line(&buffer);
	if(line && line[0] == 0)
	{
		free(line);
		return NULL;
	}
	return (line);
}

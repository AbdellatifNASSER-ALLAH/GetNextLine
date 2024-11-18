/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnasse <abdnasse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:50:09 by abdnasse          #+#    #+#             */
/*   Updated: 2024/11/18 22:53:37 by abdnasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <stdio.h>
#include <string.h>

char	*get_next_line(int fd)
{
	static char	*buffer;
	char	*line;
	ssize_t	bytes;
	ssize_t	i;

	if (!buffer)
	{
		buffer = (char *)malloc((BUFFER_SIZE) * sizeof(char));
		ft_bzero(buffer, BUFFER_SIZE);
	}
	if (!buffer)
		return (NULL);
	line = buffer;
	i = ft_strlen(buffer);
	while(1)
	{
		if (*buffer && ft_newline(buffer))
		{
			buffer = strdup(buffer + ft_newline(buffer));
			line = ft_realloc(line, ft_newline(line));
			if (!line)
				return (NULL);
			
			break;
		}
		line = ft_realloc(line, i + BUFFER_SIZE);
		bytes = read(fd, line + i, BUFFER_SIZE);
		if(bytes < 0)
			return (NULL);
		if (bytes == 0) 
		{
			line = ft_realloc(line, ft_strlen(line));
			if (!line)
				return (NULL);
			break;
		}
		if (ft_newline(line))
		{
			buffer = strdup(line + ft_newline(line));
			line = ft_realloc(line, ft_newline(line));
			if (!line)
				return (NULL);
			
			break;
		}
		else
		{
			i += BUFFER_SIZE;
			line = ft_realloc(line, i + BUFFER_SIZE);
			if (!line)
				return (NULL);
		}

	}
	return (line);
}

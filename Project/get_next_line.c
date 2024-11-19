/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnasse <abdnasse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:50:09 by abdnasse          #+#    #+#             */
/*   Updated: 2024/11/19 13:02:51 by abdnasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <stdio.h>
#include <string.h>

/*ssize_t	ft_read(int fd, char *line)
  {
  if (*line)
  bytes = read(fd, line + ft_strlen(line), BUFFER_SIZE);
  else 
  bytes = 
  }*/

int	ft_check_buffer(char **buffer, char **line)
{
	if (ft_newline(*buffer))
	{
		*buffer = strdup(*line + ft_newline(*line));
		*line = ft_realloc(*line, ft_newline(*line));
		if(!(*line))
			return (0);
		return (1);
	}
	if (**buffer)
		return (1);
	return (0);
}

int	ft_endline(char **line)
{
	*line = ft_realloc(*line, ft_strlen(*line));
	if (!(*line))
		return(0);
	return (1);
}

char	*get_next_line(int fd)
{
	static char *buffer;
	char	*line;
	ssize_t	bytes;
	size_t	i;

	if (!buffer)
	{
		buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!buffer)
			return (NULL);
		ft_bzero(buffer, BUFFER_SIZE + 1);
	}
	line = buffer;
	i = ft_strlen(buffer);
	while (1)
	{
		if (ft_check_buffer(&buffer, &line))
			break ;
		bytes = read(fd, line + i, BUFFER_SIZE);
		if (bytes < 0)
			return (NULL);
		else if (bytes == 0 && ft_endline(&line))
			break ;
		else if(ft_newline(line) && ft_check_buffer(&buffer, &line))
			break ;
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

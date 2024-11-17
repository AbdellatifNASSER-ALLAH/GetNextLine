/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnasse <abdnasse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:50:09 by abdnasse          #+#    #+#             */
/*   Updated: 2024/11/17 16:48:08 by abdnasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	char	*line;
	ssize_t	bytes;
	size_t	i;

	line = (char *)malloc(BUFFER_SIZE + 1);
	if (!line)
		return (NULL);
	i = 0;
	while ((bytes = read(fd, line + i, 1)) > 0)
	{
		if (i >= BUFFER_SIZE)
		{
			line = ft_realloc(line , i + BUFFER_SIZE);
			if (!line) 
				return (NULL);
		}
		if (line[i] == '\n')
		{
			i++;
			break ;
		}
		i++;
	}
	line[i] = 0;
	line = ft_realloc(line, i);
	if (!line)
		return (NULL);
	if (bytes == 0)
		return (line);
	if (bytes < 0)
	{
		free(line);
		return (NULL);
	}
	return (line);
}

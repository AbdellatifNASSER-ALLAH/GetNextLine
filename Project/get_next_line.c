/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnasse <abdnasse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:50:09 by abdnasse          #+#    #+#             */
/*   Updated: 2024/11/18 16:21:28 by abdnasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <string.h>

char	*get_next_line(int fd)
{
	char	*buffer;
	ssize_t	bytes;
	ssize_t	i;

	buffer = (char *)mallo((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	i = 0;
	while(1)
	{
		bytes = read(fd, buffer + i, BUFFER_SIZE);
		if(bytes < 0)
			return (NULL);
		if (bytes && ft_newline(buffer))
		{
			buffer = ft_realloc(buffer, ft_newline(buffer));
			if (!buffer)
				return (NULL);
			break;
		}
		else if (bytes && !ft_newline(buffer))
		{
			i += BUFFER_SIZE;
			buffer = ft_realloc(buffer, i + BUFFER_SIZE);
			if (!buffer)
				return (NULL);
		}
		else 
		{
			buffer = ft_realloc(buffer, strlen(buffer));
			if (!buffer)
				return (NULL);
			break;
		}
	}
	return (buffer);
}

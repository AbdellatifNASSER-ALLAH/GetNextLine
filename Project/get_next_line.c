/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnasse <abdnasse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:50:09 by abdnasse          #+#    #+#             */
/*   Updated: 2024/11/18 18:46:58 by abdnasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	char	*buffer;
	ssize_t	bytes;
	ssize_t	i;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	ft_bzero(buffer, BUFFER_SIZE + 1);
	i = 0;
	while(1)
	{
		bytes = read(fd, buffer + i, BUFFER_SIZE);
		if(bytes < 0)
			return (NULL);
		if (bytes == 0) 
		{
			buffer = ft_realloc(buffer, ft_strlen(buffer));
			if (!buffer)
				return (NULL);
			break;
		}
		if (ft_newline(buffer))
		{
			buffer = ft_realloc(buffer, ft_newline(buffer));
			if (!buffer)
				return (NULL);
			break;
		}
		else
		{
			i += BUFFER_SIZE;
			buffer = ft_realloc(buffer, i + BUFFER_SIZE);
			if (!buffer)
				return (NULL);
		}

	}
	return (buffer);
}

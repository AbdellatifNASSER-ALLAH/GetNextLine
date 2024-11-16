/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnasse <abdnasse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:50:09 by abdnasse          #+#    #+#             */
/*   Updated: 2024/11/16 20:33:40 by abdnasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	char	*buff;
	size_t	bytes;
	size_t	i;

	buff = (char *)malloc((BUFFER_SIZE) * sizeof(char));
	if (!buff)
		return (NULL);
	i = 0;
	while ((bytes = read(fd, buff + i, 1)) > 0)
	{
		if (buff[i] == '\n')
		{
			i++;
			break ;
		}
		i++;
	}
	if (bytes < 0)
	{
		free(buff);
		return (NULL);
	}
	buff[i] = '\0';
	return (buff);
}

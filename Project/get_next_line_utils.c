/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnasse <abdnasse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:48:30 by abdnasse          #+#    #+#             */
/*   Updated: 2024/11/18 16:02:34 by abdnasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

size_t	ft_newline(char *p)
{
	size_t	i;

	i = 0;
	while (p && p[i])
	{
		if (p[i++] == '\n')
			break;
	}
	return (i);
}

char	*ft_realloc(char *s, size_t n)
{
	char	*p;
	size_t	i;

	p = malloc(n + 1);
	if (!p)
		return (NULL);
	i = 0;
	while (*s)
		p[i++] = *(s++);
	free(s - i);
	p[i] = '\0';
	return (p);
}

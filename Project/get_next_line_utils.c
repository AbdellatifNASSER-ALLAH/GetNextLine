/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnasse <abdnasse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:48:30 by abdnasse          #+#    #+#             */
/*   Updated: 2024/11/17 00:55:39 by abdnasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*ft_realloc(char *s, size_t n)
{
	char	*p;
	size_t	i;

	p = mallo(n + 1);
	if (!p)
		return (NULL);
	i = 0;
	while (*s)
		p[i++] = *(s++);
	p[i] = 0;
	return (p);
}

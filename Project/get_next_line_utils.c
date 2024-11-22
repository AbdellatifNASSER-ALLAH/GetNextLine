/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnasse <abdnasse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:48:30 by abdnasse          #+#    #+#             */
/*   Updated: 2024/11/22 18:22:09 by abdnasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"


size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_bzero(void *s, size_t n)
{
	char	*p;

	p = s;
	while (n--)
		p[n] = 0;
}

size_t	ft_strcat(char *dst, char *src)
{
	size_t	i;

	i = ft_strlen(dst);
	while (*src)
		dst[i++] = *src++;
	dst[i] = '\0';
	return (i);
}

size_t	f_newline(char *p)
{
	size_t	i;

	if (!p)
		return (0);
	i = 0;
	while (p && p[i] && p[i] != '\n')
		i++;
	if (p[i] == '\n')
		return (i + 1);
	return (0);
}

char	*f_realloc(char *s, size_t n)
{
	char	*p;
	size_t	i;

	p = f_malloc(n + 1);
	if (!p)
		return (NULL);
	i = 0;
	while (s[i] && i < n)
	{
		p[i] = s[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

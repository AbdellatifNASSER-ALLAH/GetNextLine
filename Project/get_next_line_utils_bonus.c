/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnasse <abdnasse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:48:30 by abdnasse          #+#    #+#             */
/*   Updated: 2024/11/25 16:50:08 by abdnasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"

void	ft_bzero(void *b, size_t len)
{
	unsigned char	*t;

	t = b;
	while (len--)
		t[len] = 0;
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
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

	p = (char *)malloc((n + 1) * sizeof(char));
	if (!p)
		return (f_free(&s));
	ft_bzero(p, n + 1);
	i = 0;
	while (s[i] && i < n)
	{
		p[i] = s[i];
		i++;
	}
	f_free(&s);
	p[i] = '\0';
	return (p);
}

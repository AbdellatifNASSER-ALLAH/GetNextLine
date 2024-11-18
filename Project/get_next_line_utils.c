/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnasse <abdnasse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:48:30 by abdnasse          #+#    #+#             */
/*   Updated: 2024/11/18 22:50:34 by abdnasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

size_t	ft_strlen(char *s)
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

size_t	ft_newline(char *p)
{
	size_t	i;

	i = 0;
	while (p && p[i] && p[i] != '\n')
		i++;
	if (p[i] == '\n')
		return (i + 1);
	return (0);
}

char	*ft_realloc(char *s, size_t n)
{
	char	*p;
	char	*org;
	size_t	i;

	org = s;
	p = malloc((n + 1) * sizeof(char));
	if (!p)
		return (NULL);
	ft_bzero(p, n + 1);
	i = 0;
	while (*s && i < n)
		p[i++] = *(s++);
	free(org);
	p[i] = '\0';
	return (p);
}

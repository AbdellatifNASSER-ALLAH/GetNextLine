/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnasse <abdnasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:45:38 by abdnasse          #+#    #+#             */
/*   Updated: 2024/11/22 18:30:32 by abdnasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>


#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1337
#endif

char	*get_next_line(int fd);
char	*f_realloc(char *s, size_t n);
size_t	f_newline(char *p);
void	ft_bzero(void *s, size_t n);
size_t	ft_strlen(const char *s);
size_t	ft_strcat(char *s1, char *s2);
char	*f_malloc(size_t size);
int	f_buffer_to_cache(char *buffer,char **cache, ssize_t bytes);
char	*f_set_line(char **cache);
char	*ft_strdup(const char *s);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnasse <abdnasse@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:45:38 by abdnasse          #+#    #+#             */
/*   Updated: 2024/11/18 17:10:38 by abdnasse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1024
#endif

char	*get_next_line(int fd);
char	*ft_realloc(char *s, size_t n);
size_t	ft_newline(char *p);
void	ft_bzero(void *s, size_t n);
size_t	ft_strlen(char *s);

#endif

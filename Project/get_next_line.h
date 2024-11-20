/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdnasse <abdnasse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:45:38 by abdnasse          #+#    #+#             */
/*   Updated: 2024/11/20 13:53:46 by abdnasse         ###   ########.fr       */
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
char	*_realloc(char *s, size_t n);
size_t	_newline(char *p);
void	ft_bzero(void *s, size_t n);
size_t	ft_strlen(const char *s);
size_t	ft_strcat(char *s1, char *s2);

#endif

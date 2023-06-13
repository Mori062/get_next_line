/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morishitashoto <morishitashoto@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 00:05:03 by morishitash       #+#    #+#             */
/*   Updated: 2023/06/13 20:06:45 by morishitash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>

char	*get_next_line(int fd);



char	*ft_strjoin(const char *s1, const char *s2);


size_t	ft_strlen(const char *s);

char	*ft_substr(const char *s, unsigned int start, size_t len);


char	*ft_strdup(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);

#endif
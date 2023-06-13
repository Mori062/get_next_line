/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morishitashoto <morishitashoto@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 11:32:15 by morishitash       #+#    #+#             */
/*   Updated: 2023/06/12 11:32:48 by morishitash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*buff;
	static char	*storage[OPEN_MAX + 1];
	int			newline_pos;
	int			bytes_read[1];

	if ( fd < 0 ||  OPEN_MAX < fd )
		return (NULL);

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	// 何かしらの処理
	free(buff);
	// 何かしらの処理
	return ('なにかしらの文字列');
}
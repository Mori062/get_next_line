/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morishitashoto <morishitashoto@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 00:04:36 by morishitash       #+#    #+#             */
/*   Updated: 2023/06/12 10:16:32 by morishitash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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


// #include <fcntl.h>
// #include <stdio.h>
// int main()
// {
//     char *test = "";
//     int fd = open("test1.txt", O_RDONLY);
//     test = get_next_line(fd);
//     while (test)
//     {
//         printf("%s", test);
//         free(test);
//         test = get_next_line(fd);
//     }
//     printf("\n");
//     free(test);
//     close(fd);
// }

// __attribute__((destructor))
// static void destructor() {
//     system("leaks -q a.out");
// }
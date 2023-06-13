/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morishitashoto <morishitashoto@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 00:04:36 by morishitash       #+#    #+#             */
/*   Updated: 2023/06/12 13:32:17 by morishitash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*buff;
	static char	*storage[OPEN_MAX];
	int			pos;
	int			bytes_read[1];

	if (fd < 0 || OPEN_MAX <= fd)
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
// int	main(void)
// {
// 	char	*test = "";
// 	int		fd;

// 	fd = open("test1.txt", O_RDONLY);
// 	test = get_next_line(fd);
// 	while (test)
// 	{
// 		printf("%s", test);
// 		free(test);
// 		test = get_next_line(fd);
// 	}
// 	printf("\n");
// 	free(test);
// 	close(fd);
// }

// __attribute__((destructor)) static void	destructor(void)
// {
// 	system("leaks -q a.out");
// }

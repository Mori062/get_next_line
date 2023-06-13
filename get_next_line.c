/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morishitashoto <morishitashoto@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 00:04:36 by morishitash       #+#    #+#             */
/*   Updated: 2023/06/13 20:07:17 by morishitash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	get_newline_pos(char *str)
{
	size_t	i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i + 1);
		i++;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	char		*buff;
	static char	*storage[OPEN_MAX];
	int			pos;

	if (fd < 0 || OPEN_MAX <= fd || BUFFER_SIZE <= 0)
		return (NULL);
	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	pos = get_newline_pos(storage[fd]);
	while (pos != 0)
	{
		pos = read(fd, buff, BUFFER_SIZE);
		if (pos == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[pos] = '\0';
		storage[fd] = ft_strjoin(storage[fd], buff);
		pos = get_newline_pos(storage[fd]);
	}
	free(buff);
	return (ft_substr(storage[fd], 0, pos));
}




#include <fcntl.h>
#include <stdio.h>
int	main(void)
{
	char	*test = "";
	int		fd;

	fd = open("test1.txt", O_RDONLY);
	test = get_next_line(fd);
	while (test)
	{
		printf("%s", test);
		free(test);
		test = get_next_line(fd);
	}
	printf("\n");
	free(test);
	close(fd);
}

__attribute__((destructor)) static void	destructor(void)
{
	system("leaks -q a.out");
}

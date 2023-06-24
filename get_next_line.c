/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morishitashoto <morishitashoto@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 00:04:36 by morishitash       #+#    #+#             */
/*   Updated: 2023/06/25 03:49:48 by morishitash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

size_t	find_newline_pos(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (i);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strnjoin(char *s1, char *s2, size_t n)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!s2)
		return (NULL);
	if (!s1)
		str = (char *)malloc(sizeof(char) * (n + 1));
	else
		str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + n + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	if (s1)
		while (s1[i])
		{
			str[j++] = s1[i++];
		}
	i = 0;
	while (s2[i] && i < n)
	{
		str[j++] = s2[i++];
	}
	str[j] = '\0';
	free(s2);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*buff;
	char		*arr;
	static char	*storage[OPEN_MAX] = {0};
	size_t		read_size;

	if (fd < 0 || OPEN_MAX <= fd || BUFFER_SIZE <= 0)
		return (NULL);
	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	while(1)
	{
		read_size = read(fd, buff, BUFFER_SIZE);
		if (read_size < 0)
			return (NULL);
		buff[BUFFER_SIZE] = '\0';
		arr = ft_strnjoin(storage[fd], buff, find_newline_pos(buff));
		printf("%s\n", arr);
	}
	return (0);
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
		printf("--%s", test);
		free(test);
		test = get_next_line(fd);
	}
	printf("\n");
	free(test);
	close(fd);
}

// __attribute__((destructor)) static void	destructor(void)
// {
// 	system("leaks -q a.out");
// }

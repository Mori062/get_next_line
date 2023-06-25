/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morishitashoto <morishitashoto@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 00:04:36 by morishitash       #+#    #+#             */
/*   Updated: 2023/06/25 18:53:40 by morishitash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s)
{
	char	*str;
	size_t	i;

	str = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!str)
		return (NULL);
	i = -1;
	while (s[++i])
		str[i] = s[i];
	str[i] = '\0';
	return (str);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = start;
	j = 0;
	while (s[i] && j < len)
		str[j++] = s[i++];
	str[j] = '\0';
	return (str);
}

size_t	find_newline_pos(char *str)
{
	size_t	i;

	i = 0;
	if (str == NULL)
		return (0);
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

	// printf("%s\n", s1);
	// if (!s2)
	// 	return (NULL);
	if (!s1)
		str = (char *)malloc(sizeof(char) * (n + 1));
	else
		str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + n + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	if (s1)
	{
		while (s1[i] != '\0' && s1[i] != '\n')
		{
			// printf("--------------%c\n", s1[i]);
			str[j] = s1[i];
			j++;
			i++;
		}
	}
	i = 0;
	// printf("s2: %s\n", s2);
	while (s2[i] && i < n)
		str[j++] = s2[i++];
	str[j] = '\0';
	// str[j + 1] = '\0';
	// free(s2);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*buff;
	char		*arr;
	static char	*storage[OPEN_MAX];
	size_t		read_size;
	size_t		flag;

	if (fd < 0 || OPEN_MAX <= fd || BUFFER_SIZE <= 0)
		return (NULL);
	flag = 0;
	arr = NULL;
	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	int count = 0;
	while (1)
	{
		read_size = read(fd, buff, BUFFER_SIZE);
		if (read_size < 0)
			return (NULL);
		if (read_size == 0)
			break ;
		buff[BUFFER_SIZE] = '\0';
		if (storage[fd])
		{
			arr = ft_strnjoin(storage[fd], buff, find_newline_pos(storage[fd]) + BUFFER_SIZE);
			// printf("ue arr = %s\n", arr);
		}
		// printf("find_new_line -> %zu\n",find_newline_pos(buff));
		if (find_newline_pos(buff) < BUFFER_SIZE)
		{
			// printf("入ったよ！   ");
			flag += 1;
			// printf("flag -> %zu\n", flag);
			storage[fd] = ft_substr(buff, find_newline_pos(buff) + 1, BUFFER_SIZE - find_newline_pos(buff));
			// printf("%d : storage[fd] -> %s\n", count, storage[fd]);
		}
		if (storage[fd])
			buff = NULL;
		printf("arr = %s\nbuff = %s\n", arr, buff);
		arr = ft_strnjoin(arr, buff, find_newline_pos(buff));
		printf("arr = %s\n", arr);
		if (flag >= 1)
			break ;
		count++;
		// printf("%zu\n", flag);
		// printf("%s\n", arr);
	}
	return (arr);
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
		// printf("test : %s\n", test);
		// free(test);
		test = get_next_line(fd);
	}
	printf("\n");
	// free(test);
	close(fd);
}

// __attribute__((destructor)) static void	destructor(void)
// {
// 	system("leaks -q a.out");
// }

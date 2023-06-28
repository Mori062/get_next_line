/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morishitashoto <morishitashoto@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 00:04:36 by morishitash       #+#    #+#             */
/*   Updated: 2023/06/28 15:20:58 by morishitash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	newline_ex(char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (0);
		i++;
	}
	if (s[i] == c)
		return (0);
	return (1);
}

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

size_t	newline_pos(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == '\n')
			return (i + 1);
		i++;
	}
	return (i);
}

char	*ft_strdup(char *s)
{
	char	*str;
	size_t	i;
	size_t	j;

	str = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
		str[j++] = s[i++];
	str[i] = '\0';
	return (str);
}

char	*ft_strnjoin(char *s1, char *s2, size_t len)
{
	char	*str;
	size_t	i;
	size_t	j;

	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + len + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	if (s1)
	{
		while (s1[i])
			str[j++] = s1[i++];
	}
	i = 0;
	if (s2)
	{
		while (s2[i] && i < len)
			str[j++] = s2[i++];
	}
	str[j] = '\0';
	// free(s1);
	return (str);
}

char	*keep_store(char *buff, size_t pos)
{
	char	*tmp;
	size_t	i;

	i = 0;
	if (!buff)
	{
		free(buff);
		return (NULL);
	}
	tmp = (char *)malloc(sizeof(char) * (ft_strlen(buff) - pos + 1));
	if (!tmp)
		return (NULL);
	while (buff[pos])
		tmp[i++] = buff[pos++];
	tmp[i] = '\0';
	return (tmp);
}

char	*get_next_line(int fd)
{
	char		*buff;
	char		*arr;
	static char	*storage[OPEN_MAX];
	size_t		read_size;

	if (fd < 0 || OPEN_MAX <= fd || BUFFER_SIZE <= 0)
		return (NULL);
	arr = NULL;
	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	if (storage[fd])
		arr = ft_strdup(storage[fd]);
	while (1)
	{
		read_size = read(fd, buff, BUFFER_SIZE);
		if (read_size < 0)
			break;
		buff[read_size] = '\0';
		if (!buff[0] && arr[0])
			return (arr);
		if (read_size == 0)
			return (NULL);
		if (newline_pos(arr) == ft_strlen(arr))
		{
			arr = ft_strnjoin(arr, buff, newline_pos(buff));
			storage[fd] = keep_store(buff, newline_pos(buff));
		}
		else
		{
			arr = ft_strnjoin(NULL, storage[fd], newline_pos(storage[fd]));
			storage[fd] = keep_store(storage[fd], newline_pos(storage[fd]));
			storage[fd] = ft_strnjoin(storage[fd], buff, newline_pos(buff));
		}
		if (!newline_ex(arr, '\n'))
			break ;
	}
	return (arr);
}

// #include <fcntl.h>
// #include <stdio.h>
// int	main(void)
// {
// 	char	*test = "";
// 	int		fd;
// 	int		i;

// 	fd = open("test1.txt", O_RDONLY);
// 	i = 0;
// 	while (1)
// 	{
// 		test = get_next_line(fd);
// 		printf("%d: %s", i++, test);
// 		if (test == NULL)
// 			break ;
// 	}
// 	printf("\n");
// 	// free(test);
// 	close(fd);
// }

// __attribute__((destructor)) static void	destructor(void)
// {
// 	system("leaks -q a.out");
// }

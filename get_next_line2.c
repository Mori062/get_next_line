/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmorish <shmorish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 00:21:31 by shmorish          #+#    #+#             */
/*   Updated: 2023/07/02 07:46:21 by shmorish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "get_next_line.h"

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>

#define BUFFER_SIZE 20

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

char	*ft_strdup(char *s)
{
	char	*ret;
	size_t	i;

	i = 0;
	ret = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!ret)
		return (NULL);
	while (s[i])
	{
		ret[i] = s[i];
		i++;
	}
	ret[i] = 0;
	free(s);
	return (ret);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ret;
	size_t	i;
	size_t	j;

	ret = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!ret)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		ret[j++] = s1[i++];
	i = 0;
	while (s2[i])
		ret[j++] = s2[i++];
	ret[j] = 0;
	free(s1);
	free(s2);
	return (ret);
}

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

char	*get_before_newline(char *s)
{
	char	*ret;
	size_t	i;

	i = 0;
	ret = (char *)malloc(sizeof(char) * (newline_pos(s) + 1));
	if (!ret)
		return (NULL);
	while (s[i] && s[i] != '\n')
	{
		ret[i] = s[i];
		i++;
	}
	if (s[i] == '\n')
		ret[i++] = '\n';
	ret[i] = '\0';
	return (ret);
}

char	*get_after_newline(char *s)
{
	char	*ret;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	ret = (char *)malloc(sizeof(char) * (ft_strlen(s) - newline_pos(s) + 1));
	if (!ret)
		return (NULL);
	while (s[i] && s[i] != '\n')
		i++;
	i++;
	while (s[i])
		ret[j++] = s[i++];
	ret[j] = '\0';
	free(s);
	return (ret);
}

char	*get_next_line(int fd)
{
	static char	*store[OPEN_MAX];
	char		*buf;
	char		*line;
	size_t		read_size;

	if (fd < 0 || OPEN_MAX <= fd || BUFFER_SIZE <= 0)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	while (1)
	{
		read_size = read(fd, buf, BUFFER_SIZE);
		if (read_size <= 0 && store[fd] == NULL)
			return (NULL);
		buf[read_size] = '\0';
		if (store[fd] == NULL)
			store[fd] = ft_strdup(buf);
		else
			store[fd] = ft_strjoin(store[fd], buf);
		if (!newline_ex(store[fd], '\n'))
		{
			line = get_before_newline(store[fd]);
			store[fd] = get_after_newline(store[fd]);
			return (line);
		}
		if (read_size == 0)
		{
			line = ft_strdup(store[fd]);
			store[fd] = NULL;
			return (line);
		}
	}
}

#include <fcntl.h>
#include <stdio.h>
int	main(void)
{
	char	*test = "";
	int		fd;
	int		i;

	fd = open("get_next_line2.c", O_RDONLY);
	i = 0;
	while (1)
	{
		test = get_next_line(fd);
		printf("%d: %s", i++, test);
		if (test == NULL)
			break ;
		free(test);
	}
	printf("\n");
	close(fd);
}

__attribute__((destructor))
static void	destructor(void){
	system("leaks -q a.out");
}

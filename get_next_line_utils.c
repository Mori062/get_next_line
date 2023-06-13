/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morishitashoto <morishitashoto@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 00:05:00 by morishitash       #+#    #+#             */
/*   Updated: 2023/06/13 19:48:40 by morishitash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// strjoin, strlen
#include "get_next_line.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*ret;
	size_t	len;

	if (!s1 || !s2)
		return (0);
	len = ft_strlen(s1) + ft_strlen(s2);
	ret = malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (0);
	ft_strlcpy(ret, s1, len + 1);
	ft_strlcat(ret, s2, len + 1);
	return (ret);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	i;

	if (!s)
		return (0);
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	ret = malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (0);
	i = 0;
	while (i < len && s[start + i])
	{
		ret[i] = s[start + i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

char	*ft_strdup(const char *s)
{
	char	*ret;
	size_t	len;
	size_t	i;

	len = ft_strlen(s);
	ret = malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (0);
	i = 0;
	while (i < len)
	{
		ret[i] = s[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}


size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len;

	if (!dst || !src)
		return (0);
	len = ft_strlen(src);
	if (dstsize == 0)
		return (len);
	i = 0;
	while (i < dstsize - 1 && i < len)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (len);
}


size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len;

	if (!dst || !src)
		return (0);
	len = ft_strlen(dst);
	if (dstsize <= len)
		return (ft_strlen(src) + dstsize);
	i = 0;
	while (src[i] && len + i < dstsize - 1)
	{
		dst[len + i] = src[i];
		i++;
	}
	dst[len + i] = '\0';
	return (ft_strlen(src) + len);
}
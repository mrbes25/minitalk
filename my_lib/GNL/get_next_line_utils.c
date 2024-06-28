/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmid <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 16:17:11 by bschmid           #+#    #+#             */
/*   Updated: 2023/12/12 16:17:13 by bschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*new_str;
	int		i;
	int		b;

	i = 0;
	b = 0;
	if (!s1)
		s1 = "";
	if (!s2)
		s2 = "";
	new_str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!new_str)
		return (NULL);
	while (s1[i])
	{
		new_str[i] = s1[i];
		i++;
	}
	while (s2[b])
		new_str[i++] = s2[b++];
	new_str[i] = '\0';
	return (new_str);
}

size_t	ft_strlen(const char *s)
{
	int	l;

	l = 0;
	while (s && s[l])
		l++;
	return (l);
}

char	*ft_strndup(const char *src, size_t n)
{
	char	*dest;
	size_t	length;
	size_t	i;

	length = ft_strlen(src);
	i = 0;
	if (n < length)
		length = n;
	dest = (char *)malloc(sizeof(char) * (length + 1));
	if (dest == NULL)
		return (NULL);
	while (i < length)
	{
		dest[i] = src[i];
		i++;
	}
	dest[length] = '\0';
	return (dest);
}

char	*ft_strdup(const char *s)
{
	char	*d;
	int		i;

	i = 0;
	d = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (d == NULL)
		return (NULL);
	while (*s)
		d[i++] = *s++;
	d[i] = '\0';
	return (d);
}

char	*ft_strchr(char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s != (char)c)
	{
		if (*s == '\0')
			return (NULL);
		s++;
	}
	return ((char *)s);
}

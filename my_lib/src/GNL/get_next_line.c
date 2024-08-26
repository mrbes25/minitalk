/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmid <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 16:16:51 by bschmid           #+#    #+#             */
/*   Updated: 2023/12/12 16:16:53 by bschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*move_it(char **str)
{
	char	*line;
	char	*newline;
	char	*placeholder_str;

	if (!*str || !**str)
		return (NULL);
	newline = ft_strchr(*str, '\n');
	if (newline)
	{
		line = ft_strndup(*str, newline - *str + 1);
		placeholder_str = *str;
		*str = ft_strdup(newline + 1);
		free(placeholder_str);
	}
	else
	{
		line = ft_strdup(*str);
		free(*str);
		*str = NULL;
	}
	return (line);
}

static char	*ft_read_join(int fd, char *str)
{
	char	buffer[BUFFER_SIZE + 1];
	ssize_t	bytes;
	char	*tmp;

	if (!str)
		str = NULL;
	while (1)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == 0 || bytes == -1)
		{
			if (bytes == 0 && str && *str)
				return (str);
			free(str);
			return (NULL);
		}
		buffer[bytes] = '\0';
		tmp = ft_strjoin(str, buffer);
		free(str);
		str = tmp;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	str = ft_read_join(fd, str);
	line = move_it(&str);
	return (line);
}

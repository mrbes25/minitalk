/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmid <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 18:43:16 by bschmid           #+#    #+#             */
/*   Updated: 2023/10/31 18:43:20 by bschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*size_t	ft_strlen(const char *s)
{
	int	l;

	l = 0;
	while (s[l] != '\0')
		l++;
	return (l);
}

char	*ft_strdup(const char *s)
{
	int		str_len;
	char	*d;
	int		i;

	i = 0;
	str_len = ft_strlen(s);
	d = (char *)malloc((str_len + 1) * sizeof(char));
	if (d == NULL)
		return (NULL);
	while (s[i])
	{
		d[i] = s[i];
		i++;
	}
	d[i] = '\0';
	return (d);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	str_len;
	size_t	i;

	if (!s)
		return (NULL);
	str_len = ft_strlen(s);
	if (start >= str_len)
		return (ft_strdup(""));
	str_len -= start;
	if (len > str_len)
		len = str_len;
	ptr = (char *)malloc((len + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		ptr[i] = s[start + i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}*/

static void	free_str_array(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

static int	count_words(char const *s, char c)
{
	int	i1;
	int	count;

	i1 = 0;
	count = 0;
	while (s[i1])
	{
		if (s[i1] == c)
			i1++;
		else
		{
			count++;
			while (s[i1] && s[i1] != c)
				i1++;
		}
	}
	return (count);
}

static void	fill_strs(char const *s, char c, char **strs, int *error)
{
	int	i1;
	int	i2;
	int	i3;

	i1 = 0;
	i2 = 0;
	while (s[i1] && *error == 0)
	{
		if (s[i1] != c)
		{
			i3 = i1;
			while (s[i1] && s[i1] != c)
				i1++;
			strs[i2++] = ft_substr(s, i3, i1 - i3);
			if (!strs[i2 - 1])
				*error = 1;
		}
		else
			i1++;
	}
	strs[i2] = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	int		error;

	error = 0;
	if (!s)
		return (NULL);
	strs = (char **)malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!strs)
		return (NULL);
	fill_strs(s, c, strs, &error);
	if (error)
	{
		free_str_array(strs);
		return (NULL);
	}
	return (strs);
}
/*
int	main(void)
{
	char	**strs;
	char	*str = "           ";
	char	c;
	int		i1 = 0;
	int		i2 = 0;
	
	c = ' ';
	strs = ft_split(str, c);
	if (!strs)
		return (0);
	while (strs[i1])
	{
		i2 = 0;
		while(strs[i1][i2])
		{
			write (1, &strs[i1][i2], 1);
			i2++;
		}
		i1++;
	}
	return (0);
}*/

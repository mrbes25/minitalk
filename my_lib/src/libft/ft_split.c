/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmid <bschmid@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 18/06/2024 20:23:55 by bschmid           #+#    #+#             */
/*   Updated: 26/06/2024 15:07:40 by bschmid          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

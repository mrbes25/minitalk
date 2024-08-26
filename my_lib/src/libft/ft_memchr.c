/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmid <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 10:02:33 by bschmid           #+#    #+#             */
/*   Updated: 2023/10/27 10:02:35 by bschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	b;
	size_t	i;

	b = c;
	i = 0;
	while (i < n)
	{
		if (*(char *)s == b)
			return ((void *)s);
		s++;
		i++;
	}
	return (NULL);
}

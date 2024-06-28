/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmid <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 14:08:40 by bschmid           #+#    #+#             */
/*   Updated: 2023/10/26 14:08:42 by bschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*last;
	char	cc;

	cc = c;
	last = NULL;
	while (*s)
	{
		if (*s == cc)
			last = ((char *)s);
		s++;
	}
	if (cc == '\0')
		return ((char *)s);
	return (last);
}

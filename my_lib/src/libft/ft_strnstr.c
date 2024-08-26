/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmid <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:55:23 by bschmid           #+#    #+#             */
/*   Updated: 2023/10/30 15:55:27 by bschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	if (*needle == '\0' || haystack == needle)
		return ((char *)haystack);
	while (*haystack && len > 0)
	{
		i = 0;
		if (*haystack == *needle)
		{
			while (needle[i] && needle[i] == haystack[i] && i < len)
			{
				if (needle[i + 1] == '\0')
					return ((char *)haystack);
				i++;
			}
		}
		len--;
		haystack++;
	}
	return (NULL);
}

/*#include "libft.h"
#include <stdio.h>

int main()
{
    const char *haystack = "aaabc";
    const char *needle = "a";
    size_t len = 1;

    char *result = ft_strnstr(haystack, needle, len);

    if (result)
    {
        printf("Needle found at position: %ld\n", result - haystack);
    }
    else
    {
        printf("Needle not found in haystack.\n");
    }

    return 0;
}
*/
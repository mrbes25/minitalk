/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_lower.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmid <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 10:47:27 by bschmid           #+#    #+#             */
/*   Updated: 2023/11/06 10:47:34 by bschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex_lower(unsigned long n)
{
	int		i;
	int		count;
	char	buffer[64];

	i = 0;
	count = 0;
	if (n == 0)
		return (write(1, ("0"), 1));
	while (n > 15)
	{
		buffer[i++] = (n % 16);
		n /= 16;
	}
	buffer[i] = n;
	while (i >= 0)
	{
		if (buffer[i] >= 0 && buffer[i] <= 9)
			count += ft_putchar(buffer[i] + 48);
		else if (buffer[i] >= 10 && buffer[i] <= 15)
			count += ft_putchar(buffer[i] + 87);
		i--;
	}
	return (count);
}

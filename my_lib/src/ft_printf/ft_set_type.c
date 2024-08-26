/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmid <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 09:12:35 by bschmid           #+#    #+#             */
/*   Updated: 2023/11/14 09:12:38 by bschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

int	ft_set_type(const char *format, va_list ap)
{
	int	count;

	count = 0;
	if (*format == 'c')
		count += ft_putchar(va_arg(ap, int));
	else if (*format == 's')
		count += ft_putstr(va_arg(ap, char *));
	else if (*format == 'p')
		count += ft_putpointer(va_arg(ap, void *));
	else if (*format == 'd' || *format == 'i')
		count += ft_putnbr(va_arg(ap, int));
	else if (*format == 'u')
		count += ft_putnbr(va_arg(ap, unsigned int));
	else if (*format == 'x')
		count += ft_puthex_lower(va_arg(ap, unsigned int));
	else if (*format == 'X')
		count += ft_puthex_upper(va_arg(ap, unsigned int));
	else if (*format == '%')
		count += ft_putchar('%');
	return (count);
}

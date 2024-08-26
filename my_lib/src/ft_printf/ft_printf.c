/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmid <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:05:42 by bschmid           #+#    #+#             */
/*   Updated: 2023/11/13 15:05:44 by bschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*argument pointer points to the first argument
return how many characters it printed*/
#include "ft_printf.h"

static int	check_format(const char *format)
{
	if ((*format == 'c') || (*format == 's') || (*format == 'p')
		|| (*format == 'd') || (*format == 'i') || (*format == 'u')
		|| (*format == 'x') || (*format == 'X' || (*format == '%')))
		return (1);
	else
		return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;

	count = 0;
	va_start(ap, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (check_format(format) == 1)
			{
				count += ft_set_type(format, ap);
				format++;
			}
		}
		else
		{
			count += ft_putchar(*format);
			format++;
		}
	}
	va_end(ap);
	return (count);
}

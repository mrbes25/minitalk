/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmid <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 16:45:49 by bschmid           #+#    #+#             */
/*   Updated: 2023/11/14 16:45:52 by bschmid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_putchar(char c);
int	ft_puthex_lower(unsigned long n);
int	ft_puthex_upper(unsigned long n);
int	ft_putnbr(long n);
int	ft_putpointer(void *struggle);
int	ft_putstr(char *s);
int	ft_set_type(const char *format, va_list ap);

#endif
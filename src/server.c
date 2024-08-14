/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmid <bschmid@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 11:25:26 by bschmid           #+#    #+#             */
/*   Updated: 2024/08/14 11:37:43 by bschmid          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	sig_handler(int sig)
{
	static int	bit;
	static int	il

	if (sig == SIGUSR1)
		i |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", i);
		bit = 0;
		i = 0;
	}
}
int	main(int argc, char **argv)
{
	pid_t	pid;

	(void)argv; //supress the unudes parameter warning for argv
	if (argc != 1)
	{
		ft_printf("Error: wrong format\n");
		ft_printf("Try: ./server\n");
	}
	pid = getpid();
	ft_printf("PID: %d\n", pid);
	ft_printf("Waiting for a message...\n");
	while (argc == 1) // infinit loop to wait for signals
	{
		signal(SIGUSR1, sig_handler);
		signal(SIGUSR2, sig_handler);
		pause();
	}
	return (0);
}

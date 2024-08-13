/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmid <bschmid@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 15:42:27 by bschmid           #+#    #+#             */
/*   Updated: 2024/08/13 17:07:27 by bschmid          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_bits(pid_t, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((c & (0x01 << bit)) != 0)
			kill(pid, SIGUSR1)
		else
			kill(pid, SIGUSR2)
		usleep(100);
		bit++;
	}
}
int	main(int argc, char **argv)
{
	pid_t	pid;
	char	*msg;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		msg = argv[2];
		while (*msg != '\0')
		{
			send_bits(pid, *msg);
			msg++;
		}
		send_bits(pid. '\0')
	}
	else
	{
		ft_printf("Error: wrong format\n");
		ft_printf
	}
}

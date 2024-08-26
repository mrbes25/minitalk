/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmid <bschmid@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 14:59:51 by bschmid           #+#    #+#             */
/*   Updated: 2024/08/26 15:46:22 by bschmid          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

void	send_bits(pid_t pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((c & (0x01 << bit)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(200);
		bit++;
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;
	char	*msg;

	if (argc != 3)
	{
		ft_printf("Error: wrong format\n");
		return (1);
	}
	pid = ft_atoi(argv[1]);
	msg = argv[2];
	while (*msg)
	{
		send_bits(pid, *msg);
		msg++;
	}
	send_bits(pid, '\n');
	return (0);
}

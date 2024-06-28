/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmid <bschmid@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 09:05:52 by bschmid           #+#    #+#             */
/*   Updated: 2024/06/28 09:31:01 by bschmid          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int main(void)
{
	// Print the process ID of the server
	ft_printf("Server PID: %d\n", getpid());

	// Set up the signal handler
	struct sigaction sa;
	sa.sa_sigaction = &ft_handle_signal; // Set the signal handler function
	sa.sa_flags = SA_SIGINFO; // Use extended signal information
	sigaction(SIGUSR1, &sa, NULL); // Set the handler for SIGUSR1
	sigaction(SIGUSR2, &sa, NULL); // Set the handler for SIGUSR2

	// Wait for signals indefinitely
	while (1)
		;

	return (0);
}

void ft_handle_signal(int signum, siginfo_t *info, void *context)
{
	// Variables to keep track of the received character and bit count
	static unsigned char character = 0;
	static int bit_count = 0;
	static int client_pid = 0;

	(void)context; // Ignore the context parameter

	// If the signal is from a different client, reset the character and bit count
	if (client_pid != info->si_pid)
	{
		bit_count = 0;
		character = 0;
	}
	client_pid = info->si_pid;

	// Shift the character to the left by 1 bit
	character = character << 1;

	// If the signal is SIGUSR1, set the least significant bit of the character to 1
	if (signum == SIGUSR1)
		character |= 1;

	// Increment the bit count
	bit_count++;

	// If we have received 8 bits (a full character), print the character and reset the variables
	if (bit_count == 8)
	{
		write(1, &character, 1);
		bit_count = 0;
		character = 0;
	}

	// Send a SIGUSR2 signal back to the client to acknowledge the received signal
	kill(client_pid, SIGUSR2);
}

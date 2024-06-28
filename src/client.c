/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmid <bschmid@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 12:26:35 by bschmid           #+#    #+#             */
/*   Updated: 2024/06/28 12:52:52 by bschmid          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int main(int argc, char **argv)
{
	pid_t pid;
	if (argc != 3) // Check if the number of command line arguments is not equal to 3
	{
		ft_putstr_fd("Usage: ./client [PID] [MESSAGE]\n", 2); // Print an error message to the standard error stream
		exit(EXIT_FAILURE); // Terminate the program with a failure status
	}
	pid = ft_atoi(argv[1]); // Convert the first command line argument to an integer and assign it to 'pid'
	if (pid <= 0) // Check if 'pid' is less than or equal to 0
	{
		ft_putstr_fd("Invalid PID\n", 2); // Print an error message to the standard error stream
		exit(EXIT_FAILURE); // Terminate the program with a failure status
	}
	signal (SIGUSR1, ft_resp_handler); // Register 'ft_resp_handler' as the signal handler for SIGUSR1
	ft_send_string(pid, argv[2]); // Send the message (third command line argument) to the specified process (PID)
	return (0); // Terminate the program with a success status
}

int g_confirm_flag = 0; // Global variable to indicate if a confirmation signal has been received

void ft_resp_handler(int signum)
{
	g_confirm_flag = 1; // Set the global confirmation flag to 1
	(void)signum; // Suppress unused parameter warning
}

void ft_send_bit(int pid, int bit)
{
	int signal;

	if (bit == 1) // Check if the bit is equal to 1
		signal = SIGUSR1; // Set the signal to SIGUSR1
	else
		signal = SIGUSR2; // Set the signal to SIGUSR2
	if (kill(pid, signal) == -1) // Send the signal to the specified process
	{
		ft_putstr_fd("Error\n", 2); // Print an error message to the standard error stream
		exit(EXIT_FAILURE); // Terminate the program with a failure status
	}
	while (!g_confirm_flag) // Wait until the confirmation flag is set
		;
	g_confirm_flag = 0; // Reset the confirmation flag
}

void ft_send_char(int pid, char c)
{
	int i;

	i = 7; // Start from the most significant bit
	while (i >= 0) // Iterate through each bit of the character
	{
		ft_send_bit(pid, (c >> i) & 1); // Send the bit to the specified process
		usleep(400); // Sleep for 400 microseconds
		i--; // Move to the next bit
	}
}

void ft_send_string(int pid, char *str)
{
	while (*str) // Iterate through each character of the string
		ft_send_char(pid, *str++); // Send the character to the specified process and move to the next character
	ft_send_char(pid, '\0'); // Send the null terminator to indicate the end of the string
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleal <jleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 16:58:15 by jleal             #+#    #+#             */
/*   Updated: 2025/06/05 20:56:31 by jleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	configure_sigaction_signals(struct sigaction *sa)
{
	if (sigaction(SIGUSR1, sa, NULL) < 0)
	{
		write(2, "Error initializing SIGUSR1\n", 27);
		exit(EXIT_FAILURE);
	}
	if (sigaction(SIGUSR2, sa, NULL) < 0 )
	{
		
		write(2, "Error initializing SIGUSR2\n", 27);
		exit(EXIT_FAILURE);
	}
}

void	send_int(pid_t pid, int num)
{
	int		shift;
	char	bit;

	shift = (sizeof(int) * 8) - 1;
	while (shift >= 0)
	{
		bit = (num >> shift) & 1;
		send_bit(pid, bit, 1);
		shift--;
	}
}

void	send_char(pid_t pid, char c)
{
	int		shift;
	char	bit;

	shift = (CHAR_BIT - 1);
	while (shift >= 0)
	{
		bit = (c >> shift) & 1;
		send_bit(pid, bit, 1);
		shift--;
	}
}

void	send_bit(pid_t pid, char bit, char flag_to_pause)
{
	if (bit == 0)
	{
		if (kill(pid, SIGUSR1) < 0)
		{
			write(2, "Error sending SIGUSR1\n", 22);
			exit(EXIT_FAILURE);
		}
	}
	else if (bit == 1)
	{
		if (kill(pid, SIGUSR2) < 0)
		{
			write(2, "Error sending SIGUSR2\n", 22);
			exit(EXIT_FAILURE);
		}
	}
	if (flag_to_pause != 0)
		pause();
}

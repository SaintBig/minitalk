/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleal <jleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 16:47:36 by jleal             #+#    #+#             */
/*   Updated: 2025/06/07 19:14:20 by jleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile sig_atomic_t	g_server = BUSY;

static void	end_handler(void)
{
	ft_putstr("\e[92m > end of message signal received from server\n\e[0m");
	exit(EXIT_SUCCESS);
}

static void	ack_handler(void)
{
	g_server = READY;
}

static void	send_char(char c, pid_t server)
{
	int	bit;

	bit = 0;
	while (bit < CHAR_BIT)
	{
		if (c & (0x80 >> bit))
			ft_kill(server, SIGUSR1);
		else
			ft_kill(server, SIGUSR2);
		bit++;
		while (BUSY == g_server)
			usleep(42);
		g_server = BUSY;
	}
}

int	main(int ac, char **av)
{
	pid_t	server;
	char	*message;
	int		i;

	if (ac != 3)
	{
		write(2, "./client <server pid> \"message\"\n", 32);
		return (EXIT_FAILURE);
	}
	server = ft_atoi(av[1]);
	if (server < 1)
	{
		write(2, "Invalid PID\n", 12);
		return (EXIT_FAILURE);
	}
	message = av[2];
	ft_signal(SIGUSR1, ack_handler, 0);
	ft_signal(SIGUSR2, end_handler, 0);
	i = 0;
	while (message[i])
		send_char(message[i++], server);
	send_char('\0', server);
	return (EXIT_SUCCESS);
}

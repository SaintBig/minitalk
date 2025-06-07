/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleal <jleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 16:40:50 by jleal             #+#    #+#             */
/*   Updated: 2025/06/07 19:19:48 by jleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static void	client_handler(int sig)
{
	if (sig == SIGUSR2)
	{
		ft_putstr("\e[92m > end of message signal received from server\n\e[0m");
		exit(EXIT_SUCCESS);
	}
}

static void	client_send_message(int server_pid, char *str)
{
	int	i;

	i = 0;
	{
		ft_putstr("\e[92msending length = [");
		ft_putnbr_fd(ft_strlen(str), STDOUT_FILENO);
		ft_putstr("]\n\e[0m");
		send_int(server_pid, ft_strlen(str));
		ft_putstr("\e[92msending message...\n\e[0m");
		while (str[i] != '\0')
			send_char(server_pid, str[i++]);
		send_char(server_pid, '\0');
	}
}

int	main(int ac, char **av)
{
	struct sigaction	s_client;

	if (ac != 3)
	{
		ft_printf("incorrect format\n");
		return (EXIT_FAILURE);
	}
	if (ft_atoi(av[1]) < 1)
	{
		write(2, "Invalid PID\n", 12);
		return (EXIT_FAILURE);
	}
	else if (kill(ft_atoi(av[1]), 0) < 0)
	{
		ft_printf("Invalid PID\n");
		return (EXIT_FAILURE);
	}
	sigemptyset(&s_client.sa_mask);
	s_client.sa_flags = SA_RESTART;
	s_client.sa_handler = client_handler;
	configure_sigaction_signals(&s_client);
	client_send_message(ft_atoi(av[1]), av[2]);
	return (EXIT_SUCCESS);
}

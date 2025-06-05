/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleal <jleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 16:40:50 by jleal             #+#    #+#             */
/*   Updated: 2025/06/05 18:44:49 by jleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"
#include "./libft/libft.h"
#include "./ft_printf/ft_printf.h"

static void	client_handler(int sig)
{
	if (sig == SIGUSR2)
	{
		printf("Message received!\n");
		exit(EXIT_SUCCESS);
	}
	
}

static void	client_send_message(int server_pid, char *str)
{
	int i;

	i = 0;
	printf("sending message length: %zu\n", ft_strlen(str));
	send_int(server_pid, ft_strlen(str));
	printf("sending message...\n");
	while (str[i] != '\0')
		send_char(server_pid, str[i++]);
	send_char(server_pid, '\0');
}

int main(int ac, char **av)
{
	struct sigaction	s_client;

	if (ac != 3)
	{
		printf("incorrect format\n");
		return (EXIT_FAILURE);
	}
	else if (kill(ft_atoi(av[1]), 0) < 0)
	{
		printf("Invalid PID\n");
		return (EXIT_FAILURE);
	}
	sigemptyset(&s_client.sa_mask);
	s_client.sa_flags = SA_RESTART;
	s_client.sa_handler = client_handler;
	configure_sigaction_signals(&s_client);
	client_send_message(ft_atoi(av[1]), av[2]);
	return(EXIT_SUCCESS);
}
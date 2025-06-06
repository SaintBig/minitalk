/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleal <jleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 16:39:12 by jleal             #+#    #+#             */
/*   Updated: 2025/06/06 17:19:25 by jleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"
#include "./libft/libft.h"
#include "./ft_printf/ft_printf.h"

static void	server_is_message_finished(
	t_protocol *t_server, size_t *i, pid_t client_pid)
{
	if (t_server->bits == 8 && t_server->flag == 1)
	{
		t_server->message[*i] = t_server->data;
		(*i)++;
		if (t_server->data == '\0')
		{
			ft_putstr("\e[92mreceived message = [");
			ft_putstr(t_server->message);
			ft_putstr("]\n\e[0m");
			free(t_server->message);
			t_server->message = NULL;
			t_server->flag = 0;
			*i = 0;
			send_bit(client_pid, 1, 0);
		}
		t_server->bits = 0;
	}
}

static void	server_is_str_length_finished(t_protocol *t_server, int size_bits)
{
	if (t_server->bits == size_bits && t_server->flag == 0)
	{
		t_server->flag = 1;
		ft_putstr("\e[92mreceived length = [");
		ft_putnbr_fd(t_server->data, STDOUT_FILENO);
		ft_putstr("]\n\e[0m");
		t_server->message = ft_calloc(t_server->data + 1, sizeof(char));
		if (t_server->message == NULL)
		{
			write(2, "error - ft_calloc\n", 18);
			exit(EXIT_FAILURE);
		}
		t_server->message[t_server->data] = '\0';
		t_server->bits = 0;
	}
}

static void	server_handler(int num, siginfo_t *info, void *context)
{
	static t_protocol	t_server;
	static size_t		i;
	int					size_bits;

	size_bits = sizeof(size_t) * 8;
	usleep(WAIT_US);
	(void)context;
	(void)info;
	if (t_server.bits == 0)
		t_server.data = 0;
	if (num == SIGUSR2 && t_server.flag == 0)
		t_server.data |= 1 << ((size_bits - 1) - t_server.bits);
	else if (num == SIGUSR2 && t_server.flag == 1)
		t_server.data |= 1 << ((CHAR_BIT - 1) - t_server.bits);
	t_server.bits++;
	server_is_str_length_finished(&t_server, size_bits);
	server_is_message_finished(&t_server, &i, info->si_pid);
	send_bit(info->si_pid, 0, 0);
}

int	main(void)
{
	struct sigaction	s_server;

	sigemptyset(&s_server.sa_mask);
	s_server.sa_sigaction = server_handler;
	s_server.sa_flags = SA_SIGINFO | SA_RESTART;
	configure_sigaction_signals(&s_server);
	ft_putstr("\e[92mserver [PID = ");
	ft_putnbr_fd(getpid(), STDOUT_FILENO);
	ft_putstr("]\n\e[0m");
	while (1)
		pause();
	return (EXIT_SUCCESS);
}

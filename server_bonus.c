/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleal <jleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 15:53:56 by jleal             #+#    #+#             */
/*   Updated: 2025/06/03 16:11:47by jleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static void	server_is_message_finished(t_protocol *t_server, int *i, pid_t client_pid)
{
	if (t_server->bits == 8 && t_server->flag == 1)
	{
		t_server->message[*i] = t_server->data;
		(*i)++;
		if (t_server->data == '\0')
		{
			printf("%s\n", t_server->message);
			free(t_server->message);\
			t_server->message = NULL;
			t_server->flag = 0;
			*i = 0;
			send_bit(client_pid, 1, 0);
		}
		t_server->bits = 0;
	}
}

static void	server_is_str_lenght_finished(t_protocol *t_server, size_t size_bits)
{
	if (t_server->bits == size_bits && t_server->flag == 0)
	{
		t_server->flag = 1;
		printf("server received length: %zu\n", t_server->data);
		t_server->message == ft_calloc(t_server->data + 1, sizeof(char));
		if (t_server->message == NULL)
		{
			write(2, "error - ft_calloc\n", 18);
			exit(EXIT_FAILURE);
		}
		t_server->message[t_server->data] = '0';
		t_server->bits = 0;
	}
}

static void	server_handler(int num, siginfo_t *info, void *context)
{
	static t_protocol	t_server;
	static size_t		i;
	size_t				size_bits;

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
	printf("Server PID = %d\n", getpid());
	while(1)
		pause();
	return (EXIT_SUCCESS);
}
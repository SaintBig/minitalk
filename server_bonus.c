/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleal <jleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 10:44:03 by jleal             #+#    #+#             */
/*   Updated: 2025/06/03 11:46:31 by jleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	char_handler(int sig, siginfo_t *info, char *str, pid_t client)
{
	static char		c = 0;
	static int		bit = 0;
	static int		i = 0;

	if (SIGUSR1 == sig)
		c |= (0x80 >> bit);
	else if (SIGUSR2 == sig)
		c &= ~(0x80 >> bit);
	bit++;
	if (CHAR_BIT == bit)
	{
		bit = 0;
		if ('\0' == c)
		{
			i++;
			write(1, str, i);
			ft_kill(client, SIGUSR2);
			c = 0;
			return ;
		}
		str[i++] = c;
		c = 0;
	}
	ft_kill(client, SIGUSR1);
}

static size_t	size_handler(int sig, siginfo_t *info)
{
	static size_t	len = 0;
	static int		bit = 0;
	static pid_t	client = 0;
	static int		total_bits = sizeof(size_t) * 8;

	if (info->si_pid)
		client = info->si_pid;
	if (SIGUSR1 == sig)
		len |= ((size_t)1 << (total_bits - 1 - bit));
	else if (SIGUSR2 == sig)
		len &= ~((size_t)1 << (total_bits - 1 - bit));
	bit++;
	if (sizeof(size_t) * 8 == bit)
		return (len);
	else
	{
		ft_kill(client, SIGUSR1);
		return (0);
	}
}

static void	handler(int sig, siginfo_t *info)
{
	static char		*str = NULL;
	static size_t	len = 0;
	static int		i = 0;
	static pid_t	client;

	if (info->si_pid)
		client = info->si_pid;
	if (i++ < sizeof(size_t) * 8)
	{
		len = size_handler(sig, info);
		if (len)
		{
			str = malloc(len);
			if (!str)
			{
				write(2, "failed to allocate memory for string\n", 37);
				return (EXIT_FAILURE);
			}
			str[len - 1] = '\0';
			ft_kill(client, SIGUSR1);
		}
	}
	else
		char_handler(sig, info, str, client);
}

int	main(int ac, char **av)
{
	if (ac != 1 || !av)
	{
		write(2, "No arguments!", 13);
		return (EXIT_FAILURE);
	}
	write(1, "Server PID: ", 12);
	ft_putnbr(getpid());
	write(1, "\n", 1);
	ft_signal(SIGUSR1, handler, 1);
	ft_signal(SIGUSR2, handler, 1);
	while (1)
		pause();
	return (EXIT_SUCCESS);
}

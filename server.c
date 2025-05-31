/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleal <jleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 17:48:24 by jleal             #+#    #+#             */
/*   Updated: 2025/05/31 19:02:10 by jleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	handler(int sig, siginfo_t *info, void *more_info)
{
	static char		c = 0;
	static int		bit = 0;
	static pid_t	client = 0;

	(void)more_info;
	if (info->si_pid)
		client = info->si_pid;
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
			write(STDOUT_FILENO, "\n", 1);
			ft_kill(client, SIGUSR2);
			c = 0;
			return ;
		}
		write(STDOUT_FILENO, &c, 1);
		c = 0;
	}
	ft_kill(client, SIGUSR1);
}

int main(int ac, char **av)
{
	if (ac != 1 || !av)
	{
		write(2, "No arguments!", 14);
		return (EXIT_FAILURE);
	}
	printf("Server PID: %d\n", getpid());
	ft_signal(SIGUSR1, handler, 1);
	ft_signal(SIGUSR2, handler, 1);
	while (1)
		pause();
	return(EXIT_SUCCESS);
}

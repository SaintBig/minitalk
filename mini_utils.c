/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleal <jleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 16:41:01 by jleal             #+#    #+#             */
/*   Updated: 2025/06/02 16:50:59 by jleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_signal(int sig, void *handler, int use_siginfo)
{
	struct sigaction	sa;

	ft_memset(&sa, 0, sizeof(sa));
	if (use_siginfo)
	{
		sa.sa_sigaction = handler;
		sa.sa_flags = SA_SIGINFO;
	}
	else
		sa.sa_handler = handler;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	if (sigaction(sig, &sa, NULL) < 0)
	{
		write(2, "Signal handler setup failed", 27);
		exit(EXIT_FAILURE);
	}
}

void	ft_kill(pid_t pid, int signum)
{
	if (kill(pid, signum) < 0)
	{
		write(2, "Signal transmission failed\n", 27);
		exit(EXIT_FAILURE);
	}
}

int	ft_atoi(const char *str)
{
	int	tot;
	int	p;
	int	i;

	tot = 0;
	p = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' && str[i + 1] != '-')
		i++;
	if (str[i] == '-')
	{
		p = -1;
		i++;
	}
	while (str[i] >= '0' || str[i] <= '9')
	{
		tot = (tot * 10) + str[i] - '0';
		i++;
	}
	return (tot * p);
}

void	ft_putnbr(int n)
{
	char	c;

	if (n == -2147483648)
		write(1, "-2147483648", 12);
	else if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
		ft_putnbr(n);
	}
	else if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
	{
		c = (n + '0');
		write(1, &c, 1);
	}
}

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*tmp_ptr;

	tmp_ptr = (unsigned char *)b;
	while (len-- > 0)
		*(tmp_ptr++) = (unsigned char)c;
	return (b);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleal <jleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 17:20:12 by jleal             #+#    #+#             */
/*   Updated: 2025/06/02 16:47:40 by jleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# define _GNU_SOURCE

//# include <errno.h>
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <limits.h>
# include <sys/types.h>
# include <sys/signal.h>

# define BUSY 0
# define READY 1

void	ft_signal(int sig, void *handler, int use_siginfo);

void	ft_kill(pid_t pid, int signum);

int		ft_atoi(const char *str);

void	ft_putnbr(int n);

void	*ft_memset(void *b, int c, size_t len);

#endif

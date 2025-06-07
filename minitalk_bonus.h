/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleal <jleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 16:40:52 by jleal             #+#    #+#             */
/*   Updated: 2025/06/07 19:16:34 by jleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H
# define _GNU_SOURCE

# define WAIT_US  100

# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <limits.h>
# include <sys/types.h>
# include <sys/signal.h>
# include "./libft/libft.h"
# include "./ft_printf/ft_printf.h"

void	configure_sigaction_signals(struct sigaction *sa);

void	send_int(pid_t pid, int num);

void	send_char(pid_t pid, char c);

void	send_bit(pid_t pid, char bit, char flag_to_pause);

void	ft_putstr(char *s);

typedef struct s_protocol
{
	int		bits;
	size_t	data;
	int		flag;
	char	*message;
}			t_protocol;

#endif
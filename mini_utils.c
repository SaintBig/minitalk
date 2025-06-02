/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleal <jleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 18:03:07 by jleal             #+#    #+#             */
/*   Updated: 2025/05/31 18:05:59by jleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_signal(int sig, void *handler, int use_siginfo)
{
	struct sigaction	sa = {0};

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
		write(2, "Signal handler setup failed", 28);
		exit(EXIT_FAILURE);
	}
}

void	ft_kill(pid_t pid, int signum)
{
	if (kill(pid, signum) < 0)
	{
		write(2, "Signal transmission failed", 27);
		exit(EXIT_FAILURE);
	}
}

/* void print_pending_signals()
{
    sigset_t pending;
    if (sigpending(&pending) == -1) {
        perror("sigpending");
        exit(EXIT_FAILURE);
    }

    printf("\n=== Pending Signals ===\n");
    for (int i = 1; i < NSIG; i++) {
        if (sigismember(&pending, i)) {
            printf("Signal %d (%s) is pending\n", i, strsignal(i));
        }
    }
    printf("=======================\n\n");
}

void print_blocked_signals()
{
    sigset_t blocked;
    if (sigprocmask(SIG_BLOCK, NULL, &blocked) == -1) {
        perror("sigprocmask");
        exit(EXIT_FAILURE);
    }

    printf("\n=== Blocked Signals ===\n");
    for (int i = 1; i < NSIG; i++) {
        if (sigismember(&blocked, i)) {
            printf("Signal %d (%s) is blocked\n", i, strsignal(i));
        }
    }
    printf("=======================\n");
} */

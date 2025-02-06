/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdargui <hdargui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:27:11 by hdargui           #+#    #+#             */
/*   Updated: 2025/02/06 17:05:21 by hdargui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"
#include <signal.h>
#include <stdio.h>
#include <sys/signal.h>
#include <unistd.h>

t_help	g_heho;

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
		ft_putchar(n + '0');
}

void	handler(int n, siginfo_t *info, void *context)
{
	int	ascii;
	int	power_of_two;
	int	i;

	(void)context;
	g_heho.bit_array[g_heho.bit_count] = n - 30;
	g_heho.bit_count++;
	ascii = 0;
	if (g_heho.bit_count == 8)
	{
		power_of_two = 1;
		i = 7;
		while (i >= 0)
		{
			ascii += g_heho.bit_array[i] * power_of_two;
			power_of_two *= 2;
			i--;
		}
		write(1, &ascii, 1);
		g_heho.bit_count = 0;
	}
	if (ascii == 10)
	{
		kill(info->si_pid, SIGUSR1);
	}
}

int	main(void)
{
	struct sigaction x;

	g_heho.bit_count = 0;
	x.sa_sigaction = handler;
	x.sa_flags = SA_SIGINFO;
	sigemptyset(&x.sa_mask);
	sigaction(SIGUSR1, &x, NULL);
	sigaction(SIGUSR2, &x, NULL);
	write(1, "Server running with PID:", 27);
	ft_putnbr(getpid());
	ft_putchar('\n');
	while (1)
	{
		pause();
	}
	return (0);
}
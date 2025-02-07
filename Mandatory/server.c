/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdargui <hdargui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:27:11 by hdargui           #+#    #+#             */
/*   Updated: 2025/02/07 17:43:34 by hdargui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>
#include <sys/_types/_pid_t.h>
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

void	handler(int n)
{

	int	ascii;
	int	power_of_two;
	int	i;

	g_heho.bit_array[g_heho.bit_count] = n - 30;
	g_heho.bit_count++;
	if (g_heho.bit_count == 8)
	{
		ascii = 0;
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
}

int	main(void)
{
	struct sigaction	x;

	g_heho.bit_count = 0;
	x.sa_handler = handler;
	x.sa_flags = 0;
	sigemptyset(&x.sa_mask);
	sigaction(SIGUSR1, &x, NULL);
	sigaction(SIGUSR2, &x, NULL);
	write(1, "Server running with PID: ", 28);
	ft_putnbr(getpid());
	ft_putchar('\n');
	while (1)
	{
		pause();
	}
	return (0);
}

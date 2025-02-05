/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdargui <hdargui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:27:11 by hdargui           #+#    #+#             */
/*   Updated: 2025/02/05 17:23:41 by hdargui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>
#include <unistd.h>

t_help	g_heho;

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
		if (ascii == '\0')
		{
			write(1, "\n", 1);
		}
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
	ft_printf("Server running with PID: %d\n", getpid());
	while (1)
	{
		pause();
	}
	return (0);
}

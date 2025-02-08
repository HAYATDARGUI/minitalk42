/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdargui <hdargui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:27:05 by hdargui           #+#    #+#             */
/*   Updated: 2025/02/08 13:02:43 by hdargui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	helpfuction(unsigned char crchar, int power_of_two, pid_t server_pid)
{
	int	j;

	j = 7;
	while (j >= 0)
	{
		if (crchar / power_of_two >= 1)
		{
			kill(server_pid, SIGUSR2);
			crchar -= power_of_two;
		}
		else
			kill(server_pid, SIGUSR1);
		usleep(100);
		power_of_two /= 2;
		j--;
	}
}

void	send_message(pid_t server_pid, const char *message)
{
	int				i;
	unsigned char	encrypted_char;
	int				power_of_two;

	power_of_two = 128;
	i = 0;
	while (message[i] != '\0')
	{
		encrypted_char = message[i];
		helpfuction(encrypted_char, power_of_two, server_pid);
		i++;
	}
	encrypted_char = '\n';
	helpfuction(encrypted_char, power_of_two, server_pid);
}

void	handler1(int n)
{
	(void)n;
	write(1, "message reseved ✅\n", 21);
	exit(0);
}

int	main(int arc, char **arv)
{
	pid_t				pid;
	struct sigaction	s;
	sigset_t			block_mask;

	s.sa_handler = handler1;
	sigemptyset(&s.sa_mask);
	s.sa_flags = 0;
	sigaction(SIGUSR1, &s, NULL);
	sigfillset(&block_mask);
	sigdelset(&block_mask, SIGUSR1);
	sigdelset(&block_mask, SIGUSR2);
	sigprocmask(SIG_SETMASK, &block_mask, NULL);
	if (arc != 3)
	{
		write(2, "error\n", 7);
		return (1);
	}
	pid = atoi(arv[1]);
	send_message(pid, arv[2]);
	while (1)
		pause();
	return (0);
}

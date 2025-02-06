/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdargui <hdargui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:27:05 by hdargui           #+#    #+#             */
/*   Updated: 2025/02/06 17:50:35 by hdargui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minitalk.h"

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

int	main(int arc, char **arv)
{
	pid_t		pid;
	const char	*message = arv[2];

	if (arc != 3)
	{
		write(2, "error\n",6);
		return 1;
	}
	pid = atoi(arv[1]);
	send_message(pid, message);
	return (0);
}

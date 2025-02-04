/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdargui <hdargui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:27:05 by hdargui           #+#    #+#             */
/*   Updated: 2025/02/04 15:32:49 by hdargui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "printf/ft_printf.h"
#include <signal.h>
#include <sys/_types/_pid_t.h>
#include <unistd.h>
#include <stdlib.h>

void send_message(pid_t server_pid, const char *message) {
    int i = 0;
    while (message[i] != '\0') {
        unsigned char encrypted_char = message[i];
        int j = 7;
        while (j >= 0) {
            if (encrypted_char & (1 << j)) {
                kill(server_pid, SIGUSR1);
            } else {
                kill(server_pid, SIGUSR2);
            }
            usleep(100); 
            j--;
        }
        i++;
    }
}

int main(int arc,char **arv)
{

    if(arc!=3)
    {
        ft_printf("error");
    }
    pid_t pid=atoi(arv[1]);

    const char *message = arv[2];

    send_message(pid, message);

    return 0;
}
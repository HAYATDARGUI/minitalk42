/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdargui <hdargui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:27:11 by hdargui           #+#    #+#             */
/*   Updated: 2025/02/04 13:51:05 by hdargui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_help heho;

void handler(int n)
{
   
    heho.bit_array[heho.bit_count] = n-30;

    heho.bit_count++;

    if (heho.bit_count == 8) {
        int ascii = 0;
        int power_of_two = 1;
        int i = 7;

        while (i >= 0) {
            ascii += heho.bit_array[i] * power_of_two;
            power_of_two *= 2;
            i--;
        }
        write(1,&ascii,1);
       
       heho.bit_count = 0; 
    }
}

int main()
{
    struct sigaction x;
    heho.bit_count=0;
    x.sa_handler = handler;
    x.sa_flags = 0;
    sigemptyset(&x.sa_mask);

    sigaction(SIGUSR1, &x, NULL); 
    sigaction(SIGUSR2, &x, NULL);  

    ft_printf("Server running with PID: %d\n", getpid());

    while (1) {
        pause();  
    }
    return 0;
}

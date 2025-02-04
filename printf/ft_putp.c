/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdargui <hdargui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:16:18 by hdargui           #+#    #+#             */
/*   Updated: 2024/11/20 13:28:30 by hdargui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	converttohex(unsigned long num, int *len)
{
	char	hex[16];
	int		i;
	int		r;

	i = 0;
	if (num == 0)
		ft_putchar('0', len);
	while (num != 0)
	{
		r = num % 16;
		if (r < 10)
			hex[i] = r + '0';
		else
			hex[i] = r - 10 + 'a';
		i++;
		num = num / 16;
	}
	while (i > 0)
	{
		i--;
		ft_putchar(hex[i], len);
	}
}

void	ft_putp(unsigned long p, int *len)
{
	unsigned long	n;

	n = (unsigned long)p;
	ft_putchar('0', len);
	ft_putchar('x', len);
	converttohex(n, len);
}

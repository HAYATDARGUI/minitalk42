/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdargui <hdargui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 11:52:55 by hdargui           #+#    #+#             */
/*   Updated: 2024/11/21 13:59:59 by hdargui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	converttohexa(unsigned int num, int *len)
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
	hex[i] = '\0';
	while (i > 0)
	{
		i--;
		ft_putchar(hex[i], len);
	}
}

static void	converttohexaup(unsigned int num, int *len)
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
			hex[i] = r - 10 + 'A';
		i++;
		num = num / 16;
	}
	hex[i] = '\0';
	while (i > 0)
	{
		i--;
		ft_putchar(hex[i], len);
	}
}

void	ft_puthexa(unsigned int num, char format, int *len)
{
	if (format == 'x')
	{
		converttohexa(num, len);
	}
	else
	{
		converttohexaup(num, len);
	}
}

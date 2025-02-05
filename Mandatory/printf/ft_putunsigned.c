/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdargui <hdargui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 11:10:21 by hdargui           #+#    #+#             */
/*   Updated: 2024/11/20 11:54:34 by hdargui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putunsigned(unsigned int n, int *len)
{
	if (n > 9)
	{
		ft_putunsigned(n / 10, len);
		ft_putunsigned(n % 10, len);
	}
	else
		ft_putchar(n + '0', len);
}

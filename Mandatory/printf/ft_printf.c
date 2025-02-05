/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdargui <hdargui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 11:08:00 by hdargui           #+#    #+#             */
/*   Updated: 2024/11/20 15:08:02 by hdargui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_write(char c, va_list args, int *len)
{
	if (c == 'c')
		ft_putchar(va_arg(args, int), len);
	else if (c == 's')
		ft_putstr(va_arg(args, char *), len);
	else if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(args, int), len);
	else if (c == 'u')
		ft_putunsigned(va_arg(args, unsigned int), len);
	else if (c == 'X' || c == 'x')
		ft_puthexa(va_arg(args, unsigned int), c, len);
	else if (c == 'p')
	{
		ft_putp(va_arg(args, unsigned long), len);
	}
	else if (c == '%')
		ft_putchar('%', len);
	else
		ft_putchar(c, len);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		len;
	va_list	args;

	i = 0;
	len = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			ft_write(format[i], args, &len);
		}
		else
		{
			ft_putchar(format[i], &len);
		}
		i++;
	}
	va_end(args);
	return (len);
}

// int main()
// {
// 	int d = ft_printf("%x\n", 42);
// 	printf("d = %d\n", d);
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkocakur <kkocakur@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 16:02:26 by kkocakur          #+#    #+#             */
/*   Updated: 2025/07/18 16:06:37 by kkocakur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_format(va_list args, char format, int *len)
{
	if (format == 'c')
		return (ft_putchar(va_arg(args, int), len));
	else if (format == 's')
		return (ft_putstr(va_arg(args, char *), len));
	else if (format == 'p')
    	return (ft_putptr((unsigned long long)va_arg(args, void *), len));
	else if (format == 'd' || format == 'i')
		return (ft_putnbr(va_arg(args, int), len));
	else if (format == 'u')
		return (ft_putunbr(va_arg(args, unsigned int), len));
	else if (format == 'x' || format == 'X')
		return (ft_puthex(va_arg(args, unsigned int), format, len));
	else if (format == '%')
		return (ft_putchar('%', len));
		
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	va_start(args, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			ft_format(args, format[++i], &count);
		}
		else
			ft_putchar(format[i], &count);
		i++;
	}
	va_end(args);
	return (count);
}

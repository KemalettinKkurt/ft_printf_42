/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkocakur <kkocakur@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 18:33:03 by kkocakur          #+#    #+#             */
/*   Updated: 2025/07/23 05:42:46 by kkocakur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c, int *len)
{
    if (write(1, &c, 1) == -1)
        return (-1);
    (*len)++;
    return (1);
}

int	ft_putstr(char *s, int *len)
{
	int	prev;

	if (!s)
		return (ft_putstr("(null)", len));
	prev = *len;
	while (*s)
		ft_putchar(*s++, len);
	return (*len - prev);
}

int	ft_putnbr(int n, int *len)
{
	long	nb;
	int		count;

	nb = n;
	count = 0;
	if (nb < 0)
	{
		count += ft_putchar('-', len);
		nb *= -1;
	}
	if (nb >= 10)
		count += ft_putnbr(nb / 10, len);
	count += ft_putchar(nb % 10 + '0', len);
	return (count);
}

int	ft_putunbr(unsigned int n, int *len)
{
	int	count;

	count = 0;
	if (n >= 10)
		count += ft_putunbr(n / 10, len);
	count += ft_putchar(n % 10 + '0', len);
	return (count);
}

int	ft_puthex(unsigned int n, const char format, int *len)
{
	char	*hex;
	int		count;

	if (format == 'x')
		hex = "0123456789abcdef";
	else
		hex = "0123456789ABCDEF";
	count = 0;
	if (n >= 16)
		count += ft_puthex(n / 16, format, len);
	count += ft_putchar(hex[n % 16], len);
	return (count);
}

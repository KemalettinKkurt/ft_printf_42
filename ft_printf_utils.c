/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkocakur <kkocakur@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 18:33:03 by kkocakur          #+#    #+#             */
/*   Updated: 2025/07/18 15:29:39 by kkocakur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c, int *len)
{
	write(1, &c, 1);
	(*len)++;
	return (1);
}

int	ft_putstr(char *s, int *len)
{
	int	i;

	if (!s)
		return (ft_putstr("(null)", len));
	i = 0;
	while (s[i])
	{
		ft_putchar(s[i], len);
		i++;
	}
	return (i);
}

int	ft_putnbr(int n, int *len)
{
	int		count;
	long	nb;

	count = 0;
	nb = n;
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

	count = 0;
	hex = (format == 'x') ? "0123456789abcdef" : "0123456789ABCDEF";
	if (n >= 16)
		count += ft_puthex(n / 16, format, len);
	count += ft_putchar(hex[n % 16], len);
	return (count);
}

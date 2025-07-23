/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkocakur <kkocakur@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 06:33:56 by kkocakur          #+#    #+#             */
/*   Updated: 2025/07/23 05:24:20 by kkocakur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_ptrlen(unsigned long long ptr)
{
	int	len;

	len = 0;
	if (ptr == 0)
		return (1);
	while (ptr)
	{
		ptr /= 16;
		len++;
	}
	return (len);
}

static void	ft_putptr_rec(unsigned long long ptr, int *len)
{
	const char	*hex = "0123456789abcdef";

	if (ptr >= 16)
		ft_putptr_rec(ptr / 16, len);
	ft_putchar(hex[ptr % 16], len);
}

int	ft_putptr(unsigned long long ptr, int *len)
{
	int	count;

	if (!ptr)
		return (ft_putstr("(nil)", len));
	count = ft_putstr("0x", len);
	ft_putptr_rec(ptr, len);
	count += ft_ptrlen(ptr);
	return (count);
}

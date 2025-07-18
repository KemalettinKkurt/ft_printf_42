/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkocakur <kkocakur@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 06:33:56 by kkocakur          #+#    #+#             */
/*   Updated: 2025/07/18 16:02:18 by kkocakur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putptr_rec(unsigned long long ptr, int *len)
{
	char *hex = "0123456789abcdef";

	if (ptr >= 16)
		ft_putptr_rec(ptr / 16, len);
	ft_putchar(hex[ptr % 16], len);
}

int	ft_putptr(unsigned long long ptr, int *len)
{
	if (!ptr)
	{
		ft_putstr("(nil)", len);
		return (*len);
	}
	ft_putstr("0x", len);
	ft_putptr_rec(ptr, len);
	return (*len);
}

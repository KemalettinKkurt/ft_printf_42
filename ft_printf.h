/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkocakur <kkocakur@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 04:06:52 by kkocakur          #+#    #+#             */
/*   Updated: 2025/07/18 15:23:13 by kkocakur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
#include <stdio.h>

int		ft_printf(const char *format, ...);
int	ft_putchar(char c, int *len);
int		ft_putstr(char *s, int *len);
int		ft_putnbr(int n, int *len);
int		ft_putunbr(unsigned int n, int *len);
int		ft_puthex(unsigned int n, const char format, int *len);
int		ft_putptr(unsigned long long ptr, int *len);

#endif

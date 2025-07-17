/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkocakur <kkocakur@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 18:33:03 by kkocakur          #+#    #+#             */
/*   Updated: 2025/07/17 16:34:01 by kkocakur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "printf.h"
#include <stdio.h>

int print_char(char x)
{
    return (write(1, &x, 1));
}

int print_str(char *x)
{
    int i;
    i = 0;

    if (!x)
    {
        x = NULL;
    }
    
    while (x[i] != '\0')
    {
        write(1, &x[i], 1);
        i++;
    }
    return i;
}

int print_int(int x)
{
    	if (x == -2147483648)
	{
		print_char('-');
		print_char('2');
		x = 147483648;
	}
	if (x < 0)
	{
		print_char('-');
		x = -x;
	}
	if (x >= 10)
		print_int(x / 10);
	print_char(x % 10 + '0');
    
    return ft_strlen(x);
}


int main()
{
    printf("%d\n\n", print_int(1234567899));
    return 0;
}
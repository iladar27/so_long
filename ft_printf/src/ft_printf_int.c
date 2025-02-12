/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilgaynet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:21:12 by ilgaynet          #+#    #+#             */
/*   Updated: 2024/11/13 14:47:54 by ilgaynet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_printf_int(int num)
{
	char	digit;
	int		count;

	count = 0;
	if (num == INT_MIN)
	{
		ft_printf_char('-');
		ft_printf_char('2');
		num = 147483648;
		count += 2;
	}
	if (num < 0)
	{
		ft_printf_char('-');
		num = -num;
		count++;
	}
	if (num >= 10)
	{
		count += ft_printf_int(num / 10);
	}
	digit = (num % 10) + '0';
	ft_printf_char(digit);
	count++;
	return (count);
}

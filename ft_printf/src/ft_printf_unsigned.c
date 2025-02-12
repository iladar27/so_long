/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilgaynet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:48:28 by ilgaynet          #+#    #+#             */
/*   Updated: 2024/11/12 13:09:34 by ilgaynet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_printf_unsigned(unsigned int num)
{
	char	digit;
	int		count;

	count = 0;
	if (num >= 10)
	{
		count += ft_printf_unsigned(num / 10);
	}
	digit = (num % 10) + '0';
	ft_printf_char(digit);
	count++;
	return (count);
}

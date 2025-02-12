/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilgaynet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:58:23 by ilgaynet          #+#    #+#             */
/*   Updated: 2024/11/13 14:49:13 by ilgaynet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char	*ft_make_str(unsigned long value, int *strlen)
{
	int				count;
	unsigned long	temp;
	char			*str;

	count = 0;
	temp = value;
	while (temp != 0)
	{
		temp /= 16;
		count++;
	}
	str = (char *)malloc(sizeof(char) * (count + 1));
	if (!str)
		return (0);
	str[count] = '\0';
	*strlen = count;
	return (str);
}

int	ft_printf_hex(unsigned long value, int asc)
{
	int				count;
	int				countreturn;
	unsigned long	tl;
	char			*strout;

	if (value == 0)
		return (ft_printf_char('0'));
	count = 0;
	strout = ft_make_str(value, &count);
	tl = value;
	countreturn = count;
	if (!strout)
		return (0);
	while (tl != 0 && count > 0)
	{
		count--;
		if ((tl % 16) < 10)
			strout[count] = (tl % 16) + 48;
		else
			strout[count] = (tl % 16) + asc;
		tl /= 16;
	}
	ft_printf_str(strout);
	free(strout);
	return (countreturn);
}

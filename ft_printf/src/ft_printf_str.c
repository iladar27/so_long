/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilgaynet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 13:43:29 by ilgaynet          #+#    #+#             */
/*   Updated: 2024/11/08 14:08:09 by ilgaynet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_printf_str(const char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		ft_printf_str("(null)");
		return (6);
	}
	while (str[i] != '\0')
	{
		ft_printf_char(str[i]);
		i++;
	}
	return (i);
}

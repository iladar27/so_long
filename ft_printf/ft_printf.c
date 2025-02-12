/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilgaynet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:19:31 by ilgaynet          #+#    #+#             */
/*   Updated: 2024/11/13 14:55:41 by ilgaynet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int	check_format(const char *format, va_list args)
{
	int	count;

	count = 0;
	if (*format == 'c')
		count += ft_printf_char((char)va_arg(args, int));
	else if (*format == 's')
		count += ft_printf_str(va_arg(args, char *));
	else if (*format == 'p')
		count += ft_printf_pointer(va_arg(args, void *));
	else if (*format == 'd' || *format == 'i')
		count += ft_printf_int(va_arg(args, int));
	else if (*format == 'u')
		count += ft_printf_unsigned(va_arg(args, unsigned int));
	else if (*format == 'x')
		count += ft_printf_hex(va_arg(args, unsigned int), 87);
	else if (*format == 'X')
		count += ft_printf_hex(va_arg(args, unsigned int), 55);
	else if (*format == '%')
		count += write(1, "%", 1);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		count;
	va_list	args;

	if (!format)
		return (0);
	va_start(args, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format)
				count += check_format(format, args);
		}
		else
			count += write(1, format, 1);
		format++;
	}
	va_end(args);
	return (count);
}

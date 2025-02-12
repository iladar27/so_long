/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilgaynet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:24:22 by ilgaynet          #+#    #+#             */
/*   Updated: 2024/11/12 13:24:28 by ilgaynet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h> 
# include <stdint.h>

int	ft_printf(const char *format, ...);
int	ft_printf_char(char c);
int	ft_printf_str(const char *str);
int	ft_printf_pointer(void *ptr_addr);
int	ft_printf_int(int n);
int	ft_printf_unsigned(unsigned int num);
int	ft_printf_hex(unsigned long value, int asc);

#endif

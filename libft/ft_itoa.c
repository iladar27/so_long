/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilgaynet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 13:15:27 by ilgaynet          #+#    #+#             */
/*   Updated: 2024/11/01 16:05:53 by ilgaynet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_len(int num)
{
	size_t		number_of_len;

	number_of_len = 0;
	if (num == 0)
		return (1);
	while (num != 0)
	{
		num /= 10;
		number_of_len++;
	}
	return (number_of_len);
}

char	*ft_itoa(int n)
{
	char		*str;
	size_t		len;
	long int	num;

	num = n;
	len = get_len(num);
	if (n < 0)
	{
		num *= -1;
		len++;
	}
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	*(str + len) = '\0';
	while (len--)
	{
		*(str + len) = num % 10 + '0';
		num /= 10;
	}
	if (n < 0)
		*(str) = '-';
	return (str);
}

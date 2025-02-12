/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilgaynet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 13:53:53 by ilgaynet          #+#    #+#             */
/*   Updated: 2024/10/31 14:56:01 by ilgaynet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*str;

	if (n > 0)
	{
		i = 0;
		str = (char *)s;
		while (i < n)
		{
			if ((unsigned char)str[i] == (unsigned char)c)
				return ((char *)s + i);
			i++;
		}
	}
	return (NULL);
}

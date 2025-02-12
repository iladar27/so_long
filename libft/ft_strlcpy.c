/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilgaynet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 13:23:52 by ilgaynet          #+#    #+#             */
/*   Updated: 2024/10/26 14:15:23 by ilgaynet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	k;

	i = 0;
	while (src[i] != '\0')
		i++;
	if (dstsize > 0)
	{
		k = 0;
		while (k < dstsize - 1 && src[k] != '\0')
		{
			dst[k] = src[k];
			k++;
		}
		dst[k] = '\0';
	}
	return (i);
}

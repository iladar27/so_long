/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilgaynet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 13:45:03 by ilgaynet          #+#    #+#             */
/*   Updated: 2024/10/26 14:14:49 by ilgaynet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	d;
	size_t	s;
	size_t	i;

	s = 0;
	while (src[s] != '\0')
		s++;
	d = 0;
	while (dst[d] != '\0' && d < dstsize)
		d++;
	if (dstsize <= d)
		return (dstsize + s);
	i = 0;
	while (src[i] != '\0' && (d + i) < dstsize - 1)
	{
		dst[d + i] = src[i];
		i++;
	}
	dst[d + i] = '\0';
	return (d + s);
}

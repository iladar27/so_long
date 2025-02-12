/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilgaynet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:56:24 by ilgaynet          #+#    #+#             */
/*   Updated: 2024/10/31 15:11:28 by ilgaynet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*dest;
	size_t	size;

	size = ft_strlen(src);
	dest = (char *)malloc((size + 1) * (sizeof(char)));
	if (dest == NULL)
		return (NULL);
	ft_memcpy(dest, src, size);
	dest[size] = '\0';
	return (dest);
}

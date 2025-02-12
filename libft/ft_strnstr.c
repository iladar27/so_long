/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilgaynet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 15:02:40 by ilgaynet          #+#    #+#             */
/*   Updated: 2024/10/28 13:38:51 by ilgaynet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;
	size_t	s;

	if (s2[0] == '\0')
		return ((char *)s1);
	if (len == 0)
		return (NULL);
	i = 0;
	while (i < len && s1[i] != '\0')
	{
		s = 0;
		while (s1[i + s] == s2[s] && (i + s) < len && s2[s] != '\0')
			s++;
		if (s2[s] == '\0')
			return ((char *)s1 + i);
		i++;
	}
	return (NULL);
}

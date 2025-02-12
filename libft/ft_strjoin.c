/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilgaynet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:47:25 by ilgaynet          #+#    #+#             */
/*   Updated: 2024/10/28 13:56:30 by ilgaynet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	si1;
	size_t	si2;
	char	*s3;

	if (!s1 || !s2)
		return (NULL);
	si1 = ft_strlen(s1);
	si2 = ft_strlen(s2);
	s3 = (char *)malloc(si1 + si2 + 1);
	if (!s3)
		return (0);
	ft_strlcpy(s3, s1, si1 + 1);
	ft_strlcpy(s3 + si1, s2, si2 + 1);
	return (s3);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_2d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilgaynet <ilgaynet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 11:57:19 by ilgaynet          #+#    #+#             */
/*   Updated: 2025/02/10 12:09:15 by ilgaynet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

char	**ft_strdup_2d(char **src)
{
	char	**dst;
	int		i;

	if (!src)
		return (NULL);
	i = 0;
	while (src[i])
		i++;
	dst = (char **)ft_calloc(i + 1, sizeof(char *));
	if (!dst)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dst[i] = ft_strdup(src[i]);
		if (!dst[i])
		{
			while (i > 0)
				free(dst[--i]);
			free(dst);
			return (NULL);
		}
		i++;
	}
	return (dst);
}

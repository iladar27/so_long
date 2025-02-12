/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilgaynet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:13:48 by ilgaynet          #+#    #+#             */
/*   Updated: 2024/10/31 15:14:44 by ilgaynet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	words_counts(const char *s, char c)
{
	int	counts;
	int	iw;

	counts = 0;
	iw = 0;
	while (*s)
	{
		if (*s != c && !iw)
		{
			iw = 1;
			counts++;
		}
		else if (*s == c)
		{
			iw = 0;
		}
		s++;
	}
	return (counts);
}

char	*get_next(const char **s, char c)
{
	const char	*start;
	size_t		len;

	while (**s && **s == c)
		(*s)++;
	start = *s;
	while (**s && **s != c)
		(*s)++;
	len = *s - start;
	return (ft_substr(start, 0, len));
}

void	free_all(char **res, int count)
{
	int		i;

	i = 0;
	while (i < count)
	{
		free(res[i]);
		i++;
	}
	free(res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	char	*word;
	int		word_count;
	int		i;

	if (!s)
		return (NULL);
	word_count = words_counts(s, c);
	res = (char **)malloc((word_count + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	i = 0;
	while (i < word_count)
	{
		word = get_next(&s, c);
		if (!word)
		{
			free_all(res, i);
			return (NULL);
		}
		res[i++] = word;
	}
	res[i] = NULL;
	return (res);
}

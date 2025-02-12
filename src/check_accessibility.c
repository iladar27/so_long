/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_accessibility.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilgaynet <ilgaynet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 19:00:00 by ilgaynet          #+#    #+#             */
/*   Updated: 2025/02/12 11:27:45 by ilgaynet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

static int	is_valid_move(char **map, int x, int y)
{
	if (!map || !map[y] || map[y][x] == '\0')
		return (0);
	return (map[y][x] != '1' && map[y][x] != 'V');
}

static void	flood_fill(char **map, int x, int y, int *collectibles)
{
	if (!is_valid_move(map, x, y))
		return ;
	if (map[y][x] == 'C')
		(*collectibles)--;
	if (map[y][x] == 'E')
		map[y][x] = 'e';
	else
		map[y][x] = 'V';
	flood_fill(map, x + 1, y, collectibles);
	flood_fill(map, x - 1, y, collectibles);
	flood_fill(map, x, y + 1, collectibles);
	flood_fill(map, x, y - 1, collectibles);
}

static int	find_start(char **map, int *start_x, int *start_y)
{
	int	y;
	int	x;

	y = 0;
	while (map && map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
			{
				*start_x = x;
				*start_y = y;
				return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

static int	check_accessibility_helper(char **map)
{
	int	y;
	int	x;

	y = 0;
	while (map && map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'C' || map[y][x] == 'E')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int	check_accessibility(char **map, int collectible_count)
{
	int		start_x;
	int		start_y;
	int		collectibles;
	char	**map_copy;
	int		result;

	if (!map)
		return (0);
	collectibles = collectible_count;
	if (!find_start(map, &start_x, &start_y))
		return (0);
	map_copy = ft_strdup_2d(map);
	if (!map_copy)
		return (0);
	flood_fill(map_copy, start_x, start_y, &collectibles);
	result = check_accessibility_helper(map_copy);
	free_map(map_copy);
	return (result && collectibles == 0);
}

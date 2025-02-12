/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilgaynet <ilgaynet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 12:48:59 by ilgaynet          #+#    #+#             */
/*   Updated: 2025/02/12 11:49:02 by ilgaynet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

static int	verify_map_conditions(int name_problem, t_data *data)
{
	static int	exit_count = 0;
	static int	start_count = 0;

	if (name_problem == 1)
		exit_count++;
	else if (name_problem == 2)
		start_count++;
	else if (name_problem == 3)
		data->collectible_count++;
	if ((name_problem == 5 && (exit_count != 1 || start_count != 1))
		|| name_problem == 4 || (data->collectible_count == 0
			&& name_problem == 5))
	{
		perror("Error Invalid map configuration");
		return (1);
	}
	return (0);
}

static int	check_char(char c, t_data *data)
{
	if (c == 'E')
		return (verify_map_conditions(1, data));
	if (c == 'P')
		return (verify_map_conditions(2, data));
	if (c == 'C')
		return (verify_map_conditions(3, data));
	if (c != '0' && c != '1')
		return (verify_map_conditions(4, data));
	return (0);
}

static int	loop(char **lines, t_data *data)
{
	int	x;
	int	y;
	int	height;
	int	width;

	y = 0;
	if (!lines)
		return (1);
	height = get_height(lines);
	width = get_width(lines);
	while (lines[y])
	{
		x = 0;
		while (lines[y][x])
		{
			if ((y == 0 || y == height - 1 || x == 0 || x == width - 1)
				&& lines[y][x] != '1')
				return (verify_map_conditions(4, data));
			if (check_char(lines[y][x], data))
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

int	verify_map_start(char **lines, t_data *data)
{
	if (!lines)
		return (1);
	if (loop(lines, data) || verify_map_conditions(5, data))
		return (1);
	if (!check_accessibility(lines, data->collectible_count))
	{
		perror("Error Not all collectibles or exit are accessible");
		return (1);
	}
	return (0);
}

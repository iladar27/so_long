/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilgaynet <ilgaynet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 11:39:30 by ilgaynet          #+#    #+#             */
/*   Updated: 2025/02/12 11:15:24 by ilgaynet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	display_moves(t_data *data, int moves)
{
	char	*move_str;

	put_img(data, "textures/map/wall.xpm", 2, 0);
	put_img(data, "textures/map/wall.xpm", 3, 0);
	put_img(data, "textures/map/wall.xpm", 1, 0);
	move_str = ft_itoa(moves);
	mlx_string_put(data->mlx, data->window, 10, 10, 0xFF0000, "Moves: ");
	mlx_string_put(data->mlx, data->window, 80, 10, 0xFF0000, move_str);
	ft_printf("Moves: %d\n", moves);
	free(move_str);
}

int	find_player(int *x, int *y, t_data *data)
{
	*x = 0;
	*y = 0;
	while (data->map[*y] != NULL)
	{
		*x = 0;
		while (data->map[*y][*x])
		{
			if (data->map[*y][*x] == 'P')
				return (0);
			(*x)++;
		}
		(*y)++;
	}
	return (1);
}

int	change_x_y(int *x, int *y, int keycode, t_data *data)
{
	int	lastx;
	int	lasty;

	lastx = (*x);
	lasty = (*y);
	if (keycode == 'w')
		(*y)--;
	else if (keycode == 's')
		(*y)++;
	else if (keycode == 'a')
		(*x)--;
	else if (keycode == 'd')
		(*x)++;
	if (data->map[*y][*x] == '1')
	{
		(*y) = lasty;
		(*x) = lastx;
		return (1);
	}
	put_img(data, "textures/map/floor.xpm", lastx, lasty);
	return (0);
}

int	player_move(t_data *data, int x, int y)
{
	static unsigned int	move;
	static int			count;

	if (data->map[y][x] == 'C')
	{
		count++;
		data->map[y][x] = '0';
		put_img(data, "textures/map/start.xpm", x, y);
		if (data->collectible_count == count)
			creat_exit(data);
	}
	else if (data->map[y][x] == 'E' && data->collectible_count == count)
	{
		ft_printf("VICTORY!!, moves: %d", move);
		close_window(data);
	}
	else if (data->map[y][x] == '0' || data->map[y][x] == 'P'
		|| data->map[y][x] == 'E')
		put_img(data, "textures/map/start.xpm", x, y);
	move++;
	display_moves(data, move);
	return (0);
}

void	player_playing(t_data *data, int keycode)
{
	static int	x;
	static int	y;
	static int	initialized;

	if (!initialized)
	{
		if (find_player(&x, &y, data))
			return ;
		initialized++;
	}
	if (change_x_y(&x, &y, keycode, data) != 1)
		player_move(data, x, y);
}

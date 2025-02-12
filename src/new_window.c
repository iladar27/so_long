/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilgaynet <ilgaynet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 15:21:46 by ilgaynet          #+#    #+#             */
/*   Updated: 2025/02/12 11:48:38 by ilgaynet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

int	close_window(t_data *data)
{
	if (data->window)
		mlx_destroy_window(data->mlx, data->window);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	free_map(data->map);
	exit(0);
}

int	handle_keypress(int keycode, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (keycode == 65307)
		close_window(data);
	else if (keycode == 'w' || keycode == 'a' || keycode == 's'
		|| keycode == 'd')
		player_playing(data, keycode);
	return (0);
}

void	setup_hooks(t_data *data)
{
	mlx_hook(data->window, 17, 1L << 17, close_window, data);
	mlx_hook(data->window, 2, 1L << 0, handle_keypress, data);
}

void	*open_window(int width, int height, void *mlx)
{
	void	*window;

	window = mlx_new_window(mlx, (width * 32), (height * 32), "So_long");
	if (!window)
		perror("Error Failed to create window");
	return (window);
}

int	main(int ac, char **av)
{
	t_data	data;

	ft_memset(&data, 0, sizeof(t_data));
	data.map = read_map(ac, av, &data);
	if (!data.map)
		return (1);
	data.mlx = mlx_init();
	if (!data.mlx)
	{
		perror("Error Failed to initialize MLX");
		free_map(data.map);
		return (1);
	}
	data.window = open_window(data.width, data.height, data.mlx);
	if (!data.window)
	{
		mlx_destroy_display(data.mlx);
		free(data.mlx);
		free_map(data.map);
		return (1);
	}
	draw_map(&data);
	setup_hooks(&data);
	mlx_loop(data.mlx);
	return (0);
}

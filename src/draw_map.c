/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilgaynet <ilgaynet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:22:04 by ilgaynet          #+#    #+#             */
/*   Updated: 2025/01/22 14:57:50 by ilgaynet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	put_img(t_data *data, const char *path, int x, int y)
{
	int		width;
	int		height;
	void	*img;

	img = mlx_xpm_file_to_image(data->mlx, (char *)path, &width, &height);
	if (!img)
	{
		perror("Failed to load image");
		return ;
	}
	mlx_put_image_to_window(data->mlx, data->window,
		img, x * width, y * height);
	mlx_destroy_image(data->mlx, img);
}

void	draw_map(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (data->map[y] != NULL)
	{
		x = 0;
		while (data->map[y][x] != '\0')
		{
			if (data->map[y][x] == '1')
				put_img(data, "textures/map/wall.xpm", x, y);
			else if (data->map[y][x] == '0')
				put_img(data, "textures/map/floor.xpm", x, y);
			else if (data->map[y][x] == 'P')
				put_img(data, "textures/map/start.xpm", x, y);
			else if (data->map[y][x] == 'C')
				put_img(data, "textures/map/collectible.xpm", x, y);
			else if (data->map[y][x] == 'E')
				put_img(data, "textures/map/floor.xpm", x, y);
			x++;
		}
		y++;
	}
}

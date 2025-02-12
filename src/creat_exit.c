/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilgaynet <ilgaynet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:46:00 by ilgaynet          #+#    #+#             */
/*   Updated: 2025/01/22 15:03:44 by ilgaynet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

int	find_exit(int *x, int *y, t_data *data)
{
	*y = 0;
	while (data->map[*y] != NULL)
	{
		*x = 0;
		while (data->map[*y][*x] != '\0')
		{
			if (data->map[*y][*x] == 'E')
				return (0);
			(*x)++;
		}
		(*y)++;
	}
	return (1);
}

void	creat_exit(t_data *data)
{
	int	x;
	int	y;

	if (find_exit(&x, &y, data) == 0)
		put_img(data, "textures/map/exit.xpm", x, y);
}

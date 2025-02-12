/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilgaynet <ilgaynet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 15:21:51 by ilgaynet          #+#    #+#             */
/*   Updated: 2025/02/12 11:44:37 by ilgaynet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <X11/keysym.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <limits.h>
# include "getnextline/get_next_line.h"
# include "libft/libft.h"
# include "minilibx/mlx.h"
# include "ft_printf/includes/ft_printf.h"

typedef struct s_data
{
	void	*mlx;
	void	*window;
	char	**map;
	int		collectible_count;
	int		width;
	int		height;
}	t_data;

int		ft_printf(const char *format, ...);
char	**read_map(int ac, char **av, t_data *data);
int		verify_map_start(char **lines, t_data *data);
void	*ft_realloc(void *ptr, size_t old_size, size_t new_size);
int		main(int ac, char **av);
void	draw_map(t_data *data);
void	*open_window(int width, int height, void *mlx);
void	creat_exit(t_data *data);
void	put_img(t_data *data, const char *path, int x, int y);
void	player_playing(t_data *data, int keycode);
int		get_height(char **map);
int		get_width(char **map);
int		close_window(t_data *data);
int		check_accessibility(char **map, int collectible_count);
void	free_lines(char **lines);
void	free_map(char **map);
char	**ft_strdup_2d(char **src);

#endif

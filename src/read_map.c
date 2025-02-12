/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilgaynet <ilgaynet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 15:21:43 by ilgaynet          #+#    #+#             */
/*   Updated: 2025/02/12 11:42:39 by ilgaynet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

static int	open_file(int ac, char **av)
{
	int	fd;

	if (ac < 2)
		fd = open("maps/main_map.ber", O_RDONLY);
	else
		fd = open(av[1], O_RDONLY);
	if (fd < 0)
	{
		perror("Error Cannot open map");
		return (-1);
	}
	return (fd);
}

static int	validate_line(char *line, int *width)
{
	int	len;

	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[--len] = '\0';
	if (*width == 0)
		*width = len;
	else if (len != *width)
	{
		perror("Error Inconsistent line length");
		return (0);
	}
	return (1);
}

static char	*read_single_line(int fd, char ***lines, int *width, int *count)
{
	char	*line;

	line = get_next_line(fd);
	if (!line)
		return (NULL);
	if (!validate_line(line, width))
	{
		free(line);
		return (NULL);
	}
	*lines = ft_realloc(*lines, sizeof(char *) * (*count + 1),
			sizeof(char *) * (*count + 2));
	if (!*lines)
	{
		free(line);
		perror("Error Memory allocation failed");
		return (NULL);
	}
	(*lines)[*count] = line;
	(*lines)[*count + 1] = NULL;
	(*count)++;
	return (line);
}

static int	read_lines(int fd, char ***lines, int *width, int *height)
{
	int		line_count;
	char	*line;

	line_count = 0;
	*width = 0;
	while (1)
	{
		line = read_single_line(fd, lines, width, &line_count);
		if (!line)
		{
			if (line_count == 0)
			{
				perror("Error Empty map");
				return (-1);
			}
			break ;
		}
	}
	*height = line_count;
	return (0);
}

char	**read_map(int ac, char **av, t_data *data)
{
	char	**lines;
	int		fd;

	lines = NULL;
	fd = open_file(ac, av);
	if (fd == -1)
		return (NULL);
	if (read_lines(fd, &lines, &data->width, &data->height) == -1)
	{
		close(fd);
		free_lines(lines);
		return (NULL);
	}
	close(fd);
	if (verify_map_start(lines, data))
	{
		free_lines(lines);
		return (NULL);
	}
	return (lines);
}

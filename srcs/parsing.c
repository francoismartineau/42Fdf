/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francoma <francoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 11:48:21 by francoma          #+#    #+#             */
/*   Updated: 2023/02/07 07:41:51 by francoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>		// open
#include <unistd.h>		// close

#include "fdf.h"

static int	inspect_map_line(char const *line, t_map *map)
{
	size_t	curr_width;

	curr_width = count_numbers(line);
	if (map->width && curr_width != map->width)
		return (FAILURE);
	map->width = curr_width;
	return (SUCCESS);
}

static int	inspect_map_file(char const *path, t_map *map)
{
	char	*line;
	int		res;
	int		fd;

	res = SUCCESS;
	fd = open(path, O_RDONLY);
	if (fd == -1)
		res = FAILURE;
	while (res == SUCCESS)
	{
		line = get_next_line(fd);
		if (line)
		{
			(map->length)++;
			res = inspect_map_line(line, map);
		}
		free(line);
		if (!line)
			break ;
	}
	close(fd);
	if (map->width + map->length <= 2)
		res = FAILURE;
	return (res);
}

static int	get_map_heights(char const *path, t_map *map)
{
	size_t	y;
	char	*line;
	int		fd;

	fd = open(path, O_RDONLY);
	y = 0;
	while (y < map->length)
	{
		line = get_next_line(fd);
		if (!line)
		{
			close(fd);
			return (FAILURE);
		}
		split_numbers(map->heights + (y * map->width), line);
		free(line);
		y++;
	}
	close(fd);
	return (SUCCESS);
}

static void	set_min_max_heights(t_map *map)
{
	size_t	i;
	size_t	len;

	len = map->width * map->length;
	i = 0;
	while (i < len)
	{
		if (map->heights[i] > map->max_height)
			map->max_height = map->heights[i];
		else if (map->heights[i] < map->min_height)
			map->min_height = map->heights[i];
		i++;
	}
}

t_map	*init_map(char const *path)
{
	t_map	*map;

	map = ft_calloc(sizeof(*map), 1);
	if (!map)
		exit_error("map memory error");
	if (inspect_map_file(path, map) == FAILURE)
		exit_error("map error");
	map->heights = malloc(sizeof(*map->heights) * map->width * map->length);
	map->points = malloc(sizeof(*map->points) * map->width * map->length);
	if (!map->heights || !map->points)
		exit_error("map memory error");
	if (get_map_heights(path, map) == FAILURE)
		exit_error("map memory error");
	map->scale = MAP_INIT_SCALE;
	map->elevation = .1;
	set_min_max_heights(map);
	return (map);
}

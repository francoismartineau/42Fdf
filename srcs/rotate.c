/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francoma <francoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 12:13:02 by francoma          #+#    #+#             */
/*   Updated: 2023/02/01 15:32:28 by francoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_swap_st(size_t *a, size_t *b)
{
	size_t	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static void	rotate_heigths(t_map *map)
{
	int		*temp_heights;
	size_t	i;
	size_t	x;
	size_t	y;

	temp_heights = ft_calloc(sizeof(*temp_heights), map->length * map->width);
	if (!temp_heights)
		return ;
	i = 0;
	x = 0;
	while (x < map->width)
	{
		y = map->length;
		while (y > 0)
		{
			temp_heights[i++] = map->heights[(y - 1) * map->width + x];
			y--;
		}
		x++;
	}
	ft_swap_st(&map->length, &map->width);
	ft_memmove(map->heights, temp_heights,
		sizeof(*map->heights) * map->length * map->width);
	free(temp_heights);
}

void	rotate(t_map *map)
{
	map->rotation++;
	if (map->rotation % 2)
	{
		map->place_points = place_points_para;
		map->draw_grid = draw_grid_para;
		return ;
	}
	map->place_points = place_points_iso;
	map->draw_grid = draw_grid_iso;
	rotate_heigths(map);
}

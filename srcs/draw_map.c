/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francoma <francoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 12:18:08 by francoma          #+#    #+#             */
/*   Updated: 2023/02/03 16:00:21 by francoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	top_left_point(t_map *map,
	t_point	incr_x(t_point, int, t_map *),
	t_point	incr_y(t_point, int, t_map *))
{
	t_point	p;

	p.x = WIN_W / 2 + map->translate_x;
	p.y = WIN_H / 2 + map->translate_y;
	p = incr_x(p, -(map->width) / 2, map);
	p = incr_y(p, -(map->length) / 2, map);
	return (p);
}

void	draw_map(t_map *map)
{
	size_t	i;
	t_point	p0;
	t_point	p1;

	if (map->grid)
		map->draw_grid(map);
	map->place_points(map);
	i = 0;
	while (i < map->length * map->width)
	{
		p0 = map->points[i];
		if (i % map->width)
		{
			p1 = map->points[i - 1];
			draw_line(p0, p1, draw_point_with_height_color);
		}
		if (i >= map->width)
		{
			p1 = map->points[i - map->width];
			draw_line(p0, p1, draw_point_with_height_color);
		}
		i++;
	}
}

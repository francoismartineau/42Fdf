/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_isometric.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francoma <francoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 09:10:29 by francoma          #+#    #+#             */
/*   Updated: 2023/03/09 11:26:00 by francoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_point	incr_x(t_point p, int factor, t_map *map)
{
	t_point	res;

	res.x = p.x + map->scale * 2 * factor * RATIO_PARA_ISO_INCR_X;
	res.y = p.y - map->scale * factor * RATIO_PARA_ISO_INCR_X;
	return (res);
}

static t_point	incr_y(t_point p, int factor, t_map *map)
{
	t_point	res;

	res.x = p.x + map->scale * 2 * factor * RATIO_PARA_ISO_INCR_Y;
	res.y = p.y + map->scale * factor * RATIO_PARA_ISO_INCR_Y;
	return (res);
}

static t_point	apply_height(t_point p, int height, t_map *map)
{
	t_point	res;

	res.x = p.x;
	res.y = p.y - height * map->scale * map->elevation / HEIGHT_PRECISION;
	res.height = height;
	return (res);
}

void	draw_grid_iso(t_map *map)
{
	t_point	p;
	int		i;
	int		scale_save;

	scale_save = map->scale;
	map->scale = ft_max(map->scale, 5);
	p.y = 0;
	i = 0;
	while (p.y < WIN_H + map->scale)
	{
		p.x = (i % 2) * map->scale * 2;
		while (p.x < WIN_W + map->scale * 2)
		{
			draw_line(p, incr_y(p, -1, map), draw_grid_point);
			draw_line(p, incr_y(incr_x(p, 1, map), -1, map), draw_grid_point);
			draw_line(p, incr_x(p, 1, map), draw_grid_point);
			p.x += map->scale * 4;
		}
		i++;
		p.y = i * map->scale;
	}
	map->scale = scale_save;
}

void	place_points_iso(t_map *map)
{
	t_point	p;
	size_t	x;
	size_t	y;
	size_t	i;

	i = 0;
	y = 0;
	while (y < map->length)
	{
		p = top_left_point(map, incr_x, incr_y);
		p = incr_y(p, y, map);
		x = 0;
		while (x < map->width)
		{
			map->points[i] = incr_x(p, x, map);
			map->points[i] = apply_height(map->points[i], map->heights[i], map);
			i++;
			x++;
		}
		y++;
	}
}

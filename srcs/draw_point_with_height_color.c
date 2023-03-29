/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_point_with_height_color.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francoma <francoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 09:50:21 by francoma          #+#    #+#             */
/*   Updated: 2023/02/06 16:15:54 by francoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_abs(int a)
{
	if (a < 0)
		return (-a);
	return (a);
}

static int	interp_color(float ratio, int c1, int c2)
{
	return (((int)(((0xFF00 & c1) >> 8) * (1 - ratio)) << 8)
		+ ((int)(((0xFF00 & c2) >> 8) * ratio) << 8)
		+ ((int)(((0xFF0000 & c1) >> 16) * (1 - ratio)) << 16)
		+ ((int)(((0xFF0000 & c2) >> 16) * ratio) << 16)
		+ ((int)(((0xFF000000 & c1) >> 24) * (1 - ratio)) << 24)
		+ ((int)(((0xFF000000 & c2) >> 24) * ratio) << 24)
		+ 0xFF);
}

static int	get_height_color(t_data *data, int height)
{
	int			color_low_index;
	int			color_high_index;
	float		height_ratio;
	static int	colors[COLORS_MAP_QTY] = {BLUE, BROWN, BEIGE,
		GREEN, LIGHT_GREEN, GREY, WHITE};

	if (COLORS_MAP_QTY == 0)
		return (0xFFFFFFFF);
	if (data->map->max_height == data->map->min_height
		|| height == data->map->min_height
		|| COLORS_MAP_QTY == 1)
		return (colors[0]);
	if (height == data->map->max_height)
		return (colors[COLORS_MAP_QTY - 1]);
	height_ratio = (float)(height - data->map->min_height)
		/ (data->map->max_height - data->map->min_height);
	color_low_index = height_ratio * (COLORS_MAP_QTY - 1);
	color_high_index = color_low_index + 1;
	height_ratio *= (COLORS_MAP_QTY - 1);
	height_ratio -= (int)(height_ratio);
	return (interp_color(height_ratio,
			colors[color_low_index], colors[color_high_index]));
}

static int	find_interpolation_point_height(t_point interp,
	t_point p0, t_point p1)
{
	float	ratio;

	if (p0.height == p1.height)
		return (p0.height);
	ratio = (float)(ft_abs(interp.x - p0.x) + ft_abs(interp.y - p0.y))
		/ (ft_abs(p1.x - p0.x) + ft_abs(p1.y - p0.y));
	return (p0.height + ratio * (p1.height - p0.height));
}

void	draw_point_with_height_color(t_point interp,
	t_point p0, t_point p1)
{
	t_data	*data;
	int		color;

	if (interp.x < 0 || interp.x >= WIN_W || interp.y < 0 || interp.y >= WIN_H)
		return ;
	data = get_data();
	interp.height = find_interpolation_point_height(interp, p0, p1);
	color = get_height_color(data, interp.height);
	put_pixel(data->img, interp.x, interp.y, color);
}

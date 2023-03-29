/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francoma <francoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 09:36:51 by francoma          #+#    #+#             */
/*   Updated: 2023/02/03 17:19:15 by francoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_pixel(mlx_image_t *img, int x, int y, int color)
{
	if (x < 0 || x >= WIN_W || y < 0 || y >= WIN_H)
		return ;
	mlx_put_pixel(img, x, y, color);
}

void	draw_grid_point(t_point interp, t_point p0, t_point p1)
{
	t_data	*data;

	(void) p0;
	(void) p1;
	data = get_data();
	put_pixel(data->img, interp.x, interp.y, COLOR_GRID);
}

static void	draw_background(mlx_image_t *img)
{
	int	x;
	int	y;

	y = 0;
	while (y < WIN_H)
	{
		x = 0;
		while (x < WIN_W)
		{
			put_pixel(img, x, y, COLOR_BACKGROUND);
			x++;
		}
		y++;
	}
}

void	draw_frame(t_data *data, void (f)(t_map *))
{
	mlx_delete_image(data->mlx, data->img);
	data->img = mlx_new_image(data->mlx, WIN_W, WIN_H);
	draw_background(data->img);
	f(data->map);
	mlx_image_to_window(data->mlx, data->img, 0, 0);
}

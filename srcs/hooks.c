/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francoma <francoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 17:48:58 by francoma          #+#    #+#             */
/*   Updated: 2023/02/06 14:29:10 by francoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	redraw_map_key_down(mlx_t *mlx)
{
	int				i;
	static keys_t	redraw_keys[9] = {MLX_KEY_LEFT, MLX_KEY_RIGHT, MLX_KEY_UP,
		MLX_KEY_DOWN, MLX_KEY_MINUS, MLX_KEY_EQUAL, MLX_KEY_G,
		MLX_KEY_R, MLX_KEY_T};

	i = 0;
	while (i < 9)
	{
		if (mlx_is_key_down(mlx, redraw_keys[i]))
			return (1);
		i++;
	}
	return (0);
}

void	key_pressed(mlx_key_data_t keydata, void *param)
{
	t_data	*data;

	if (keydata.action != MLX_PRESS)
		return ;
	data = (t_data *)param;
	if (keydata.key == MLX_KEY_Q || keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(data->mlx);
	else if (keydata.key == MLX_KEY_G)
		data->map->grid = !data->map->grid;
	else if (keydata.key == MLX_KEY_R)
		rotate(data->map);
	else if (keydata.key == MLX_KEY_MINUS)
		data->map->scale = ft_max(1, (data->map->scale) >>= 1);
	else if (keydata.key == MLX_KEY_EQUAL)
		data->map->scale = ft_min(128, (data->map->scale) <<= 1);
	else if (keydata.key == MLX_KEY_T)
	{
		data->map->translate_x = 0;
		data->map->translate_y = 0;
	}
}

void	check_key_states(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
		data->map->translate_x += data->map->scale;
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
		data->map->translate_x -= data->map->scale;
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT_SHIFT)
		&& mlx_is_key_down(data->mlx, MLX_KEY_UP))
		data->map->elevation += .1;
	else if (mlx_is_key_down(data->mlx, MLX_KEY_UP))
		data->map->translate_y += data->map->scale;
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT_SHIFT)
		&& mlx_is_key_down(data->mlx, MLX_KEY_DOWN))
		data->map->elevation -= .1;
	else if (mlx_is_key_down(data->mlx, MLX_KEY_DOWN))
		data->map->translate_y -= data->map->scale;
	if (redraw_map_key_down(data->mlx))
		draw_frame(data, draw_map);
}

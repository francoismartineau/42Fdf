/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francoma <francoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 09:07:22 by francoma          #+#    #+#             */
/*   Updated: 2023/02/04 13:21:12 by francoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>	// malloc, free, exit, EXIT_SUCCESS, EXIT_FAILURE
# include "MLX42.h"
# include "libft.h"
# include "defines.h"

size_t	count_numbers(char const *s);
void	split_numbers(int *dst, char const *src);

void	draw_grid_iso(t_map *map);
void	place_points_iso(t_map *map);

void	draw_grid_para(t_map *map);
void	place_points_para(t_map *map);

void	rotate(t_map *map);

void	exit_error(char *message);
void	free_data(void);
t_data	*get_data(void);
t_data	*init_data(char const *map_path);

t_map	*init_map(char const *path);

void	close_window(void *data);
void	key_pressed(mlx_key_data_t keydata, void *data);
void	check_key_states(void *data);

void	draw_frame(t_data *data, void (f)(t_map *));
t_point	top_left_point(t_map *map,
			t_point	incr_x(t_point, int, t_map *),
			t_point	incr_y(t_point, int, t_map *));
void	draw_map(t_map *map);
void	put_pixel(mlx_image_t *img, int x, int y, int color);
void	draw_line(t_point p0, t_point p1,
			void (*draw_point_func)(t_point, t_point, t_point));
void	draw_point_with_height_color(t_point interp, t_point p0, t_point p1);
void	draw_grid_point(t_point interp, t_point p0, t_point p1);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francoma <francoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 17:25:46 by francoma          #+#    #+#             */
/*   Updated: 2023/03/09 11:49:40 by francoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# include <stddef.h>

# define WIN_W	800
# define WIN_H	600
# define MAP_INIT_SCALE 8
# define WIN_TITLE "Fdf"
# define FILE_EXT ".fdf"

# define COLOR_BACKGROUND 0x000000FF
# define COLOR_GRID 0x333333FF
# define BLUE 0x0000FFFF
# define BROWN 0x654321FF
# define BEIGE 0xAC9362FF
# define GREEN 0x006600FF
# define LIGHT_GREEN 0x00AA00FF
# define GREY 0x777777FF
# define WHITE 0xFFFFFFFF
# define COLORS_MAP_QTY 7
# define HEIGHT_PRECISION 10

# define RATIO_PARA_ISO_INCR_X 1 //0.8944271909999159 // 2 / sqrt(5)
# define RATIO_PARA_ISO_INCR_Y 1 //0.6324555320336759 // sqrt(2) / sqrt(5)
# define USAGE "\
R: rotate (switches between parralel and isometric projections\n\
T: reset translation\n\
Arrows: move around\n\
Shift + Up/Down: set map elevation\n\
G: toggle grid\n"

# define SUCCESS 0
# define FAILURE -1

typedef struct s_point
{
	int	x;
	int	y;
	int	height;
}	t_point;

typedef struct s_map
{
	int		*heights;
	int		max_height;
	int		min_height;
	t_point	*points;
	size_t	length;
	size_t	width;
	int		scale;
	int		scale_lin;
	int		translate_x;
	int		translate_y;
	float	elevation;
	int		rotation;
	void	(*place_points)(struct s_map *map);
	int		grid;
	void	(*draw_grid)(struct s_map *map);
}	t_map;

typedef struct s_data
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_map		*map;
}	t_data;

#endif
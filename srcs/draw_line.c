/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francoma <francoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 10:07:35 by francoma          #+#    #+#             */
/*   Updated: 2023/02/01 14:23:45 by francoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_abs(int a)
{
	if (a < 0)
		return (-a);
	return (a);
}

// eliminates some trivial cases where a line between p0 and p1
// wont cross the screen
static int	line_crosses_screen(t_point p0, t_point p1)
{
	if ((p0.x < 0 && p1.x < 0) || (p0.x >= WIN_W && p1.x >= WIN_W)
		|| (p0.y < 0 && p1.y < 0) || (p0.y >= WIN_H && p1.y >= WIN_H))
		return (0);
	return (1);
}

typedef struct s_draw_line_vars
{
	t_data	*data;
	int		dx;
	int		dy;
	int		sx;
	int		sy;
	int		err;
	int		e2;
	t_point	interp_p;
}	t_draw_line_vars;

static t_draw_line_vars	init_draw_line_vars(t_point p0, t_point p1)
{
	t_draw_line_vars	vars;

	vars.dx = ft_abs(p1.x - p0.x);
	vars.dy = -ft_abs(p1.y - p0.y);
	vars.sx = 2 * (p0.x < p1.x) - 1;
	vars.sy = 2 * (p0.y < p1.y) - 1;
	vars.err = vars.dx + vars.dy;
	vars.interp_p.x = p0.x;
	vars.interp_p.y = p0.y;
	return (vars);
}

void	draw_line(t_point p0, t_point p1,
	void (*draw_point_func)(t_point, t_point, t_point))
{
	t_draw_line_vars	vars;

	if (!line_crosses_screen(p0, p1))
		return ;
	vars = init_draw_line_vars(p0, p1);
	while (1)
	{
		draw_point_func(vars.interp_p, p0, p1);
		if (vars.interp_p.x == p1.x && vars.interp_p.y == p1.y)
			break ;
		vars.e2 = 2 * vars.err;
		if (vars.e2 >= vars.dy)
		{
			vars.err += vars.dy;
			vars.interp_p.x += vars.sx;
		}
		if (vars.e2 <= vars.dx)
		{
			vars.err += vars.dx;
			vars.interp_p.y += vars.sy;
		}
	}
}

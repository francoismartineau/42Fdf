/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   runtime.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francoma <francoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 08:31:59 by francoma          #+#    #+#             */
/*   Updated: 2023/02/07 08:41:41 by francoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	exit_error(char *message)
{
	free_data();
	ft_printf("Error: %s\n", message);
	exit(EXIT_SUCCESS);
}

static void	free_map(t_map *map)
{
	if (!map)
		return ;
	free(map->heights);
	free(map->points);
	free(map);
}

void	free_data(void)
{
	t_data	*data;

	data = get_data();
	if (!data)
		return ;
	free_map(data->map);
	free(data);
}

t_data	*get_data(void)
{
	static t_data	*data = NULL;

	if (!data)
		data = ft_calloc(1, sizeof(*data));
	return (data);
}

t_data	*init_data(char const *map_path)
{
	t_data	*data;

	data = get_data();
	if (!data)
		exit_error("data memory error");
	data->map = init_map(map_path);
	data->map->place_points = place_points_iso;
	data->map->draw_grid = draw_grid_iso;
	return (data);
}

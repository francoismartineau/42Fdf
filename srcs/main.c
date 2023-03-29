/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francoma <francoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 09:07:25 by francoma          #+#    #+#             */
/*   Updated: 2023/02/07 07:46:18 by francoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char const *argv[])
{
	t_data	*data;

	if (argc != 2)
		exit_error("bad arguments");
	if (ft_strncmp(argv[1], "-h", 2) == 0)
	{
		ft_printf(USAGE);
		exit(EXIT_SUCCESS);
	}
	data = init_data(argv[1]);
	if (!data)
		exit_error("data memory error");
	data->mlx = mlx_init(WIN_W, WIN_H, WIN_TITLE, 1);
	draw_frame(data, draw_map);
	mlx_key_hook(data->mlx, key_pressed, data);
	mlx_loop_hook(data->mlx, check_key_states, data);
	mlx_loop(data->mlx);
	mlx_terminate(data->mlx);
	free_data();
	return (0);
}

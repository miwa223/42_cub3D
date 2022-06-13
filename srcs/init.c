/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasubuc <mmasubuc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 16:29:30 by mmasubuc          #+#    #+#             */
/*   Updated: 2022/06/12 18:34:53 by mmasubuc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_data(t_data *data)
{
	int	i;

	i = 0;
	init_mlx(data);
	data->ppos.direction = ALL_DIRECTION;
	data->ppos.pos.x = 0;
	data->ppos.pos.y = 0;
	data->cubfile = (t_cubfile *)malloc(sizeof(t_cubfile));
	if (!data->cubfile)
		exit_program(MALLOC_FAIL);
	while (i < ALL_DIRECTION)
		data->cubfile->textures[i++] = NULL;
	data->cubfile->colors[FLOOR] = 0;
	data->cubfile->colors[CELLING] = 0;
	data->cubfile->map_row = 0;
	data->cubfile->map_col = 0;
	data->cubfile->map = NULL;
}

void	init_mlx(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		exit_program(MLX_INIT_FAIL);
	data->mlx_win = mlx_new_window(data->mlx, 1200, 720, "cub3D");
	if (!data->mlx_win)
	{
		mlx_destroy_display(data->mlx);
		exit_program(MLX_NEW_WINDOW_FAIL);
	}
}

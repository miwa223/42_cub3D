/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfumiya <kfumiya@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 10:38:19 by kfumiya           #+#    #+#             */
/*   Updated: 2022/06/13 09:14:44 by kfumiya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include <stdio.h>
#include "cub3d.h"


void
	print_ray(t_ray ray)
{
	printf("\n=== ray info ======================\n");
	printf("camera_x: %lf\n", ray.camera_x);
	printf("dir.x: %lf\n", ray.dir.x);
	printf("dir.y: %lf\n", ray.dir.y);
	printf("map_x: %d\n", ray.map_x);
	printf("map_y: %d\n", ray.map_y);
	printf("side_dist_x: %lf\n", ray.side_dist_x);
	printf("side_dist_y: %lf\n", ray.side_dist_y);
	printf("perp_wall_dist: %lf\n", ray.perp_wall_dist);
	printf("side: %d\n", ray.side);
	printf("step_x: %d\n", ray.step_x);
	printf("step_y: %d\n", ray.step_y);
	printf("delta_dist_x: %lf\n", ray.delta_dist_x);
	printf("delta_dist_x: %lf\n", ray.delta_dist_x);
	printf("color: %x\n", ray.color);
	printf("===================================\n\n");
}

void
	print_wall(t_wall wall)
{
	printf("\n=== wall info ======================\n");
	printf("line_height: %d\n", wall.line_height);
	printf("draw_start: %d\n", wall.draw_start);
	printf("draw_end: %d\n", wall.draw_end);
	printf("wall_x: %lf\n", wall.wall_x);
	// printf("texture_x: %lf\n", wall.texture_x);
	printf("step: %lf\n", wall.step);
	// printf("texture_pos_y: %lf\n", wall.texture_pos_y);
	// printf("texture_y: %d\n", wall.texture_y);
	printf("======================================\n\n");
}


void
	print_image(t_image *img)
{
	printf("\n=== image info ======================\n");
	printf("img_p: %p\n", img->img);
	printf("bits_pre_pixel: %d\n", img->bits_per_pixel);
	printf("line_length: %d\n", img->line_length);
	printf("endian: %d\n", img->endian);
	printf("width: %d\n", img->width);
	printf("height: %d\n", img->height);
	printf("\n====================================\n");
}

void	print_data(t_data *data)
{
	size_t	i;

	i = 0;
	if (!data)
		return ;
	if (data->cubfile)
	{
		printf("row: %zu, col: %zu\n",
			data->cubfile->map_row, data->cubfile->map_col);
		while (i < data->cubfile->map_row)
			printf("m: %s\n", data->cubfile->map[i++]);
	}
}

void
	print_map(t_data *data)
{
	int i;

	i = 0;
	while (data->map[i])
	{
		printf("%s\n", data->map[i]);
		i++;
	}
}

void
	print_da(t_data *data)
{
	printf("\n=== data =========================================\n");
	printf("player\n");
	printf("pos\n\tx: %lf\n\ty: %lf\n", \
			data->player.pos.x, data->player.pos.y);
	printf("dir\n\tx: %lf\n\ty: %lf\n", \
			data->player.dir.x, data->player.dir.y);
	printf("plane\n\tx: %lf\n\ty: %lf\n", \
			data->player.plane.x, data->player.plane.y);
	printf("status\n\tis_moving: %d\n\tis_rotating: %d\n", \
			data->player.is_moving, data->player.is_rotating);
	printf("\n====================================================\n");
}

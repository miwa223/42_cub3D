/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasubuc <mmasubuc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 10:38:19 by kfumiya           #+#    #+#             */
/*   Updated: 2022/06/14 23:03:21 by mmasubuc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	print_image(t_data *data)
{
	int	i;
	t_image img[4];
	const char *tex[4] = {"tex_n", "tex_s", "tex_w", "tex_e"};

	img[0] = data->tex_n;
	img[1] = data->tex_s;
	img[2] = data->tex_w;
	img[3] = data->tex_e;
	i = -1;
	while (++i < ALL_DIRECTION)
	{
		printf("\n=== image %s info ======================\n", tex[i]);
		printf("img_p: %p\n", img[i].img);
		printf("bits_pre_pixel: %d\n", img[i].bits_per_pixel);
		printf("line_length: %d\n", img[i].line_length);
		printf("endian: %d\n", img[i].endian);
		printf("width: %d\n", img[i].width);
		printf("height: %d\n", img[i].height);
		printf("=====================================\n\n");
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
	printf("mlx: %p\n", data->mlx);
	printf("win: %p\n", data->win);
	printf("screen_w: %d screen_h: %d\n", \
		data->screen_width, data->screen_height);
	printf("horizon: %lf\n", data->horizon);
	printf("sky_color: %x\n", data->sky_color);
	printf("ground_color: %x\n", data->ground_color);
	printf("player\n");
	printf("pos\n\tx: %lf\n\ty: %lf\n", \
			data->player.pos.x, data->player.pos.y);
	printf("dir\n\tx: %lf\n\ty: %lf\n", \
			data->player.dir.x, data->player.dir.y);
	printf("plane\n\tx: %lf\n\ty: %lf\n", \
			data->player.plane.x, data->player.plane.y);
	printf("status\n\tis_moving: %d\n\tis_silding: %d\n\t \
		is_rotating: %d\n", data->player.is_moving, \
		data->player.is_sidling, data->player.is_rotating);
	printf("====================================================\n");
}

void
	print_info(t_data *data)
{
	print_da(data);
	print_map(data);
	print_image(data);
}

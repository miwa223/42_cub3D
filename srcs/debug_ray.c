/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfumiya <kfumiya@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 09:04:25 by kfumiya           #+#    #+#             */
/*   Updated: 2022/06/15 09:04:47 by kfumiya          ###   ########.fr       */
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
	printf("texture_x: %lf\n", wall.texture_x);
	printf("step: %lf\n", wall.step);
	printf("texture_pos_y: %lf\n", wall.texture_pos_y);
	printf("texture_y: %d\n", wall.texture_y);
	printf("======================================\n\n");
}

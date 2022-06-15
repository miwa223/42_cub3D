/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfumiya <kfumiya@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 10:38:19 by kfumiya           #+#    #+#             */
/*   Updated: 2022/06/15 09:04:54 by kfumiya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void
	print_image(t_data *data)
{
	int			i;
	t_image		img[4];
	const char	*tex[4] = {"tex_n", "tex_s", "tex_w", "tex_e"};

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
	int	i;

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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfumiya <kfumiya@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 10:01:31 by kfumiya           #+#    #+#             */
/*   Updated: 2022/06/07 12:55:55 by kfumiya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

# define N 10

const char world_map[][N] = {"1111111111",
							"1000000001",
							"1000000001",
							"1000000001",
							"1000000001",
							"1000000001",
							"1000000001",
							"1000000001",
							"1000000001",
							"1111111111"};

void
	set_map(char **map)
{
	int i;

	i = -1;
	map = (char **)malloc(sizeof(char *) * N);
	while (++i < N)
		map[i] = ft_strdup(world_map[i]);
}

static void
	set_player(t_player *player)
{
	player->pos.x = 1;
	player->pos.y = 1;
	player->dir.x = 0;
	player->dir.y = -1;
	player->plane.x = 1 * tan(deg_rad(66 / 2));
	player->is_moving = 0;
	player->is_sidling = 0;
	player->is_rotating = 0;
}

void
	set_data(t_data *data)
{
	data->mlx = mlx_init();
	data->win = NULL;
	data->screen_width = 850;
	data->screen_height = 500;
	set_player(&data->player);
	set_map(data->map);
	// if (!(data->map = ft_calloc(MAX_MAP_H, sizeof(char *)))) // 200 * 200が最大MAPサイズ
	// 	return (return_error_msg("failed malloc"));
	data->map_row = N;
	data->map_col = N;
	data->horizon = 0;
	data->sky_color = 0x00FFFF;
	data->ground_color = 0xD3D3D3;
	data->nouth_color = 0xFF00FF;
	data->south_color = 0xFF00FF;
	data->west_color = 0x00FF00;
	data->east_color = 0x00FF00;
	// data->tex_n.img = NULL;
	// data->tex_s.img = NULL;
	// data->tex_w.img = NULL;
	// data->tex_e.img = NULL;
	// data->tex_width = 0;
	// data->tex_height = 0;
}

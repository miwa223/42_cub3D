/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfumiya <kfumiya@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 10:01:31 by kfumiya           #+#    #+#             */
/*   Updated: 2022/06/08 12:50:11 by kfumiya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

# define N 10
# define C 11

const char world_map[][C] = {"1111111111\0",
							"1000000001\0",
							"1000000001\0",
							"1000000001\0",
							"1000000001\0",
							"1000000001\0",
							"1000000001\0",
							"1000000001\0",
							"1000000001\0",
							"1111111111\0"};

void
	set_map(t_data *data)
{
	int i;

	i = -1;
	while (++i < data->map_row)
	{
		data->map[i] = ft_calloc(MAX_MAP_W, sizeof(char));
		ft_strlcpy(data->map[i], world_map[i], ft_strlen(world_map[i]) + 1);
		if (!data->map[i])
			put_err_msg("memory error");
	}
}

void
	set_player(t_player *player)
{
	player->pos.x = 5;
	player->pos.y = 5;
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
	// set_player(&data->player);
	init_player(&data->player, 5, 5, 'W');
	if (!(data->map = ft_calloc(MAX_MAP_H, sizeof(char *)))) // 200 * 200が最大MAPサイズ
		return (put_err_msg("failed malloc"));
	data->map_row = N;
	data->map_col = N;
	set_map(data);
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
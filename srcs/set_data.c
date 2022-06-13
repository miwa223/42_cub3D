/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfumiya <kfumiya@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 10:01:31 by kfumiya           #+#    #+#             */
/*   Updated: 2022/06/13 13:57:45 by kfumiya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	set_tex(t_data *data)
{
	t_image	*tex;
	char	*path;
	int		i;

	i = 0;
	while (i < 4)
	{
		tex = NULL;
		path = NULL;
		if (i == 0)
		{
			tex = &data->tex_n;
			path = ft_strdup("texture/N.xpm");
		}
		else if (i == 1)
		{
			tex = &data->tex_s;
			path = ft_strdup("texture/S.xpm");
		}
		else if (i == 2)
		{
			tex = &data->tex_w;
			path = ft_strdup("texture/W.xpm");
		}
		else
		{
			tex = &data->tex_e;
			path = ft_strdup("texture/E.xpm");
		}
		if (read_image(data, tex, path) == ERROR)
			return (put_err_msg("Failed to read texture"));
		print_image(tex);
		i++;
	}
}
/* 
void
	set_data(t_data *data)
{
	data->mlx = mlx_init();
	data->win = NULL;
	data->screen_width = 850;
	data->screen_height = 500;
	init_player(&data->player, 5, 5, 'W');
	if (!(data->map = ft_calloc(MAX_MAP_H, sizeof(char *)))) // 200 * 200が最大MAPサイズ
		return (put_err_msg("failed malloc"));
	data->map_row = N;
	data->map_col = N;
	set_map(data);
	data->horizon = 0;
	data->sky_color = 0x00FFFF;
	data->ground_color = 0xD3D3D3;
	data->tex_n.img = NULL;
	data->tex_s.img = NULL;
	data->tex_w.img = NULL;
	data->tex_e.img = NULL;
	data->tex_width = 0;
	data->tex_height = 0;
	set_tex(data);
}

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

 */
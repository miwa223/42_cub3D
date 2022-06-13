/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfumiya <kfumiya@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 09:55:32 by kfumiya           #+#    #+#             */
/*   Updated: 2022/06/13 14:00:04 by kfumiya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void
	convert_info(t_data *data)
{
	init_player(&data->player, \
		data->player.pos.x, data->player.pos.y, data->player.direction);
	data->screen_width = 850;
	data->screen_height = 500;
	data->ground_color = data->cubfile->colors[FLOOR];
	data->sky_color = data->cubfile->colors[CELLING];
	set_tex(data);
	data->horizon = 0;
	data->map = data->cubfile->map;
}

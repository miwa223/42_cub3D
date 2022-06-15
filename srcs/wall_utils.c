/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfumiya <kfumiya@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 10:48:54 by kfumiya           #+#    #+#             */
/*   Updated: 2022/06/15 08:50:31 by kfumiya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void
	set_texture(t_data *data, t_ray *ray)
{
	if (ray->side == 0)
	{
		if (ray->step_x > 0)
			ray->tex = &data->tex_w;
		else
			ray->tex = &data->tex_e;
	}
	else
	{
		if (ray->step_y > 0)
			ray->tex = &data->tex_n;
		else
			ray->tex = &data->tex_s;
	}
}

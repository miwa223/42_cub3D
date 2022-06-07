/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfumiya <kfumiya@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 10:48:54 by kfumiya           #+#    #+#             */
/*   Updated: 2022/06/07 12:56:10 by kfumiya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
/* 
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
 */

void
	set_wall_color(t_data *data, t_ray *ray)
{
	if (ray->side == 0)
	{
		if (ray->step_x > 0)
			ray->color = data->west_color;
		else
			ray->color = data->east_color;
	}
	else
	{
		if (ray->step_y > 0)
			ray->color = data->nouth_color;
		else
			ray->color = data->south_color;		
	}
}

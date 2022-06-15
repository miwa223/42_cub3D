/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfumiya <kfumiya@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 11:31:45 by kfumiya           #+#    #+#             */
/*   Updated: 2022/06/15 08:54:58 by kfumiya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// mlx_pixel_put()はレンダリングを待たずに1ピクセルずつ描画するので激遅, なので同じ動きをする関数を自作する
void
	my_mlx_pixel_put(t_image *img, int x, int y, int color)
{
	char	*dst;

	// line_lengthは実際のウィンドウの横幅と違うので計算する必要がある
	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

uint32_t
	get_color_pix(t_image img, int x, int y)
{
	return (*(uint32_t *)(img.addr + \
		(y * img.line_length + x * (img.bits_per_pixel / 8))));
}

int
	read_image(t_data *data, t_image *img, char *filepath)
{
	img->img = mlx_xpm_file_to_image(data->mlx, filepath, \
		&img->width, &img->height);
	if (!img->img)
		return (ERROR);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, \
		&img->line_length, &img->endian);
	if (!img->addr)
		return (ERROR);
	return (0);
}

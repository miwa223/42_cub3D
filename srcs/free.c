/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasubuc <mmasubuc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 18:36:26 by mmasubuc          #+#    #+#             */
/*   Updated: 2022/06/12 19:03:17 by mmasubuc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_2d_array(char **content)
{
	int	i;

	i = 0;
	while (content[i] != NULL)
	{
		free(content[i]);
		content[i] = NULL;
		i++;
	}
	free(content);
	content = NULL;
}

void	free_buf(void **buf)
{
	free(*buf);
	*buf = NULL;
}

void	free_mlx(t_data *data, t_type type)
{
	int	i;

	i = 0;
	while (i < (int)type)
	{
		mlx_destroy_image(data->mlx, data->cubfile->textures[i]);
		i++;
	}
	mlx_destroy_window(data->mlx, data->mlx_win);
	mlx_destroy_display(data->mlx);
}

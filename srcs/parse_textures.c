/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasubuc <mmasubuc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 18:51:45 by mmasubuc          #+#    #+#             */
/*   Updated: 2022/06/12 19:01:08 by mmasubuc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parser.h"

bool	parse_textures(t_data *data, char *line, int i)
{
	size_t	start;

	if (data->cubfile->textures[i] || line[2] == '\0')
		return (false);
	else
	{
		start = 2 + skip_spaces(&line[2]);
		if (ft_strlen(&line[start]) == 0)
			return (false);
		data->cubfile->textures[i]
			= ft_substr(line, start, ft_strlen(line) - start);
		if (!data->cubfile->textures[i])
			exit_program(MALLOC_FAIL);
	}
	return (true);
}

bool	xpm_to_img(t_data *data)
{
	int		i;
	int		pixel;
	void	*tmp;

	i = 0;
	pixel = 64;
	while (i < ALL_DIRECTION)
	{
		tmp = data->cubfile->textures[i];
		data->cubfile->textures[i] = mlx_xpm_file_to_image(data->mlx,
				tmp, &pixel, &pixel);
		free_buf((void **)&tmp);
		if (!data->cubfile->textures[i])
		{
			free_mlx(data, i);
			return (false);
		}
		i++;
	}
	return (true);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfumiya <kfumiya@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 18:51:45 by mmasubuc          #+#    #+#             */
/*   Updated: 2022/06/14 09:53:54 by kfumiya          ###   ########.fr       */
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
	void	*tmp;
	t_image	*imgs[ALL_DIRECTION];

	i = 0;
	imgs[0] = &data->tex_n;
	imgs[1] = &data->tex_s;
	imgs[2] = &data->tex_w;
	imgs[3] = &data->tex_e;
	while (i < ALL_DIRECTION)
	{
		tmp = data->cubfile->textures[i];
		read_image(data, imgs[i], tmp);
		free_buf((void **)&tmp);
		if (!imgs[i]->img)
		{
			free_mlx(data, i);
			return (false);
		}
		i++;
	}
	return (true);
}

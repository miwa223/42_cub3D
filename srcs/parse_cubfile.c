/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cubfile.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasubuc <mmasubuc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 18:09:38 by mmasubuc          #+#    #+#             */
/*   Updated: 2022/06/05 23:34:29 by mmasubuc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parser.h"

void	parse_cubfile(t_data *data, char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	data->cubfile = (t_cubfile *)malloc(sizeof(t_cubfile));
	if (!data->cubfile)
		exit_program(MALLOC_FAIL);
	init_mlx(data);
	count_row_col(data->cubfile, fd);
	if (close(fd) == ERROR)
	{
		free_buf((void **)&(data->cubfile));
		exit_program(CLOSE_FAIL);
	}
	get_map(data, file);
}

void	init_mlx(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
	{
		free(data->cubfile);
		exit_program(MLX_INIT_FAIL);
	}
	data->mlx_win = mlx_new_window(data->mlx, 1200, 720, "cub3D");
	if (!data->mlx_win)
	{
		free(data->cubfile);
		mlx_destroy_display(data->mlx);
		exit_program(MLX_NEW_WINDOW_FAIL);
	}
}

void	count_row_col(t_cubfile *file, int fd)
{
	char	*line;
	int		status;

	file->map_row = 0;
	file->map_col = 0;
	status = 1;
	while (status != EOF_READ)
	{
		status = get_next_line(fd, &line);
		file->map_row += 1;
		file->map_col = get_max_value(file->map_col, ft_strlen(line));
		free_buf((void **)&line);
	}
}

void	get_map(t_data *data, char *file)
{
	int		fd;
	size_t	i;

	i = 0;
	data->cubfile->map
		= (char **)malloc(sizeof(char *) * data->cubfile->map_row);
	if (!data->cubfile->map)
	{
		free_buf((void **)&(data->cubfile));
		exit_program(MALLOC_FAIL);
	}
	fd = open(file, O_RDONLY);
	while (i < data->cubfile->map_row)
	{
		get_next_line(fd, &data->cubfile->map[i]);
		i++;
	}
	if (close(fd) == ERROR)
	{
		free_2d_array(data->cubfile->map);
		free_buf((void **)&(data->cubfile));
		exit_program(CLOSE_FAIL);
	}
}

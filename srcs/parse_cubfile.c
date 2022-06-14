/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cubfile.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfumiya <kfumiya@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 18:09:38 by mmasubuc          #+#    #+#             */
/*   Updated: 2022/06/13 15:03:48 by kfumiya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parser.h"

void	parse_cubfile(t_data *data, char *file)
{
	int	fd;
	int	status;

	fd = open(file, O_RDONLY);
	get_info(data, fd);
	status = xpm_to_img(data);
	if (status != ALL_DIRECTION)
		exit_program(XPM_TO_IMG_FAIL, data, status);
	if (!count_row_col(data, fd))
		exit_program(INVALID_MAP, data, ALL_DIRECTION);
	if (close(fd) == ERROR)
	{
		free_buf((void **)&(data->cubfile));
		exit_program(CLOSE_FAIL, data, ALL_DIRECTION);
	}
	parse_map(data, file);
}

void	get_info(t_data *data, int fd)
{
	char	*line;
	int		status;
	int		cnt;
	char	**types;

	status = 1;
	cnt = 0;
	types = set_types();
	if (!types)
		exit_program(MALLOC_FAIL, data, 0);
	while (status != EOF_READ && cnt < NB_TYPE)
	{
		status = get_next_line(fd, &line, data, 0);
		if (ft_strlen(line) == 0)
		{
			if (cnt == 0)
				exit_program(INVALID_CUBFILE, data, 0);
			continue ;
		}
		if (!check_type(data, line, types))
			exit_program(INVALID_CUBFILE, data, 0);
		cnt++;
	}
	free(types);
}

char	**set_types(void)
{
	char	**types;

	types = (char **)malloc(sizeof(char *) * NB_TYPE);
	if (!types)
		return (NULL);
	types[0] = "NO";
	types[1] = "SO";
	types[2] = "WE";
	types[3] = "EA";
	types[4] = "F";
	types[5] = "C";
	return (types);
}

bool	check_type(t_data *data, char *line, char **types)
{
	int		i;

	i = 0;
	bool (*funcs[2])(t_data *, char *, int) = {parse_textures, parse_color};
	while (i < NB_TYPE)
	{
		if (ft_strnstr(line, types[i], ft_strlen(types[i])))
			return (funcs[i / 4](data, line, i));
		i++;
	}
	return (false);
}

bool	count_row_col(t_data *data, int fd)
{
	char	*line;
	int		status;
	int		cnt;

	status = 1;
	cnt = 0;
	while (status != EOF_READ)
	{
		status = get_next_line(fd, &line, data, ALL_DIRECTION);
		if (ft_strlen(line) == 0)
		{
			free_buf((void **)&line);
			if (cnt == 0 || status == EOF_READ)
				continue ;
			return (false);
		}
		data->cubfile->map_row += 1;
		data->cubfile->map_col = get_max_value(data->cubfile->map_col, ft_strlen(line));
		free_buf((void **)&line);
		cnt++;
	}
	if (data->cubfile->map_row <= 2 || data->cubfile->map_col <= 2)
		return (false);
	return (true);
}

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

	fd = open(file, O_RDONLY);
	get_info(data, fd);
	if (!count_row_col(data->cubfile, fd))
		exit_program(INVALID_MAP);
	if (close(fd) == ERROR)
	{
		free_buf((void **)&(data->cubfile));
		exit_program(CLOSE_FAIL);
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
	while (status != EOF_READ && cnt < NB_TYPE)
	{
		status = get_next_line(fd, &line);
		if (ft_strlen(line) == 0)
		{
			if (cnt == 0)
				exit_program(INVALID_CUBFILE);
			continue ;
		}
		if (!check_type(data, line, types))
			exit_program(INVALID_CUBFILE);
		cnt++;
	}
	free(types);
	if (!xpm_to_img(data))
		exit_program(XPM_TO_IMG_FAIL);
}

char	**set_types(void)
{
	char	**types;

	types = (char **)malloc(sizeof(char *) * NB_TYPE);
	if (!types)
		exit_program(MALLOC_FAIL);
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

bool	count_row_col(t_cubfile *file, int fd)
{
	char	*line;
	int		status;
	int		cnt;

	status = 1;
	cnt = 0;
	while (status != EOF_READ)
	{
		status = get_next_line(fd, &line);
		if (ft_strlen(line) == 0)
		{
			free_buf((void **)&line);
			if (cnt == 0 || status == EOF_READ)
				continue ;
			return (false);
		}
		file->map_row += 1;
		file->map_col = get_max_value(file->map_col, ft_strlen(line));
		free_buf((void **)&line);
		cnt++;
	}
	if (file->map_row <= 2 || file->map_col <= 2)
		return (false);
	return (true);
}

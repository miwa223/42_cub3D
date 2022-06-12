/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasubuc <mmasubuc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 18:54:01 by mmasubuc          #+#    #+#             */
/*   Updated: 2022/06/12 22:35:06 by mmasubuc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "parser.h"

void	parse_map(t_data *data, char *file)
{
	int		fd;
	char	**map_dup;

	data->cubfile->map
		= (char **)malloc(sizeof(char *) * (data->cubfile->map_row + 1));
	if (!data->cubfile->map)
		exit_program(MALLOC_FAIL);
	fd = open(file, O_RDONLY);
	read_through_type_info(fd);
	if (!read_map(data, fd))
		exit_program(INVALID_MAP);
	if (close(fd) == ERROR)
		exit_program(CLOSE_FAIL);
	map_dup = make_copy_map(data);
	if (!map_dup)
		exit_program(MALLOC_FAIL);
	if (!is_closed_by_wall(map_dup, data->ppos.pos.x, data->ppos.pos.y, data))
		exit_program(INVALID_MAP);
	free_2d_array(map_dup);
}

void	read_through_type_info(int fd)
{
	char	*line;
	size_t	i;

	i = 0;
	while (i < NB_TYPE)
	{
		get_next_line(fd, &line);
		if (ft_strlen(line) != 0)
			i++;
		free_buf((void **)&line);
	}
}

bool	read_map(t_data *data, int fd)
{
	size_t	i;

	i = 0;
	while (i < data->cubfile->map_row)
	{
		get_next_line(fd, &data->cubfile->map[i]);
		if (ft_strlen(data->cubfile->map[i]) == 0)
			continue ;
		if (!get_ppos(data, data->cubfile->map[i], i))
			return (false);
		i++;
	}
	data->cubfile->map[i] = NULL;
	return (true);
}

bool	get_ppos(t_data *data, char *line, int row)
{
	int	col;
	int	llen;

	col = 0;
	llen = ft_strlen(line);
	if (llen == 0)
		return (false);
	while (line[col] != '\0')
	{
		if (ft_strchr("NSWE", line[col]))
		{
			if (data->ppos.direction != ALL_DIRECTION)
				return (false);
			data->ppos.pos.x = row;
			data->ppos.pos.y = col;
			data->ppos.direction = line[col];
		}
		else if (!ft_strchr(" 01", line[col]))
			return (false);
		col++;
	}
	return (true);
}

bool	is_closed_by_wall(char **map, size_t row, size_t col, t_data *data)
{
	if (row < 0 || row >= data->cubfile->map_row
		|| col < 0 || col >= data->cubfile->map_col)
		return (false);
	if (map[row][col] == ' ' || map[row][col] == '\0')
		return (false);
	if (map[row][col] == '1' || map[row][col] == 'X')
		return (true);
	map[row][col] = 'X';
	return (is_closed_by_wall(map, row + 1, col, data)
		&& is_closed_by_wall(map, row - 1, col, data)
		&& is_closed_by_wall(map, row, col + 1, data)
		&& is_closed_by_wall(map, row, col - 1, data));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfumiya <kfumiya@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 18:04:49 by mmasubuc          #+#    #+#             */
/*   Updated: 2022/06/13 13:43:07 by kfumiya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <stdbool.h>
# include <fcntl.h>
# include "get_next_line.h"

// parse_cubfiles.c
void		parse_cubfile(t_data *data, char *file);
void		get_info(t_data *data, int fd);
bool		check_type(t_data *data, char *line, char **types);
char		**set_types(void);
bool		count_row_col(t_cubfile *file, int fd);

// parse_textures.c
bool		parse_textures(t_data *data, char *line, int i);
bool		xpm_to_img(t_data *data);

// parse_colors.c
bool		parse_color(t_data *data, char *line, int i);
bool		get_color(t_data *data, int index, char *line);
bool		is_valid_num(char **s_nums, int *nums);
uint32_t	rgb_to_hex(int red, int green, int blue);

// parse_map.c
void		parse_map(t_data *data, char *file);
void		read_through_type_info(int fd);
bool		read_map(t_data *data, int fd);
bool		get_ppos(t_data *data, char *line, int row);
bool		is_closed_by_wall(char **map, size_t row, size_t col, t_data *data);

#endif

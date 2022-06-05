/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasubuc <mmasubuc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 18:04:49 by mmasubuc          #+#    #+#             */
/*   Updated: 2022/06/05 22:59:24 by mmasubuc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <stdbool.h>
# include <fcntl.h>
# include "get_next_line.h"

void	parse_cubfile(t_data *data, char *file);
void	init_mlx(t_data *data);
void	count_row_col(t_cubfile *file, int fd);
void	get_map(t_data *data, char *file);

#endif

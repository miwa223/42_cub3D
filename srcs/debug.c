/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasubuc <mmasubuc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 22:54:13 by mmasubuc          #+#    #+#             */
/*   Updated: 2022/06/05 22:54:14 by mmasubuc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "cub3d.h"

void	print_data(t_data *data)
{
	size_t	i;

	i = 0;
	if (!data)
		return ;
	if (data->cubfile)
	{
		printf("row: %zu, col: %zu\n",
			data->cubfile->map_row, data->cubfile->map_col);
		while (i < data->cubfile->map_row)
			printf("m: %s\n", data->cubfile->map[i++]);
	}
}

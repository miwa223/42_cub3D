/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasubuc <mmasubuc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 18:07:05 by mmasubuc          #+#    #+#             */
/*   Updated: 2022/06/12 19:06:24 by mmasubuc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	exit_program(char *msg)
{
	ft_putstr_fd("Error\n", 2);
	ft_putendl_fd(msg, 2);
	exit(EXIT_FAILURE);
}

int	close_window(t_data *data)
{
	free_mlx(data, ALL_DIRECTION);
	free_2d_array(data->cubfile->map);
	free(data->cubfile);
	exit(EXIT_SUCCESS);
}

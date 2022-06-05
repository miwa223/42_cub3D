/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasubuc <mmasubuc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 18:07:05 by mmasubuc          #+#    #+#             */
/*   Updated: 2022/06/05 22:43:58 by mmasubuc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	exit_program(char *msg)
{
	ft_putstr_fd("Error\n", 2);
	ft_putendl_fd(msg, 2);
	exit(EXIT_FAILURE);
}

void	free_buf(void **buf)
{
	free(*buf);
	*buf = NULL;
}

int	close_window(t_data *data)
{
	free_2d_array(data->cubfile->map);
	free(data->cubfile);
	mlx_destroy_window(data->mlx, data->mlx_win);
	mlx_destroy_display(data->mlx);
	exit(EXIT_SUCCESS);
}

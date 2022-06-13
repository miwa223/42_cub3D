/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
<<<<<<< HEAD:srcs/error.c
/*   error.c                                            :+:      :+:    :+:   */
=======
/*   exit.c                                             :+:      :+:    :+:   */
>>>>>>> main:srcs/exit.c
/*                                                    +:+ +:+         +:+     */
/*   By: kfumiya <kfumiya@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD:srcs/error.c
/*   Created: 2022/06/04 10:04:36 by kfumiya           #+#    #+#             */
/*   Updated: 2022/06/07 12:56:16 by kfumiya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

void
	put_err_msg(char *msg)
{
	write(STDERR_FILENO, "Error: ", ft_strlen("Error: "));
	write(STDERR_FILENO, msg, ft_strlen(msg));
	write(STDERR_FILENO, "\n", 1);
}

int
	return_error_msg(char *msg)
{
	put_err_msg(msg);
	return (ERROR);
=======
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
>>>>>>> main:srcs/exit.c
}

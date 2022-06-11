/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfumiya <kfumiya@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 18:39:32 by mmasubuc          #+#    #+#             */
/*   Updated: 2022/06/11 08:58:58 by kfumiya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

int	main(int argc, char *argv[])
{
	t_data	data;

	(void)argc;
	(void)argv;
	set_data(&data);
	print_map(&data);
	set_screen(&data);
	mlx_hook(data.win, KeyPress, KeyPressMask, key_press, &data);
	mlx_hook(data.win, KeyRelease, KeyReleaseMask, key_release, &data);
	mlx_hook(data.win, ClientMessage, 1L << 17, close_window, &data);
	mlx_loop_hook(data.mlx, &main_loop, &data);
	mlx_loop(data.mlx);
	return (0);
}

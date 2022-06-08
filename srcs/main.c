/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfumiya <kfumiya@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 18:39:32 by mmasubuc          #+#    #+#             */
/*   Updated: 2022/06/08 09:57:09 by kfumiya          ###   ########.fr       */
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
	mlx_loop_hook(data.mlx, &main_loop, &data);
	mlx_loop(data.mlx);
	return (0);
}

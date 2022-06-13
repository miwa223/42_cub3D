/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasubuc <mmasubuc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 22:48:14 by mmasubuc          #+#    #+#             */
/*   Updated: 2022/06/05 22:59:49 by mmasubuc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	is_valid_argv(int argc, char **argv)
{
	int		i;
	char	*str;

	i = 0;
	str = NULL;
	if (argc != 2)
		exit_program(INVALID_ARG);
	while (argv[1][i] != '\0')
	{
		if (argv[1][i] == '.')
			str = &argv[1][i];
		i++;
	}
	if (!str || ft_strlen(str) != 4
		|| ft_strncmp(str, ".cub", 4) != 0)
		exit_program(INVALID_ARG);
}

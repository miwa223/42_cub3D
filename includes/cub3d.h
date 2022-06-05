/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasubuc <mmasubuc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 18:39:08 by mmasubuc          #+#    #+#             */
/*   Updated: 2022/06/05 23:08:18 by mmasubuc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h> //uint32_t
# include "../mlx/mlx.h"
# include "../mlx/mlx_int.h"
# include "../libft/libft.h"

# define NB_TYPE 6
# define INVALID_ARG "Invalid arguments"
# define MLX_INIT_FAIL "Mlx initialization failed"
# define MLX_NEW_WINDOW_FAIL "Mlx window creation failed"
# define MALLOC_FAIL "Malloc failed"
# define OPEN_FAIL "Open failed"
# define READ_FAIL "Read failed"
# define CLOSE_FAIL "Close failed"
# define INVALID_MAP "Invalid map"

typedef enum e_type
{
	NORTH,
	SOUTH,
	WEST,
	EAST,
	FLOOR = 0,
	CELLING,
}			t_type;

typedef struct s_xy
{
	double	x;
	double	y;
}				t_xy;

typedef struct s_cubfile
{
	t_type		types[NB_TYPE];
	void		*textures[4];
	uint32_t	colors[2];
	size_t		map_row;
	size_t		map_col;
	char		**map;
}				t_cubfile;

typedef struct s_data
{
	void		*mlx;
	void		*mlx_win;
	t_xy		ppos;
	t_cubfile	*cubfile;
}				t_data;

// validation.c
void	is_valid_argv(int argc, char **argv);

// utils.c
size_t	get_max_value(size_t x, size_t y);
void	free_2d_array(char **content);
char	*ft_strjoin_new_line(char const *s1, char const *s2);
char	*ft_strchr_return_next_char(const char *s, int c);

// exit.c
void	exit_program(char *msg);
void	free_buf(void **buf);
int		close_window(t_data *data);

// debug.c
void	print_data(t_data *data);

#endif

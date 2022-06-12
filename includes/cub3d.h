/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasubuc <mmasubuc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 18:39:08 by mmasubuc          #+#    #+#             */
/*   Updated: 2022/06/12 18:38:16 by mmasubuc         ###   ########.fr       */
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
# define XPM_TO_IMG_FAIL "Xpm to image conversion failed"
# define MALLOC_FAIL "Malloc failed"
# define OPEN_FAIL "Open failed"
# define READ_FAIL "Read failed"
# define CLOSE_FAIL "Close failed"
# define INVALID_CUBFILE "Invalid cubfile"
# define INVALID_MAP "Invalid map"

typedef enum e_type
{
	NORTH,
	SOUTH,
	WEST,
	EAST,
	ALL_DIRECTION,
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
	void		*textures[4];
	uint32_t	colors[2];
	size_t		map_row;
	size_t		map_col;
	char		**map;
}				t_cubfile;

typedef struct s_player
{
	t_xy	pos;
	t_type	direction;
}				t_player;

typedef struct s_data
{
	void		*mlx;
	void		*mlx_win;
	t_player	ppos;
	t_cubfile	*cubfile;
}				t_data;

// validation.c
void	is_valid_argv(int argc, char **argv);

// init.c
void	init_data(t_data *data);
void	init_mlx(t_data *data);

// utils.c
size_t	get_max_value(size_t x, size_t y);
char	*ft_strjoin_new_line(char const *s1, char const *s2);
char	*ft_strchr_return_next_char(const char *s, int c);
size_t	skip_spaces(char *line);

// free.c
void	free_2d_array(char **content);
void	free_buf(void **buf);
void	free_mlx(t_data *data, t_type type);

// exit.c
void	exit_program(char *msg);
int		close_window(t_data *data);

// debug.c
void	print_data(t_data *data);

#endif

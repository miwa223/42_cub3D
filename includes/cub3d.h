/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfumiya <kfumiya@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 18:39:08 by mmasubuc          #+#    #+#             */
/*   Updated: 2022/06/15 09:07:20 by kfumiya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdint.h>
# include <math.h>
# include <stdlib.h> //uint32_t
# include "../mlx/mlx.h"
# include "../mlx/mlx_int.h"
# include "../libft/libft.h"

# define MAX(a, b)	((a > b) ? a : b)
# define MIN(a, b)	((a < b) ? a : b)
# define ERROR	-1
# define MAX_MAP_W 200
# define MAX_MAP_H 200
# define MOVE_P (0.033)
# define ROTATE_RAD (M_PI / 300)

# define KEY_A			97
# define KEY_S			115
# define KEY_D			100
# define KEY_W			119
# define KEY_LEFT		65361
# define KEY_RIGHT		65363
# define KEY_ESC		65307
# define KEY_Q			113

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

typedef struct	s_vec2
{
	double		x;
	double		y;
} t_vec2;

typedef struct s_cubfile
{
	void		*textures[4];
	uint32_t	colors[2];
	size_t		map_row;
	size_t		map_col;
	char		**map;
}				t_cubfile;

// 描画するためのイメージ情報を保持
typedef struct	s_image {
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			width;
	int			height;
} t_image;

typedef struct	s_player {
	t_vec2		pos;  // 現在位置(px)[x, y]
	t_vec2		dir;       // 現在向いている方向のベクトル
	t_vec2		plane;     // 2Dレイキャスティング用のカメラ平面
	int			is_moving; // 動くキーが押されているか (W=1, S=-1, None=0)
	int			is_sidling;  // 動くキーが押されているか (D=1, A=-1, None=0)
	int			is_rotating; // 動くキーが押されているか (左矢印=1, 右矢印=-1, None=0)
	t_type		direction;
} t_player;

typedef struct s_data
{
	void		*mlx;
	t_cubfile	*cubfile;
	void		*win;
	t_player	player;
	t_image		img;
	int			screen_width;
	int			screen_height;
	double		horizon;
	uint32_t	sky_color;
	uint32_t	ground_color;
	t_image		tex_n; // 北
	t_image		tex_s; // 南
	t_image		tex_w; // 西
	t_image		tex_e; // 東
	int			tex_width;
	int			tex_height;
	char		**map;
} t_data;

typedef struct	s_ray {
	// カメラ平面上のx座標 (3D表示時の画面のx座標)  -1.0~1.0
	double		camera_x;
	// 光線ベクトル
	t_vec2		dir;
	// map: 現在対象としているマップ内の正方形を表す
	int			map_x;
	int			map_y;
	// sideDistは, 光線が開始位置から最初の次の正方形に移動するまでの距離
	double		side_dist_x;
	double		side_dist_y;
	// perpWallDistは, 当たった壁とカメラ平面ベクトルとの距離を表す (perpはperpendicular(垂直)の略)
	double		perp_wall_dist;
	// 壁のx面かy面どちらに当たったかを判断するための変数  0: x面, 1: y面
	int			side;
	// stepはx,yそれぞれ正か負かどちらの方向に進むか記録する (必ず +1 or -1)
	int			step_x;
	int			step_y;
	// deltaDistは, 光線が今の正方形から次の正方形に行くために移動する距離
	double		delta_dist_x;
	double		delta_dist_y;
	// texは当たった壁のテクスチャ
	t_image		*tex;
	// colorは当たった壁のカラー
	u_int32_t	color;
} t_ray;

typedef struct	s_wall
{
	// スクリーンに描画する必要のある縦線の長さを求める
	int			line_height;
	// 実際に描画すべき場所の開始位置
	int			draw_start;
	// 実際に描画すべき場所の位置
	int			draw_end;
	// 正確なx座標 (整数型ではない)
	double		wall_x;
	// テクスチャ上のx座標 (0~TEXTURE_WIDTH)
	int			texture_x;
	// y方向の1ピクセルごとにテクスチャのy座標が動く量
	double		step;
	// テクスチャの現在のy座標
	double		texture_pos_y;
	// テクスチャの現在のy座標(double型)を整数型に変換する.
	int			texture_y;
} t_wall;

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
char	**make_copy_map(t_data *data);

// free.c
void	free_2d_array(char **content);
void	free_buf(void **buf);
void	free_mlx(t_data *data, t_type type);
void	free_data(t_data *data);

// exit.c
void	exit_program(char *msg, t_data *data, t_type type);
int		close_window(t_data *data);

// debug.c
void	print_data(t_data *data);


/* draw_wall.c */
void draw_wall(t_data *data);
/* errors.c */
int return_error_msg(char *msg);
void put_err_msg(char *msg);
/* game.c */
void set_screen(t_data *data);
int main_loop(t_data *data);
/* init_player.c */
void init_player(t_player *player, double x, double y, char dir);
/* mlx_utils.c */
void my_mlx_pixel_put(t_image *img, int x, int y, int color);
u_int32_t get_color_pix(t_image img, int x, int y);
int read_image(t_data *data, t_image *img, char *filepath);
/* set_data.c */
void set_data(t_data *data);
void set_tex(t_data *data);
/* vector.c */
double vec_length(t_vec2 vec);
double deg_rad(int x);
void vec_rotate(t_vec2 *vec, double rad);
/* wall_utils.c */
void set_wall_color(t_data *data, t_ray *ray);
void set_texture(t_data *data, t_ray *ray);
/* debug.c */
void print_map(t_data *data);
void print_ray(t_ray ray);
void print_wall(t_wall wall);
void print_da(t_data *data);
void print_image(t_data *data);
void print_info(t_data *data);
/* player.c */
void update_player(t_data *data);
/* hook.c */
int exit_window(t_data *data);
int key_press(int keycode, t_data *data);
int key_release(int keycode, t_data *data);
/* convert_info.c */
void convert_info(t_data *data);

#endif

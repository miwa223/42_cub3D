/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfumiya <kfumiya@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 10:10:55 by kfumiya           #+#    #+#             */
/*   Updated: 2022/06/06 11:59:56 by kfumiya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "cub3d.h"
# include "utils.h"
# include <stdint.h>
# include <math.h>

# define MAX(a, b)	((a > b) ? a : b)
# define MIN(a, b)	((a < b) ? a : b)
# define ERROR	-1
# define MAX_MAP_W 200
# define MAX_MAP_H 200

typedef struct	s_vec2 {
	double		x;
	double		y;
} t_vec2;

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
} t_player;

// 入力情報を保存
typedef struct s_data {
	void		*mlx;
	void		*win;
	t_image		img;
	int			screen_width;
	int			screen_height;
	t_player	player;
	char		**map;
	int			map_row;
	int			map_col;
	double		horizon;
	double		*z_buffer;
	uint32_t	sky_color;
	uint32_t	ground_color;
	uint32_t	nouth_color;
	uint32_t	south_color;
	uint32_t	west_color;
	uint32_t	east_color;
	// t_image		tex_n; // 北
	// t_image		tex_s; // 南
	// t_image		tex_w; // 西
	// t_image		tex_e; // 東
	// int			tex_width;
	// int			tex_height;
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
u_int32_t get_color(t_image img, int x, int y);
/* set_data.c */
void set_data(t_data *data);
/* vector.c */
double vec_length(t_vec2 vec);
double deg_rad(int x);
void vec_rotate(t_vec2 *vec, double rad);
/* wall_utils.c */
void set_wall_color(t_data *data, t_ray *ray);
void set_texture(t_data *data, t_ray *ray);

#endif

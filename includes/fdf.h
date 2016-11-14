/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleury <bfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 10:46:42 by bfleury           #+#    #+#             */
/*   Updated: 2016/11/14 02:17:51 by bfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_T			"- FdF -"
# define FDF_W			600
# define FDF_H			400
# define FDF_ZOOM		20
# define FDF_ZOOM_MAX	100
# define FDF_AMP_MAX	10

# define BLUE	c.red = 42;		c.green = 42;		c.blue = 255;
# define YELLOW	c.red = 255;	c.green = 255;		c.blue = 0;
# define BROWN	c.red = 153;	c.green = 102;		c.blue = 0;
# define GREEN	c.red = 51;		c.green = 255;		c.blue = 51;
# define GREY	c.red = 42;		c.green = 42;		c.blue = 42;
# define WHITE	c.red = 255;	c.green = 255;		c.blue = 255;

# include "../../GNL/includes/get_next_line.h"
# include "../minilibx/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>

typedef struct			s_bres
{
	int					dx;
	int					dy;
	int					sx;
	int					sy;
	int					err;
	int					e2;
}						t_bres;

typedef struct			s_color
{
	unsigned char		red;
	unsigned char		green;
	unsigned char		blue;
}						t_color;


typedef struct			s_point
{
	int					x;
	int					y;
	int					z;
}						t_point;

typedef struct			s_map
{
	int					width;
	int					height;
	int					x;
	int					y;
	int					view;
	int					amp;
	float				inclin;
	char				*file;
	int					**tab;
}						t_map;

typedef struct			s_image
{
	void				*ptr;
	char				*data;
	int					zoom;
	int					bpp;
	int					sl;
	int					e;
}						t_image;

typedef struct			s_window
{
	void				*ptr;
	int					width;
	int					height;
	char				*title;
}						t_window;

typedef struct			s_mlx
{
	void				*ptr;
	struct s_window		win;
	struct s_image		img;
	struct s_map		map;
}						t_mlx;


void					quit(t_mlx *mlx);
void					clean(t_mlx *mlx);
void					reset(t_mlx *mlx);
void					die(t_mlx *mlx, char *msg);
void					init(int width, int height, char *title, char *file);

void					image_put_pixel(t_mlx *mlx, t_point a, t_color c);
void					trace_segment(t_mlx *mlx, t_point a, t_point b);

int						get_nb_line(t_mlx *mlx);
int						**parse_map(t_mlx *mlx);

// t_point					create_point(t_mlx *mlx, int x, int y, int z);
t_point					create_point(t_mlx *mlx, int y, int z);
void					draw_map(t_mlx *mlx);

int						loop_hook(t_mlx *mlx);
void					deep(t_mlx *mlx, int key);
void					zoom(t_mlx *mlx, int key);
void					move(t_mlx *mlx, int key);
int						key_hook(int keycode, t_mlx *mlx);

void					init_color(t_point *a, int z);
void					tab_to_iso(t_mlx *mlx);
t_point					cal_i(int y, int x, int z, t_mlx *mlx);

#endif

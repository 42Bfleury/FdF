/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleury <bfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 10:46:42 by bfleury           #+#    #+#             */
/*   Updated: 2016/11/10 02:09:09 by bfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_T			"- FdF -"
# define FDF_W			1280
# define FDF_H			720
# define FDF_ZOOM		31
# define FDF_ZOOM_MAX	100
# define FDF_AMP_MAX	10

# define BLUE	{ a->red = 44; a->green = 117; a->blue = 255; }
# define YELLOW	{ a->red = 255; a->green = 255; a->blue = 0; }
# define BROWN	{ a->red = 153; a->green = 102; a->blue = 0; }
# define GREEN	{ a->red = 51; a->green = 255; a->blue = 51; }
# define GREY	{ a->red = 96; a->green = 96; a->blue = 96; }
# define WHITE	{ a->red = 255; a->green = 255; a->blue = 255; }

# include "../../GNL/get_next_line.h"
# include "../minilibx/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>

typedef struct		s_bress
{
	int				dx;
	int				dy;
	int				sx;
	int				sy;
	int				err;
	int				e2;
}					t_bress;

typedef struct			s_point
{
	int					x;
	int					y;
	int					z;
	unsigned char		red;
	unsigned char		green;
	unsigned char		blue;
}						t_point;

typedef struct			s_map
{
	int					width;
	int					height;
	int					x;
	int					y;
	int					amp;
	float				inclin;
	char				*file;
	int					**tab;
}						t_map;

typedef struct			s_image
{
	void				*ptr;
	char				*data;
	int					x;
	int					y;
	int					width;
	int					height;
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

t_point					create_point(t_mlx *mlx, int x, int y, int z);
int						**parse_map(t_mlx *mlx);

void					deep(t_mlx *mlx, int key);
void					die(t_mlx *mlx, char *str);
void					clean(t_mlx *mlx);
void					draw_map(t_mlx *mlx);
void					zoom(t_mlx *mlx, int key);
void					move(t_mlx *mlx, int key);
void					image_put_pixel(t_mlx *mlx, t_point point);
void					init_color(t_point *a, int z);
void					trace_segment(t_mlx *mlx, t_point a, t_point b);
void					init(int width, int height, char *title, char *file);

int						get_nb_line(t_mlx *mlx);
int						loop_hook(t_mlx *mlx);
int						key_hook(int keycode, t_mlx *mlx);

#endif

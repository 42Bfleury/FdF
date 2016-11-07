/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleury <bfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 10:46:42 by bfleury           #+#    #+#             */
/*   Updated: 2016/11/07 09:11:06 by bfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H			400
# define FDF_W			600
# define FDF_Z			5
# define FDF_T			"- FdF -"
# define FDF_IMG_BPP	32

# include "../GNL/get_next_line.h"
# include "minilibx/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>

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
	struct s_color		color;
}						t_point;

typedef struct			s_map
{
	int					width;
	int					height;
	int					**tab;
	char				*file;
}						t_map;

typedef struct			s_img
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
}						t_img;

typedef struct			s_window
{
	void				*ptr;
	int					width;
	int					height;
}						t_window;

typedef struct			s_mlx
{
	void				*ptr;
	struct s_window		win;
	struct s_img		img;
	struct s_map		map;
}						t_mlx;

t_mlx					init_fdf(int width, int height, char *title, char *file);
void					init_map(char *file, t_mlx *mlx);
void					display_image(t_mlx mlx);
void					image_put_pixel(int x, int y, t_mlx mlx);
void					image_trace_segment(t_point a, t_point b, t_mlx mlx);
void					move_image(int key, t_mlx mlx);
int						key_hook(int keycode, t_mlx mlx);

#endif

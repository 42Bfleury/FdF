/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleury <bfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 10:46:42 by bfleury           #+#    #+#             */
/*   Updated: 2016/11/16 13:07:22 by bfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_T			"- FdF -"
# define FDF_W			600
# define FDF_H			400
# define FDF_ZOOM		42
# define FDF_ZOOM_MAX	100
# define FDF_AMP_MAX	10

# define BLUE	c.red = 42;		c.green = 42;		c.blue = 255;
# define YELLOW	c.red = 255;	c.green = 255;		c.blue = 0;
# define BROWN	c.red = 153;	c.green = 102;		c.blue = 0;
# define GREEN	c.red = 51;		c.green = 255;		c.blue = 51;
# define GREY	c.red = 42;		c.green = 42;		c.blue = 42;
# define WHITE	c.red = 255;	c.green = 255;		c.blue = 255;

# include "../../GNL/includes/get_next_line.h"
# include "../minilibx/includes/mlx.h"
# include <fcntl.h>
# include <math.h>

typedef struct			s_bres
{
	int					dx;
	int					dy;
	int					sx;
	int					sy;
	int					e;
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
	int					amp;
	int					view;
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
	char				*title;
	int					width;
	int					height;
}						t_window;

typedef struct			s_mlx
{
	void				*ptr;
	struct s_window		win;
	struct s_image		img;
	struct s_map		map;
}						t_mlx;

void					quit(t_mlx *mlx);
void					reset(t_mlx *mlx);
void					draw_map(t_mlx *mlx);
void					die(t_mlx *mlx, char *msg);
void					init(int width, int height, char *title, char *file);

int						**parse_map(t_mlx *mlx);
int						get_nb_line(t_mlx *mlx);
int						key_hook(int keycode, t_mlx *mlx);

t_point					create_point(t_mlx *mlx, int y, int z);


#endif

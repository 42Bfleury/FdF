/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 10:46:42 by bfleury           #+#    #+#             */
/*   Updated: 2016/11/03 12:42:30 by bfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define BASE_16 "0123456789abcdef"

# include "../GNL/get_next_line.h"
# include <fcntl.h>
# include <math.h>
# include <mlx.h>

typedef struct		s_node
{
	int				height;
	int				color;
}					t_node;

typedef struct		s_map
{
	int				width;
	int				height;
	t_node			**data;
}					t_map;

typedef struct		s_image
{
	void			*addr;
	int				bpp;
	int				width;
	int				endian;
	char			*data;
}					t_image;

typedef struct		s_event
{
	void			*mlx;
	void			*win;
	int				width;
	int				height;
	int				offx;
	int				offy;
	int				zoom;
	int				cwater;
	int				cground;
	int				crock;
	int				csnow;
	void			(*render)(struct s_event *);
	t_image			img;
	t_map			map;
}					t_event;

typedef struct		s_color
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}					t_color;

typedef struct		s_point
{
	int				x;
	int				y;
}					t_point;

void				load_map(t_event *e, char *path);
int					expose_hook(t_event *ev);
int					key_hook(int keycode, t_event *ev);
void				iso(t_event *e);
void				parallel(t_event *e);
void				conical(t_event *e);
void				draw_pixel(t_event *e, int x, int y, t_color *c);
void				draw_point(t_event *e, t_point *p, t_color *c, int r);
t_color				*icolor(t_color *c0, t_color *c1, double t);
t_color				*inewcolor(int ca, int cb, double t);
t_color				*new_color(int color);
t_point				*get_point(int x, int y);
t_point				*get_iso_point(int x, int y, int h);
t_point				*get_par_point(int x, int y, int h);
t_point				*get_con_point(int x, int y, int h, double angle);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleury <bfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 10:46:42 by bfleury           #+#    #+#             */
/*   Updated: 2016/11/06 11:08:06 by bfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

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
	int					offset_x;
	int					offset_y;
}						t_point;

typedef struct			s_map
{
	int					width;
	int					height;
	int					**int_tab;
	char				*file;
}						t_map;

typedef struct			s_img
{
	void				*ptr;
	void				*addr;
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

void					trace_segment(t_mlx mlx, t_point a, t_point b, int color);
void 					convert_map(t_mlx mlx);

#endif

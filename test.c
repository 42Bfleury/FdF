/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleury <bfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 00:29:38 by bfleury           #+#    #+#             */
/*   Updated: 2016/11/06 11:26:11 by bfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*static t_point		create_point(int x, int y)
{
	t_point		point;

	point.x = x;
	point.y = y;
	return (point);
}

static void			test_carre(t_mlx mlx)
{
	t_point		a;
	t_point 	b;
	t_point 	c;
	t_point 	d;

	a = create_point(275, 175);
	b = create_point(324, 175);
	c = create_point(324, 224);
	d = create_point(275, 224);
	//a = create_point(0, 0);
	//b = create_point(10, 0);
	//c = create_point(10, 10);
	//d = create_point(0, 10);
	trace_segment(mlx, a, b, 0xFFFFFF);
	trace_segment(mlx, b, c, 0xFFFFFF);
	trace_segment(mlx, c, d, 0xFFFFFF);
	trace_segment(mlx, d, a, 0xFFFFFF);
	trace_segment(mlx, a, c, 0xFFFFFF);
	trace_segment(mlx, b, d, 0xFFFFFF);
}*/

static	t_mlx		init_mlx(int width, int height, char *title)
{
	t_mlx	mlx;
	t_img	img;
	int		bpp;
	int		size_line;
	int		endian;

	bpp = 32;
	size_line = width;
	endian = 1;
	if (!(mlx.ptr = mlx_init()))
		exit(-1);
	if (!(mlx.win.ptr = mlx_new_window(mlx.ptr, width, height, title)))
		exit(-1);
	if (!(img.ptr = mlx_new_image(mlx.ptr, width, height)))
		exit(-1);
	//if (!(img.addr = mlx_get_data_addr(img.ptr, &bpp, &size_line, &endian)))
		//exit(-1);
	mlx.win.width = width;
	mlx.win.height = height;
	mlx.img = img;
	return (mlx);
}

static int			key_hook(int keycode)
{
	if (keycode == 53)
		exit (0);
	return (0);
}

int					main(void)
{
	t_mlx		mlx;
	int			width;
	int			height;

	width = 600;
	height = 400;
	mlx.map.file = "map/plat.fdf";
	mlx = init_mlx(width, height, "42 - FdF");
	mlx_string_put(mlx.ptr, mlx.win.ptr, 10, 10, 0xFFFFFF, "Test");
	mlx_key_hook(mlx.win.ptr, key_hook, &mlx);
	if (!mlx_loop(mlx.ptr))
		return (-1);
	return (0);
}

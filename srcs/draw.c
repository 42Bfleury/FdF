
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   segment.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleury <bfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 07:51:58 by bfleury           #+#    #+#             */
/*   Updated: 2016/11/09 21:39:51 by bfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_color	get_color(int z1, int z2)
{
	t_color		c;

	// if ((z1 < 0 && z2 <= 0) || (z1 <= 0 && z2 < 0))
	if (z1 < 0 || z2 < 0)
	{
		BLUE;
	}
	else if (!z1 && !z2)
	{
		BROWN;
	}
	else if ((z1 >= 0 && z1 <= 1) && (z2 >= 0 && z2 <= 1))
	{
		GREEN;
	}
	else if (z1 < 10 || z2 < 10)
	{
		GREY;
	}
	else
	{
		WHITE;
	}
	return (c);
}

void	image_put_pixel(t_mlx *mlx, t_point a, t_color c)
{
	if (0 <= a.x && a.x < mlx->win.width && 0 <= a.y && a.y < mlx->win.height)
	{
		mlx->img.data[(mlx->img.sl * a.y) + (4 * a.x) + 2] = c.red;
		mlx->img.data[(mlx->img.sl * a.y) + (4 * a.x) + 1] = c.green;
		mlx->img.data[(mlx->img.sl * a.y) + (4 * a.x)] = c.blue;
	}
}

void	trace_segment(t_mlx *mlx, t_point a, t_point b)
{
	t_bres		bres;

	bres.dx = abs((b.x - a.x));
	bres.sx = a.x < b.x ? 1 : -1;
	bres.dy = abs((b.y - a.y));
	bres.sy = a.y < b.y ? 1 : -1;
	bres.err = (bres.dx > bres.dy ? bres.dx : -bres.dy) / 2;
	while (!(a.x == b.x && a.y == b.y))
	{
		image_put_pixel(mlx, a, get_color(a.z, b.z));
		bres.e2 = bres.err;
		if (bres.e2 > -bres.dx)
		{
			bres.err -= bres.dy;
			a.x += bres.sx;
		}
		if (bres.e2 < bres.dy)
		{
			bres.err += bres.dx;
			a.y += bres.sy;
		}
	}
}

void	draw_map(t_mlx *mlx)
{
	int			x;
	int			y;
	t_point		a;

	y = 0;
	// ft_bzero(mlx->img.data, (mlx->win.width * mlx->win.height * 4));
	if (!(mlx->img.ptr = mlx_new_image(mlx->ptr, mlx->win.width, mlx->win.height)))
		die(NULL, "ERROR: Failed to create new image!");
	if (!(mlx->img.data = mlx_get_data_addr(mlx->img.ptr, &mlx->img.bpp, &mlx->img.sl, &mlx->img.e)))
		die(NULL, "ERROR: Failed to get the image data address!");
	while (y < mlx->map.height)
	{
		x = 0;
		while (x <= mlx->map.tab[y][0])
		{
			a = create_point(mlx, x, y);
			if(x < mlx->map.tab[y][0])
				trace_segment(mlx, a, create_point(mlx, (x + 1), y));
			if(y < mlx->map.height - 1)
				trace_segment(mlx, a, create_point(mlx, x, (y + 1)));
			x++;
		}
		y++;
	}
}

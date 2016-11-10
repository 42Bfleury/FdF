
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

void			init_color(t_point *a, int z)
{
	if (z < 0)
		BLUE;
	if (z >= 0 && z <= 2)
		YELLOW;
	if (z > 2 && z <= 5)
		BROWN;
	if (z > 5 && z <= 10)
		GREEN;
	if (z > 10 && z <= 20)
		GREY;
	if (z > 20)
		WHITE;
}

t_point			cal_i(int y, int x, int z, t_mlx *mlx)
{
	t_point	point;

	point.x = mlx->map.x + ((x * mlx->img.zoom) - (y * mlx->img.zoom));
	point.y = mlx->map.y - ((sqrt(2.0 / 3.0) * (z * mlx->img.zoom / mlx->map.amp)) -
			((1 / sqrt(mlx->map.inclin)) * (mlx->img.zoom * (x + y))));
	return (point);
}

void			tab_to_iso(t_mlx *mlx)
{
	int		x;
	int		y;
	t_point	a;
	t_point	b;

	y = 0;
	while (y < mlx->map.height)
	{
		x = 1;
		while (x <= mlx->map.tab[y][0])
		{
			a = cal_i(y, x, mlx->map.tab[y][x], mlx);
			x++;
			if (x < mlx->map.tab[y][0])
			{
				b = cal_i(y, x, mlx->map.tab[y][x], mlx);
				trace_segment(mlx, a, b);
			}
			if (y < mlx->map.height - 1)
			{
				b = cal_i(y + 1, x - 1, mlx->map.tab[y + 1][x - 1], mlx);
				trace_segment(mlx, a, b);
			}
		}
		y++;
	}
}

void	trace_segment(t_mlx *mlx, t_point a, t_point b)
{
	t_bress		bres;

	bres.dx = abs((b.x - a.x));
	bres.sx = a.x < b.x ? 1 : -1;
	bres.dy = abs((b.y - a.y));
	bres.sy = a.y < b.y ? 1 : -1;
	bres.err = (bres.dx > bres.dy ? bres.dx : -bres.dy) / 2;
	while (!(a.x == b.x && a.y == b.y))
	{
		init_color(&a, a.z);
		image_put_pixel(mlx, a);
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

/*static void		first_quarter(t_mlx *mlx, t_point a, t_point b)
{
	int		dx;
	int		dy;
	int		e;

	dx = b.x - a.x;
	dy = b.y - a.y;
	e = (dx >= dy) ? dx : dy;
	dx *= 2;
	dy *= 2;
	while (1)
	{
		image_put_pixel(mlx, a);
		if ((dx >= dy && ++a.x == b.x) || (dx < dy && ++a.y == b.y))
			break ;
		if (dx >= dy && (e -= dy) < 0)
		{
			a.y++;
			e += dx;
		}
		else if (dx < dy && (e -= dx) < 0)
		{
			a.x++;
			e += dy;
		}
	}
}

static void		second_quarter(t_mlx *mlx, t_point a, t_point b)
{
	int		dx;
	int		dy;
	int		e;

	dx = b.x - a.x;
	dy = b.y - a.y;
	e = (-dx >= dy) ? dx : dy;
	dx *= 2;
	dy *= 2;
	while (1)
	{
		image_put_pixel(mlx, a);
		if ((-dx >= dy && --a.x == b.x) || (-dx < dy && ++a.y == b.y))
			break ;
		if (-dx >= dy && (e += dy) >= 0)
		{
			a.y++;
			e += dx;
		}
		if (-dx < dy && (e += dx) <= 0)
		{
			a.x--;
			e += dy;
		}
	}
}

static void		third_quarter(t_mlx *mlx, t_point a, t_point b)
{
	int		dx;
	int		dy;
	int		e;

	dx = b.x - a.x;
	dy = b.y - a.y;
	e = (dx <= dy) ? dx : dy;
	dx *= 2;
	dy *= 2;
	while (1)
	{
		image_put_pixel(mlx, a);
		if ((dx <= dy && --a.x == b.x) || (dx > dy && --a.y == b.y))
			break ;
		if (dx <= dy && (e -= dy) >= 0)
		{
			a.y--;
			e += dx;
		}
		else if (dx > dy && (e -= dx) >= 0)
		{
			a.x--;
			e += dy;
		}
	}
}

static void		fourth_quarter(t_mlx *mlx, t_point a, t_point b)
{
	int		dx;
	int		dy;
	int		e;

	dx = b.x - a.x;
	dy = b.y - a.y;
	e = (dx < -dy) ? dy : dx;
	dx *= 2;
	dy *= 2;
	while (1)
	{
		image_put_pixel(mlx, a);
		if ((dx >= dy && ++a.x == b.x) || (dx < -dy && --a.y == b.y))
			break ;
		if (dx >= -dy && (e += dy) < 0)
		{
			a.y--;
			e += dx;
		}
		else if (dx < -dy && (e += dx) > 0)
		{
			a.x++;
			e += dy;
		}
	}
}

void			trace_segment(t_mlx *mlx, t_point a, t_point b)
{
	int		dx;
	int		dy;

	dx = b.x - a.x;
	if (dx > 0 && (dy = b.y - a.y) > 0)
		first_quarter(mlx, a, b);
	else if (dx > 0 && dy < 0)
		fourth_quarter(mlx, a, b);
	else if (dx > 0)
		while (a.x++ != b.x)
			image_put_pixel(mlx, a);
	if (dx <= 0 && (dy = b.y - a.y) > 0)
		second_quarter(mlx, a, b);
	else if (dx <= 0 && dy < 0)
		third_quarter(mlx, a, b);
	else if (dx <= 0)
		while (a.x-- != b.x)
			image_put_pixel(mlx, a);
	if (!dx && (dy = b.y - a.y) > 0)
		while (a.y++ != b.y)
			image_put_pixel(mlx, a);
	else if (!dx && dy < 0)
		while (a.y-- != b.y)
			image_put_pixel(mlx, a);
	image_put_pixel(mlx, b);
}*/

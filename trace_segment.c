/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_segment.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleury <bfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 07:51:58 by bfleury           #+#    #+#             */
/*   Updated: 2016/11/06 07:53:00 by bfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		first_quarter(t_mlx mlx, t_point a, t_point b, int color)
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
		mlx_pixel_put(mlx.ptr, mlx.win.ptr, a.x, a.y, color);
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

static void		second_quarter(t_mlx mlx, t_point a, t_point b, int color)
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
		mlx_pixel_put(mlx.ptr, mlx.win.ptr, a.x, a.y, color);
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

static void		third_quarter(t_mlx mlx, t_point a, t_point b, int color)
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
		mlx_pixel_put(mlx.ptr, mlx.win.ptr, a.x, a.y, color);
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

static void		fourth_quarter(t_mlx mlx, t_point a, t_point b, int color)
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
		mlx_pixel_put(mlx.ptr, mlx.win.ptr, a.x, a.y, color);
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

void			trace_segment(t_mlx mlx, t_point a, t_point b, int color)
{
	int		dx;
	int		dy;

	dx = b.x - a.x;
	if (dx > 0 && (dy = b.y - a.y) > 0)
		first_quarter(mlx, a, b, color);
	else if (dx > 0 && dy < 0)
		fourth_quarter(mlx, a, b, color);
	else if (dx > 0)
		while (a.x++ != b.x)
			mlx_pixel_put(mlx.ptr, mlx.win.ptr, a.x, a.y, color);
	if (dx <= 0 && (dy = b.y - a.y) > 0)
		second_quarter(mlx, a, b, color);
	else if (dx <= 0 && dy < 0)
		third_quarter(mlx, a, b, color);
	else if (dx <= 0)
		while (a.x-- != b.x)
			mlx_pixel_put(mlx.ptr, mlx.win.ptr, a.x, a.y, color);
	if (!dx && (dy = b.y - a.y) > 0)
		while (a.y++ != b.y)
			mlx_pixel_put(mlx.ptr, mlx.win.ptr, a.x, a.y, color);
	else if (!dx && dy < 0)
		while (a.y-- != b.y)
			mlx_pixel_put(mlx.ptr, mlx.win.ptr, a.x, a.y, color);
	mlx_pixel_put(mlx.ptr, mlx.win.ptr, b.x, b.y, color);
}

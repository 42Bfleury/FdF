/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_trace_segment.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleury <bfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 07:51:58 by bfleury           #+#    #+#             */
/*   Updated: 2016/11/07 09:33:14 by bfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		put_pixel(t_point a, t_mlx mlx)
{
	t_mlx		mlx_bis;
	t_point		a_bis;

	mlx_bis = mlx;
	a_bis =a;
}

static void		first_quarter(t_mlx mlx, t_point a, t_point b)
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
		put_pixel(a, mlx);
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

static void		second_quarter(t_mlx mlx, t_point a, t_point b)
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
		put_pixel(a, mlx);
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

static void		third_quarter(t_mlx mlx, t_point a, t_point b)
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
		put_pixel(a, mlx);
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

static void		fourth_quarter(t_mlx mlx, t_point a, t_point b)
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
		put_pixel(a, mlx);
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

void			image_trace_segment(t_point a, t_point b, t_mlx mlx)
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
			put_pixel(a, mlx);
	if (dx <= 0 && (dy = b.y - a.y) > 0)
		second_quarter(mlx, a, b);
	else if (dx <= 0 && dy < 0)
		third_quarter(mlx, a, b);
	else if (dx <= 0)
		while (a.x-- != b.x)
			put_pixel(a, mlx);
	if (!dx && (dy = b.y - a.y) > 0)
		while (a.y++ != b.y)
			put_pixel(a, mlx);
	else if (!dx && dy < 0)
		while (a.y-- != b.y)
			put_pixel(a, mlx);
	put_pixel(b, mlx);
}

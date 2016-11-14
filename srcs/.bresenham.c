/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleury <bfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 12:10:47 by bfleury           #+#    #+#             */
/*   Updated: 2016/11/13 12:10:59 by bfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

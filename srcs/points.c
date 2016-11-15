/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleury <bfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 06:49:52 by bfleury           #+#    #+#             */
/*   Updated: 2016/11/15 15:39:47 by bfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static t_point	get_isometric_view(t_mlx *mlx, int x, int y)
{
	t_point		point;
	
	point.z = mlx->map.tab[y][x] * mlx->map.amp;
	point.x = ((x - y) * mlx->img.zoom) + mlx->map.x;
	point.y = ((x + y) * (mlx->img.zoom / 2)) + mlx->map.y - point.z;
	return (point);
}

static t_point	get_parallel_view(t_mlx *mlx, int x, int y)
{
	t_point		point;

	point.z = mlx->map.tab[y][x] * mlx->map.amp;
	point.x = ((x - y) * mlx->img.zoom) + mlx->map.x;
	point.y = (y * (mlx->img.zoom / 2)) + mlx->map.y - point.z;
	return (point);
}

static t_point	get_conical_view(t_mlx *mlx, int x, int y)
{
	t_point		point;
	double		angle;
	double		r;
	double		c;
	double		s;

	angle = 180.0 / (double)mlx->map.width;
	r = M_PI * (-angle * x + 180.0 - angle / 2.0) / 180.0;
	c = cos(r);
	s = sin(r);
	point.z = mlx->map.tab[y][x] * mlx->map.amp;
	point.x = (int)(c * 32 * y);
	point.y = (int)(s * 32 * y) - point.z;
	return (point);
}

t_point			create_point(t_mlx *mlx, int x, int y)
{
	if (mlx->map.view == 1)
		return (get_isometric_view(mlx, x, y));
	else if (mlx->map.view == 2)
		return (get_parallel_view(mlx, x, y));
	else if (mlx->map.view == 3)
		return (get_conical_view(mlx, x, y));
	die(mlx, "Error: failed to create a point!");
}

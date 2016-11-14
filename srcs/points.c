/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleury <bfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 06:49:52 by bfleury           #+#    #+#             */
/*   Updated: 2016/11/14 11:47:29 by bfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_point		get_isometric_view(t_mlx *mlx, int x, int y)
{
	t_point		point;
	
	point.z = mlx->map.tab[y][x + 1] * mlx->map.amp;
	point.x = ((x - y) * mlx->img.zoom) + mlx->map.x;
	point.y = ((x + y) * (mlx->img.zoom / 2)) + mlx->map.y - point.z;
	return (point);
}

t_point		get_parallel_view(t_mlx *mlx, int x, int y)
{
	t_point		point;

	point.z = mlx->map.tab[y][x + 1] * mlx->img.zoom / mlx->map.amp;
	point.x = mlx->map.x + ((x - y) * mlx->img.zoom);
	point.y = mlx->map.y - ((sqrt(2.0 / 3.0) * point.z)
			- ((1 / sqrt(mlx->map.inclin)) * (mlx->img.zoom * (x + y))));
	return (point);
}

t_point		get_conical_view(t_mlx *mlx, int x, int y)
{
	t_point		point;

	point.x = x;
	point.y = y;
	point.z = mlx->map.tab[y][x + 1];
	return (point);
}

t_point		create_point(t_mlx *mlx, int x, int y)
{
	if (mlx->map.view == 1)
		return (get_isometric_view(mlx, x, y));
	else if (mlx->map.view == 2)
		return (get_parallel_view(mlx, x, y));
	else
		return (get_conical_view(mlx, x, y));
}



/*void		init_color(t_point *a, int z)
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

t_point		cal_i(int y, int x, int z, t_mlx *mlx)
{
	t_point	point;

	point.x = mlx->map.x + ((x * mlx->img.zoom) - (y * mlx->img.zoom));
	point.y = mlx->map.y - ((sqrt(2.0 / 3.0) * (z * mlx->img.zoom / mlx->map.amp)) -
			((1 / sqrt(mlx->map.inclin)) * (mlx->img.zoom * (x + y))));
	return (point);
}

t_point		create_point(t_mlx *mlx, int x, int y, int z)
{
	t_point		point;

	point.z = (z * mlx->map.amp);
	point.x = ((x - y) * mlx->img.zoom) + mlx->map.x;
	point.y = ((x + y) * (mlx->img.zoom / 2)) + mlx->map.y - point.z;
	return (point);
}*/

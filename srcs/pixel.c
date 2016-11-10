/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleury <bfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 06:49:52 by bfleury           #+#    #+#             */
/*   Updated: 2016/11/10 01:39:08 by bfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_point		create_point(t_mlx *mlx, int x, int y, int z)
{
	t_point		point;

	point.z = (z * mlx->map.amp);
	point.x = ((x - y) * mlx->img.zoom) + mlx->map.x;
	point.y = ((x + y) * (mlx->img.zoom / 2)) + mlx->map.y - point.z;
	point.red = 255;
	point.green = 255;
	point.blue = 255;
	return (point);
}

void		image_put_pixel(t_mlx *mlx, t_point point)
{
	if (point.x >= 0 && point.x < mlx->img.width && point.y >= 0 && point.y < mlx->img.height)
	{
		mlx->img.data[(mlx->img.sl * point.y) + (4 * point.x) + 2] = point.red;
		mlx->img.data[(mlx->img.sl * point.y) + (4 * point.x) + 1] = point.green;
		mlx->img.data[(mlx->img.sl * point.y) + (4 * point.x)] = point.blue;
	}
}
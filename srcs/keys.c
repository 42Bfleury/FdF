/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleury <bfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 06:38:51 by bfleury           #+#    #+#             */
/*   Updated: 2016/11/15 15:48:56 by bfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	move(t_mlx *mlx, int key)
{
	if (key == 123)
		mlx->map.x--;
	else if (key == 124)
		mlx->map.x++;
	else if (key == 125)
		mlx->map.y++;
	else if (key == 126)
		mlx->map.y--;
	draw_map(mlx);
}

static void	zoom(t_mlx *mlx, int key)
{
	if (key == 69 && mlx->img.zoom < FDF_ZOOM_MAX)
		mlx->img.zoom += 2;
	else if (key == 78 && mlx->img.zoom >= 2)
		mlx->img.zoom -= 2;
	if (mlx->img.zoom > 0 && mlx->img.zoom < FDF_ZOOM_MAX)
		draw_map(mlx);
}

static void	deep(t_mlx *mlx, int key)
{
	if (key == 12 && mlx->map.amp < FDF_AMP_MAX)
		mlx->map.amp++;
	else if (key == 0 && mlx->map.amp > -FDF_AMP_MAX)
		mlx->map.amp--;
	if (mlx->img.zoom > -FDF_AMP_MAX && mlx->img.zoom < FDF_AMP_MAX)
		draw_map(mlx);
}

static void	view(t_mlx *mlx, int key)
{
	if (key == 83)
		mlx->map.view = 1;
	else if (key == 84)
		mlx->map.view = 2;
	else if (key == 85)
		mlx->map.view = 3;
	draw_map(mlx);
}

int			key_hook(int key, t_mlx *mlx)
{
	if (123 <= key && key <= 126)
		move(mlx, key);
	else if (key == 69 || key == 78)
		zoom(mlx, key);
	else if (key == 12 || key == 0)
		deep(mlx, key);
	else if (83 <= key && key <= 85)
		view(mlx, key);
	else if (key == 32)
		reset(mlx);
	else if (key == 53)
		quit(mlx);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleury <bfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 06:38:51 by bfleury           #+#    #+#             */
/*   Updated: 2016/11/14 01:45:26 by bfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		move(t_mlx *mlx, int key)
{
	if (key == 65361)
		mlx->map.x --;
	else if (key == 65362)
		mlx->map.x ++;
	else if (key == 65363)
		mlx->map.y ++;
	else if (key == 65364)
		mlx->map.y --;
	draw_map(mlx);
}

void		zoom(t_mlx *mlx, int key)
{
	if (key == 65451 && mlx->img.zoom < FDF_ZOOM_MAX)
	{
		mlx->img.zoom ++;
		draw_map(mlx);
	}
	else if (key == 65453 && mlx->img.zoom)
	{
		mlx->img.zoom --;
		draw_map(mlx);
	}
}

void		deep(t_mlx *mlx, int key)
{
	if (key == 97 && mlx->map.amp < FDF_AMP_MAX)
	{
		mlx->map.amp++;
		draw_map(mlx);
	}
	else if (key == 113 && mlx->map.amp > -FDF_AMP_MAX)
	{
		mlx->map.amp--;
		draw_map(mlx);
	}
}

int		key_hook(int key, t_mlx *mlx)
{
	if (key == 65307)
		quit(mlx);
	else if (65361 <= key && key <= 65364)
		move(mlx, key);
	else if (key == 65451 || key == 65453)
		zoom(mlx, key);
	else if (key == 97 || key == 113)
		deep(mlx, key);
	else if (key == 32)
		reset(mlx);
	// printf("%i\n", key);
	return (0);
}



/*void		move(t_mlx *mlx, int key)
{
	if (key == 123)
		mlx->map.x -= (mlx->img.zoom / 2);
	else if (key == 124)
		mlx->map.x += (mlx->img.zoom / 2);
	else if (key == 125)
		mlx->map.y += (mlx->img.zoom / 2);
	else if (key == 126)
		mlx->map.y -= (mlx->img.zoom / 2);
}

void		zoom(t_mlx *mlx, int key)
{
	if (key == 69 && mlx->img.zoom < FDF_ZOOM_MAX)
		mlx->img.zoom += 2;
	else if (key == 78 && mlx->img.zoom > 2)
		mlx->img.zoom -= 2;
	draw_map(mlx);
}

void		deep(t_mlx *mlx, int key)
{
	if (key == 12 && mlx->map.amp < FDF_AMP_MAX)
		mlx->map.amp++;
	else if (key == 0 && mlx->map.amp > -FDF_AMP_MAX)
		mlx->map.amp--;
	draw_map(mlx);
}

int		key_hook(int key, t_mlx *mlx)
{
	if (key == 53)
		quit(mlx);
	else if (key >= 123 && key <= 126)
		move(mlx, key);
	else if (key == 69 || key == 78)
		zoom(mlx, key);
	else if (key == 12 || key == 0)
		deep(mlx, key);
	return (0);
}

int		loop_hook(t_mlx *mlx)
{
	draw_map(mlx);
	if(!mlx_put_image_to_window(mlx->ptr, mlx->win.ptr, mlx->img.ptr, mlx->img.x, mlx->img.y))
		die(mlx, "ERROR: Failed to load image in the window!");
	return (1);
}*/

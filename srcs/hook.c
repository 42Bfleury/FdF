/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleury <bfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 06:38:51 by bfleury           #+#    #+#             */
/*   Updated: 2016/11/10 00:11:16 by bfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	quit(t_mlx *mlx)
{
	mlx_destroy_image(mlx->ptr, mlx->img.ptr);
	mlx_destroy_window(mlx->ptr, mlx->win.ptr);
	mlx_init(mlx->ptr);
	clean(mlx);
	exit(0);
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
}
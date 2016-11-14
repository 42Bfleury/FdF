/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleury <bfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 06:41:06 by bfleury           #+#    #+#             */
/*   Updated: 2016/11/14 03:23:15 by bfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void		init_window(t_mlx *mlx, int width, int height, char *title)
{
	mlx->win.width = width;
	mlx->win.height = height;
	mlx->win.title = title;
	if (!(mlx->win.ptr = mlx_new_window(mlx->ptr, width, height, title)))
		die(NULL, "ERROR: Failed to create new window!");
}

static void		init_image(t_mlx *mlx)
{
	if (!(mlx->img.ptr = mlx_new_image(mlx->ptr, mlx->win.width, mlx->win.height)))
		die(NULL, "ERROR: Failed to create new image!");
	if (!(mlx->img.data = mlx_get_data_addr(mlx->img.ptr, &mlx->img.bpp, &mlx->img.sl, &mlx->img.e)))
		die(NULL, "ERROR: Failed to get the image data address!");
}

static void		init_map(t_mlx *mlx, char *file)
{
	mlx->map.file = file;
	mlx->map.height = get_nb_line(mlx);
	mlx->map.width = 0;
	mlx->map.tab = parse_map(mlx);
	mlx->map.view = 1;
	reset(mlx);
}

void			reset(t_mlx *mlx)
{
	mlx->img.zoom = FDF_ZOOM;
	mlx->map.x = (mlx->win.width - mlx->map.width) / 3;
	mlx->map.y = ((mlx->win.height - mlx->map.height) / 5);
	mlx->map.inclin = 1;
	mlx->map.amp = 1;
}

void			init(int width, int height, char *title, char *file)
{
	t_mlx		mlx;

	mlx.ptr = NULL;
	mlx.win.ptr = NULL;
	mlx.img.ptr = NULL;
	mlx.map.tab = NULL;
	if (!(mlx.ptr = mlx_init()))
		die(NULL, "ERROR: Failed to init MLX library!");
	init_window(&mlx, width, height, title);
	init_image(&mlx);
	init_map(&mlx, file);
	mlx_key_hook(mlx.win.ptr, key_hook, &mlx);
	// mlx_loop_hook(mlx.ptr, loop_hook, &mlx);
	draw_map(&mlx);
	if(!mlx_put_image_to_window(mlx.ptr, mlx.win.ptr, mlx.img.ptr, 0, 0))
		die(&mlx, "ERROR: Failed to load image in the window!");
	if (!mlx_loop(mlx.ptr))
		die(&mlx, "ERROR: Failed to init MLX loop!");
}
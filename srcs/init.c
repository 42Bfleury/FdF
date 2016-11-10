/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleury <bfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 06:41:06 by bfleury           #+#    #+#             */
/*   Updated: 2016/11/09 23:57:52 by bfleury          ###   ########.fr       */
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
	mlx->img.zoom = FDF_ZOOM;
	mlx->img.width = mlx->win.width;
	mlx->img.height = mlx->win.height;
	mlx->img.x = 0;
	mlx->img.y = 0;
	if (!(mlx->img.ptr = mlx_new_image(mlx->ptr, mlx->img.width, mlx->img.height)))
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
	mlx->map.x = mlx->win.width / 2;
	mlx->map.y = 0;
	mlx->map.amp = 1;
	// mlx->map.x = (mlx->img.width - mlx->map.width) / 2;
	// mlx->map.y = (mlx->img.height - mlx->map.height) / 2;
	draw_map(mlx);
}

void			init(int width, int height, char *title, char *file)
{
	t_mlx		mlx;

	if (!(mlx.ptr = mlx_init()))
		die(NULL, "ERROR: Failed to init MLX library!");
	init_window(&mlx, width, height, title);
	init_image(&mlx);
	init_map(&mlx, file);
	mlx_key_hook(mlx.win.ptr, key_hook, &mlx);
	mlx_loop_hook(mlx.ptr, loop_hook, &mlx);
	// if(!mlx_put_image_to_window(mlx.ptr, mlx.win.ptr, mlx.img.ptr, mlx.img.x, mlx.img.y))
		// die(&mlx, "ERROR: Failed to load image in the window!");
	if (!mlx_loop(mlx.ptr))
		die(&mlx, "ERROR: Failed to init MLX loop!");
}
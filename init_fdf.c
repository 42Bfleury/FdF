/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleury <bfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 06:41:06 by bfleury           #+#    #+#             */
/*   Updated: 2016/11/07 12:19:05 by bfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		display_image(t_mlx mlx)
{
	if (!(mlx.img.ptr = mlx_new_image(mlx.ptr, mlx.img.width, mlx.img.height)))
		exit(-1);
	if (!(mlx.img.data = mlx_get_data_addr(mlx.img.ptr, &mlx.img.bpp, &mlx.img.sl, &mlx.img.e)))
		exit(-1);
	image_put_pixel(300, 200, mlx);
	image_put_pixel(301, 201, mlx);
	image_put_pixel(302, 202, mlx);
	image_put_pixel(303, 203, mlx);
	image_put_pixel(304, 204, mlx);
	image_put_pixel(305, 205, mlx);
	image_put_pixel(306, 206, mlx);
	image_put_pixel(307, 207, mlx);
	image_put_pixel(308, 208, mlx);
	image_put_pixel(309, 209, mlx);
	mlx_put_image_to_window(mlx.ptr, mlx.win.ptr, mlx.img.ptr, mlx.img.x, mlx.img.y);
	mlx_destroy_image(mlx.ptr, mlx.img.ptr);
}

t_mlx		init_fdf(int width, int height, char *title, char *file)
{
	t_mlx	mlx;

	mlx.map.file = file;
	mlx.win.width = width;
	mlx.win.height = height;
	mlx.img.x = 0;
	mlx.img.y = 0;
	mlx.img.zoom = FDF_Z;
	mlx.img.width = width * mlx.img.zoom;
	mlx.img.height = height * mlx.img.zoom;
	init_map(mlx.map.file, &mlx);
	if (!(mlx.ptr = mlx_init()))
		exit(-1);
	if (!(mlx.win.ptr = mlx_new_window(mlx.ptr, width, height, title)))
		exit(-1);
	display_image(mlx);
	mlx_key_hook(mlx.win.ptr, key_hook, &mlx);
	if (!mlx_loop(mlx.ptr))
		exit(-1);
	return (mlx);
}
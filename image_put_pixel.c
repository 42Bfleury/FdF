/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_put_pixel.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleury <bfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 06:49:52 by bfleury           #+#    #+#             */
/*   Updated: 2016/11/07 09:14:01 by bfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void					image_put_pixel(int x, int y, t_mlx mlx)
{
	mlx.img.data[(mlx.img.sl * y) + (4 * x) + 2] = 0xFF;
	mlx.img.data[(mlx.img.sl * y) + (4 * x) + 1] = 0xFF;
	mlx.img.data[(mlx.img.sl * y) + (4 * x)] = 0xFF;
}
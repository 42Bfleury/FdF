/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleury <bfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 06:43:16 by bfleury           #+#    #+#             */
/*   Updated: 2016/11/10 00:06:39 by bfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		zoom(t_mlx *mlx, int key)
{
	if (key == 69 && mlx->img.zoom < FDF_ZOOM_MAX)
		mlx->img.zoom += 2;
	else if (key == 78 && mlx->img.zoom > 2)
		mlx->img.zoom -= 2;
}

void		deep(t_mlx *mlx, int key)
{
	if (key == 12 && mlx->map.amp < FDF_AMP_MAX)
		mlx->map.amp++;
	else if (key == 0 && mlx->map.amp > -FDF_AMP_MAX)
		mlx->map.amp--;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleury <bfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 08:12:56 by bfleury           #+#    #+#             */
/*   Updated: 2016/11/09 23:44:45 by bfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		move(t_mlx *mlx, int key)
{
	if (key == 123)
		mlx->map.x -= (mlx->img.zoom / 2);
	if (key == 124)
		mlx->map.x += (mlx->img.zoom / 2);
	if (key == 125)
		mlx->map.y += (mlx->img.zoom / 2);
	if (key == 126)
		mlx->map.y -= (mlx->img.zoom / 2);
}
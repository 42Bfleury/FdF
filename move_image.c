/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleury <bfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 08:12:56 by bfleury           #+#    #+#             */
/*   Updated: 2016/11/07 12:19:28 by bfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		move_image(int key, t_mlx mlx)
{
	if (key == 123)
		mlx.img.x--;
	if (key == 124)
		mlx.img.x++;
	if (key == 125)
		mlx.img.y++;
	if (key == 126)
		mlx.img.y--;
	display_image(mlx);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleury <bfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 08:12:56 by bfleury           #+#    #+#             */
/*   Updated: 2016/11/15 13:20:09 by bfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	clean(t_mlx *mlx)
{
	int		i;

	if (mlx->map.tab != NULL)
	{
		i = 0;
		while (i++ < mlx->map.height)
			if (mlx->map.tab[i - 1] != NULL)
				free(mlx->map.tab[i - 1]);
		if (mlx->map.tab != NULL)
			free(mlx->map.tab);
	}
	if (mlx->img.ptr != NULL)
		mlx_destroy_image(mlx->ptr, mlx->img.ptr);
	if (mlx->win.ptr != NULL)
		mlx_destroy_window(mlx->ptr, mlx->win.ptr);
	if (mlx->ptr != NULL)
		free(mlx->ptr);
}

void		quit(t_mlx *mlx)
{
	if (mlx != NULL)
		clean(mlx);
	exit(0);
}

void		die(t_mlx *mlx, char *msg)
{
	if (mlx == NULL)
		clean(mlx);
	ft_putendl(msg);
	exit(-1);
}

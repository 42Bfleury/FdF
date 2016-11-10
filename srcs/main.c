/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleury <bfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 03:24:27 by bfleury           #+#    #+#             */
/*   Updated: 2016/11/10 00:09:20 by bfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/fdf.h"

void		clean(t_mlx *mlx)
{
	int		i;

	if (mlx)
	{
		i = 0;
		while (i < mlx->map.height)
			free(mlx->map.tab[i++]);
		free(mlx->map.tab);
	}
}

void		die(t_mlx *mlx, char *str)
{
	clean(mlx);
	ft_putendl(str);
	exit(-1);
}

void		draw_map(t_mlx *mlx)
{
	int			x;
	int			y;

	y = 0;
	ft_bzero(mlx->img.data, (mlx->img.width * mlx->img.height * 4));
	while (y < mlx->map.height)
	{
		x = 1;
		while (x <= mlx->map.tab[y][0])
		{
			if(x < mlx->map.tab[y][0])
				trace_segment(mlx,
					create_point(mlx, x - 1, y, mlx->map.tab[y][x]),
					create_point(mlx, x, y, mlx->map.tab[y][x + 1]));
			if(y < mlx->map.height - 1)
				trace_segment(mlx,
					create_point(mlx, x - 1, y, mlx->map.tab[y][x]),
					create_point(mlx, x - 1, y + 1, mlx->map.tab[y + 1][x]));
			x++;
		}
		y++;
	}
}

int			main(int ac, char **av)
{
	if (ac == 2)
		init(FDF_W, FDF_H, FDF_T, av[1]);
	else
		die(NULL, "./FDF : Usage --> ./fdf <map.fdf>");
	return (0);
}
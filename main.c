/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleury <bfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 03:24:27 by bfleury           #+#    #+#             */
/*   Updated: 2016/11/07 08:37:32 by bfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fdf.h"

/*static t_point		create_point(int x, int y)
{
	t_point		point;

	point.x = x;
	point.y = y;
	return (point);
}

static void			test_carre(t_mlx mlx)
{
	t_point		a;
	t_point 	b;
	t_point 	c;
	t_point 	d;

	a = create_point(275, 175);
	b = create_point(324, 175);
	c = create_point(324, 224);
	d = create_point(275, 224);
	//a = create_point(0, 0);
	//b = create_point(10, 0);
	//c = create_point(10, 10);
	//d = create_point(0, 10);
	trace_segment(mlx, a, b, 0xFFFFFF);
	trace_segment(mlx, b, c, 0xFFFFFF);
	trace_segment(mlx, c, d, 0xFFFFFF);
	trace_segment(mlx, d, a, 0xFFFFFF);
	trace_segment(mlx, a, c, 0xFFFFFF);
	trace_segment(mlx, b, d, 0xFFFFFF);
}*/

int					main(void)
{
	t_mlx		mlx;

	mlx = init_fdf(FDF_W, FDF_H, FDF_T, "map/basic.fdf");
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 10:45:10 by bfleury           #+#    #+#             */
/*   Updated: 2016/11/03 13:16:48 by bfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		init_mlx(t_event *e)
{
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, e->width, e->height, "42");
	e->img.addr = mlx_new_image(e->mlx, e->width, e->height);
	e->img.width = e->width;
	e->img.data = mlx_get_data_addr(e->img.addr, &(e->img.bpp),
			&(e->img.width), &(e->img.endian));
	e->render = &parallel;
}

static void		load_palette(t_event *e, int ac, char **av)
{
	e->cwater = 0x007fff;
	e->cground = 0x1b4f08;
	e->crock = 0x582900;
	e->csnow = 0xffffff;
	if (ac > 2)
		e->cwater = ft_atoi_base(av[2], BASE_16);
	if (ac > 3)
		e->cground = ft_atoi_base(av[3], BASE_16);
	if (ac > 4)
		e->crock = ft_atoi_base(av[4], BASE_16);
	if (ac > 5)
		e->csnow = ft_atoi_base(av[5], BASE_16);
}

static void		usage(char *name)
{
	ft_putstr("Usage: ");
	ft_putstr(name);
	ft_putendl(" mapFile");
	ft_putstr("Or:");
	ft_putstr("\t[default] ");
	ft_putstr(name);
	ft_putendl(" mapFile 0x007fff 0x1b4f08 0x582900 0xffffff");
	ft_putstr("\t[name]   ");
	ft_putstr(name);
	ft_putendl(" mapFile   water   ground   rock   snow");
}

int				main(int ac, char **av)
{
	t_event		e;

	e.width = 1280;
	e.height = e.width * 9 / 16;
	e.offx = e.width / 3;
	e.offy = e.height / 4;
	e.zoom = 1;
	if (ac < 2 || ac > 6)
	{
		usage(av[0]);
		return (0);
	}
	load_map(&e, av[1]);
	load_palette(&e, ac, av);
	init_mlx(&e);
	mlx_do_key_autorepeaton(e.mlx);
	mlx_hook(e.win, 2, (1L << 0), &key_hook, &e);
	mlx_expose_hook(e.win, &expose_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 10:43:59 by bfleury           #+#    #+#             */
/*   Updated: 2016/11/03 12:49:00 by bfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				expose_hook(t_event *e)
{
	e->render(e);
	return (0);
}

static void		control(int keycode, t_event *e)
{
	if (keycode == 125)
		e->offy -= 4 * e->zoom;
	if (keycode == 126)
		e->offy += 4 * e->zoom;
	if (keycode == 123)
		e->offx += 4 * e->zoom;
	if (keycode == 124)
		e->offx -= 4 * e->zoom;
	if (keycode == 69 || keycode == 24)
		e->zoom++;
	if (keycode == 78 || keycode == 27)
		e->zoom--;
	if (e->zoom < 1)
		e->zoom = 1;
	if (keycode == 18 || keycode == 83)
		e->render = &parallel;
	if (keycode == 19 || keycode == 84)
		e->render = &iso;
	if (keycode == 20 || keycode == 85)
		e->render = &conical;
}

int				key_hook(int keycode, t_event *e)
{
	if (keycode == 53)
	{
		mlx_destroy_window(e->mlx, e->win);
		exit(0);
	}
	control(keycode, e);
	e->render(e);
	return (0);
}

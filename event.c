/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 10:43:59 by bfleury           #+#    #+#             */
/*   Updated: 2016/11/03 10:44:31 by bfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				expose_hook(t_event *ev)
{
	ev->render(ev);
	return (0);
}

static void		control(int keycode, t_event *ev)
{
	if (keycode == 125)
		ev->offy -= 4 * ev->zoom;
	if (keycode == 126)
		ev->offy += 4 * ev->zoom;
	if (keycode == 123)
		ev->offx += 4 * ev->zoom;
	if (keycode == 124)
		ev->offx -= 4 * ev->zoom;
	if (keycode == 69 || keycode == 24)
		ev->zoom++;
	if (keycode == 78 || keycode == 27)
		ev->zoom--;
	if (ev->zoom < 1)
		ev->zoom = 1;
	if (keycode == 18 || keycode == 83)
		ev->render = &parallel;
	if (keycode == 19 || keycode == 84)
		ev->render = &iso;
	if (keycode == 20 || keycode == 85)
		ev->render = &conical;
}

int				key_hook(int keycode, t_event *ev)
{
	if (keycode == 53)
	{
		mlx_destroy_window(ev->mlx, ev->win);
		exit(0);
	}
	control(keycode, ev);
	ev->render(ev);
	return (0);
}

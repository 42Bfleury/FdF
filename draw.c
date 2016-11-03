/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 10:41:18 by bfleury           #+#    #+#             */
/*   Updated: 2016/11/03 13:16:33 by bfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		draw_pixel(t_event *e, int x, int y, t_color *c)
{
	unsigned int	index;

	x = x + e->offx * e->zoom;
	y = y + e->offy * e->zoom;
	if (x < 0 || y < 0 || x >= e->width || y >= e->height)
		return ;
	index = (x * 4 + y * e->img.width);
	e->img.data[index] = c->b;
	e->img.data[index + 1] = c->g;
	e->img.data[index + 2] = c->r;
}

void		draw_point(t_event *e, t_point *p, t_color *c, int r)
{
	int		x;
	int		y;

	x = -1;
	while (++x <= r * 2)
	{
		y = -1;
		while (++y <= r * 2)
		{
			draw_pixel(e, p->x * e->zoom + x - r, p->y * e->zoom + y - r, c);
		}
	}
	free(p);
	free(c);
}

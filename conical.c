/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conical.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 10:40:33 by bfleury           #+#    #+#             */
/*   Updated: 2016/11/03 12:50:07 by bfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_color	*get_map_color(t_event *e, t_node *node)
{
	if (node->color >= 0)
		return (new_color(node->color));
	else if (node->height >= 10)
		return (inewcolor(e->crock, e->csnow, (node->height % 10) / 10.0));
	else if (node->height >= 0)
		return (inewcolor(e->cground, e->crock, node->height / 10.0));
	else
		return (new_color(e->cwater));
}

static void		free_conical_line(t_point *p1, t_point **p, t_color **c)
{
	free(p1);
	free(p[0]);
	free(p[1]);
	free(p[2]);
	free(c[0]);
	free(c[1]);
}

static void		conical_line(t_event *e, t_point *p0, t_point *p1, double angle)
{
	t_point		*p[3];
	t_color		*c[2];
	double		i;
	double		n;
	double		len;

	p[0] = get_con_point(p0->x, p0->y, e->map.data[p0->y][p0->x].height * 2,
		angle);
	p[1] = get_con_point(p1->x, p1->y, e->map.data[p1->y][p1->x].height * 2,
		angle);
	c[0] = get_map_color(e, e->map.data[p0->y] + p0->x);
	c[1] = get_map_color(e, e->map.data[p1->y] + p1->x);
	p[2] = get_point(p[0]->x + p[1]->x, p[0]->y + p[1]->y);
	len = p[2]->x * p[2]->x + p[2]->y * p[2]->y;
	i = 0;
	while (i * i <= len)
	{
		n = (i * i) / len;
		draw_point(e,
			get_point((int)(p[0]->x + (double)(p[1]->x - p[0]->x) * n),
				(int)(p[0]->y + (double)(p[1]->y - p[0]->y) * n)),
				icolor(c[0], c[1], n), e->zoom - 1);
		i += 1.0;
	}
	free_conical_line(p1, p, c);
}

void			conical(t_event *e)
{
	t_point		*p;
	double		angle;

	ft_bzero(e->img.data, e->width * e->height * 4);
	p = get_point(-1, -1);
	angle = 180.0 / (double)e->map.width;
	while (++(p->y) < e->map.height)
	{
		p->x = -1;
		while (++(p->x) < e->map.width)
		{
			if (p->x < e->map.width - 1)
				conical_line(e, p, get_point(p->x + 1, p->y), angle);
			if (p->y < e->map.height - 1)
				conical_line(e, p, get_point(p->x, p->y + 1), angle);
		}
	}
	free(p);
	mlx_put_image_to_window(e->mlx, e->win, e->img.addr, 0, 0);
	mlx_do_sync(e->mlx);
}

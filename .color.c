/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 10:39:43 by bfleury           #+#    #+#             */
/*   Updated: 2016/11/03 13:16:19 by bfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_color			*icolor(t_color *c0, t_color *c1, double t)
{
	t_color		*c;

	c = (t_color*)malloc(sizeof(t_color));
	if (c)
	{
		c->r = (unsigned char)(c0->r + (c1->r - c0->r) * t);
		c->g = (unsigned char)(c0->g + (c1->g - c0->g) * t);
		c->b = (unsigned char)(c0->b + (c1->b - c0->b) * t);
	}
	return (c);
}

t_color			*inewcolor(int ca, int cb, double t)
{
	t_color		*c;
	t_color		*c0;
	t_color		*c1;

	c0 = new_color(ca);
	c1 = new_color(cb);
	c = (t_color *)malloc(sizeof(t_color));
	if (c)
	{
		c->r = (unsigned char)(c0->r + (c1->r - c0->r) * t);
		c->g = (unsigned char)(c0->g + (c1->g - c0->g) * t);
		c->b = (unsigned char)(c0->b + (c1->b - c0->b) * t);
	}
	free(c0);
	free(c1);
	return (c);
}

t_color			*new_color(int color)
{
	t_color		*c;

	c = (t_color *)malloc(sizeof(t_color));
	if (c)
	{
		c->r = (color >> 16) & 0xff;
		c->g = (color >> 8) & 0xff;
		c->b = color & 0xff;
	}
	return (c);
}

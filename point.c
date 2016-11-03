/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 10:51:30 by bfleury           #+#    #+#             */
/*   Updated: 2016/11/03 10:51:41 by bfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point		*get_point(int x, int y)
{
	t_point *pt;

	pt = (t_point*)malloc(sizeof(t_point));
	pt->x = x;
	pt->y = y;
	return (pt);
}

t_point		*get_iso_point(int x, int y, int h)
{
	return (get_point((x - y) * 32, (x + y) * 16 - h));
}

t_point		*get_par_point(int x, int y, int h)
{
	return (get_point((x - y) * 40, y * 20 - h));
}

t_point		*get_con_point(int x, int y, int h, double angle)
{
	double r;
	double c;
	double s;

	r = M_PI * (-angle * x + 180.0 - angle / 2.0) / 180.0;
	c = cos(r);
	s = sin(r);
	return (get_point((int)(c * 32 * y), (int)(s * 32 * y) - h));
}

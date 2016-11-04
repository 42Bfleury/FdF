/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfleury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 00:29:38 by bfleury           #+#    #+#             */
/*   Updated: 2016/11/04 03:19:34 by bfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//		mlx_pixel_put(mlx, window, x1, y1, color);

void		mlx_trace_segment(void *mlx, void *window, int x1, int y1, int x2, int y2, int color)
{
	int		dx;
	int		dy;
	int		e;

	if (!(dx = x2 - x1))
	{
		if (dx > 0)
		{
			if (!(dy = y2 - y1))
			{
				if (dy > 0)
				{
					if (dx >= dy)
					{
						e = dx;
						dx *= 2;
						dy *= 2;
						while (1)
						{
							mlx_pixel_put(mlx, window, x1, y1, color);
							x1++;
							if (x1 == x2)
								break;
							if ((e -= dy) < 0)
							{
								y1++;
								e += dx;
							}
						}
					}
					else
					{
						e = dy;
						dx *= 2;
						dy *= 2;
						while (1)
						{
							mlx_pixel_put(mlx, window, x1, y1, color);
							y1++;
							if (y1 == y2)
								break;
							if ((e -= dx) < 0)
							{
								x1++;
								e += dy;
							}
						}
					}
				}
				else
				{
					if (dx >= -dy)
					{
						e = dx;
						dx *= 2;
						dy *= 2;
						while (1)
						{
							mlx_pixel_put(mlx, window, x1, y1, color);
							x1++;
							if (x1 == x2)
								break;
							if ((e += dy) < 0)
							{
								y1--;
								e += dx;
							}
						}
					}
					else
					{
						e = dy;
						dx *= 2;
						dy *= 2;
						while (1)
						{
							mlx_pixel_put(mlx, window, x1, y1, color);
							y1--;
							if (y1 == y2)
								break;
							if ((e += dx) > 0)
							{
								x1++;
								e += dy;
							}
						}
					}
				}
			}
			else
			{
				while (x1 <= x2)
				{
					mlx_pixel_put(mlx, window, x1, y1, color);
					x1++;
				}
			}
		}
		else if (dx < 0)
		{
			if (!(dy = y2 - y1))
			{
				if (dy > 0)
				{
					if (-dx >= dy)
					{
						e = dx;
						dx *= 2;
						dy *= 2;
						while (1)
						{
							mlx_pixel_put(mlx, window, x1, y1, color);
							x1--;
							if (x1 == x2)
								break;
							if ((e += dy) >= 0)
							{
								y1++;
								e += dx;
							}
						}
					}
					else
					{
						e = dy;
						dx *= 2;
						dy *= 2;
						while (1)
						{
							mlx_pixel_put(mlx, window, x1, y1, color);
							y1++;
							if (y1 == y2)
								break;
							if ((e += dx) <= 0)
							{
								x1--;
								e += dy;
							}
						}
					}
				}
				else if (dy < 0)
				{
					if (dx <= dy)
					{
						e = dx;
						dx *= 2;
						dy *= 2;
						while (1)
						{
							mlx_pixel_put(mlx, window, x1, y1, color);
							x1++;
							if (x1 == x2)
								break;
							if ((e -= dy) >= 0)
							{
								y1--;
								e += dx;
							}
						}
					}
					else
					{
						e = dy;
						dx *= 2;
						dy *= 2;
						while (1)
						{
							mlx_pixel_put(mlx, window, x1, y1, color);
							y1--;
							if (y1 == y2)
								break;
							if ((e -= dx) >= 0)
							{
								x1--;
								e += dy;
							}
						}
					}
				}
				else
				{
					while (x1 >= x2)
					{
						mlx_pixel_put(mlx, window, x1, y1, color);
						x1--;
					}
				}
			}
		}
		else
		{
			if (!(dy = y2 - y1))
			{
				if (dy > 0)
				{
					while (y1 <= y2)
					{
						mlx_pixel_put(mlx, window, x1, y1, color);
						y1++;
					}

				}
				else if (dy < 0)
				{
					while (y1 >= y2)
					{
						mlx_pixel_put(mlx, window, x1, y1, color);
						y1--;
					}
				}
			}
		}
	}
	//mlx_pixel_put(mlx, window, x2, y2, color);
}

int			main(void)
{
	void	*mlx;
	void	*window;

	if (!(mlx = mlx_init()))
		return (-1);
	if (!(window = mlx_new_window(mlx, 600, 400, "42 - FdF")))
		return (-1);
	/*mlx_trace_segment(mlx, window, 275, 175, 324, 175, 0xFFFFFF);
	mlx_trace_segment(mlx, window, 275, 175, 275, 224, 0xFFFFFF);
	mlx_trace_segment(mlx, window, 275, 224, 324, 224, 0xFFFFFF);
	mlx_trace_segment(mlx, window, 324, 175, 324, 224, 0xFFFFFF);*/
	mlx_trace_segment(mlx, window, 0, 0, 600, 400, 0xFFFFFF);
	mlx_string_put(mlx, window, 10, 10, 0xFFFFFF, "Test");
	if (!mlx_loop(mlx))
		return (-1);
	return (0);
}
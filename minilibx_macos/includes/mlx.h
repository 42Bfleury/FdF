/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ben <ben@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 23:08:38 by ben               #+#    #+#             */
/*   Updated: 2016/11/11 01:55:39 by ben              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_H
# define MLX_H

void			*mlx_init();

void			*mlx_new_window(void *m, int w, int h, char *t);
int				mlx_pixel_put(void *m, void *w, int x, int y, int c);
int				mlx_put_string(void *m, void *w, int x, int y, int c, char *s);
int				mlx_clear_window(void *m, void *w);
int				mlx_destroy_window(void *m, void *w);

void			*mlx_new_image(void *m, int w, int h);
char			*mlx_get_data_addr(void *i, int *bpp, int *sl, int *e);
void			*mlx_xpm_to_image(void *m, char **xpm, int *w, int *h);
void			*mlx_xpm_file_to_image(void *m, char *file, int *w, int *h);
unsigned int	mlx_get_color_value(void *m, int c);
int				mlx_put_image_to_window(void*m, void*w, void*i, int x, int y);
int				mlx_destroy_image(void *m, void *i);

int				mlx_mouse_hook (void *w, int (*f)(), void *p);
int				mlx_key_hook (void *w, int (*f)(), void *p);
int				mlx_expose_hook (void *w, int (*f)(), void *p);
int				mlx_loop_hook (void *m, int (*f)(), void *p);
int				mlx_loop (void *m);
int				mlx_hook(void *w, int x_event, int x_mask, int (*f)(), void *p);
int				mlx_do_key_autorepeatoff(void *m);
int				mlx_do_key_autorepeaton(void *m);
int				mlx_do_sync(void *m);

#endif

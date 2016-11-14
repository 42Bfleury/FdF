/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ben <ben@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 23:24:37 by ben               #+#    #+#             */
/*   Updated: 2016/11/11 01:16:47 by ben              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define	MAX_EVENT		32
#define	MAX_PIXEL_NB	200000
#define UNIQ_BPP		4
#define FONT_WIDTH		10
#define	FONT_HEIGHT		20

typedef int				(*func_t)();

typedef struct			glsl_info_s
{
	GLuint				pixel_vshader;
	GLuint				pixel_fshader;
	GLuint				pixel_program;
	GLint				loc_pixel_position;
	GLint				loc_pixel_texture;
	GLint				loc_pixel_winhalfsize;
	GLuint				image_vshader;
	GLuint				image_fshader;
	GLuint				image_program;
	GLint				loc_image_position;
	GLint				loc_image_winhalfsize;
	GLint				loc_image_texture;
	GLint				loc_image_pos;
	GLint				loc_image_size;
	GLuint				font_vshader;
	GLuint				font_fshader;
	GLuint				font_program;
	GLint				loc_font_position;
	GLint				loc_font_winhalfsize;
	GLint				loc_font_texture;
	GLint				loc_font_color;
	GLint				loc_font_posinwin;
	GLint				loc_font_posinatlas;
	GLint				loc_font_atlassize;
}						glsl_info_t;

typedef struct			mlx_img_list_s
{
	int					width;
	int					height;
	char				*buffer;
	GLfloat				vertexes[8];
	mlx_img_list_t		*next;
}						mlx_img_list_t;

typedef struct			mlx_img_ctx_s
{
	GLuint				texture;
	GLuint				vbuffer;
	mlx_img_list_t		*img;
	mlx_img_ctx_t		*next;
}						mlx_img_ctx_t;

typedef struct			mlx_win_list_s
{
  void					*winid;
  mlx_img_ctx_t			*img_list;
  int					nb_flush;
  int					pixmgt;
  mlx_win_list_t		*next;
}						mlx_win_list_t;

typedef struct			mlx_s
{
  void					*appid;
  mlx_win_list_t		*win_list;
  mlx_img_list_t		*img_list;
  void					(*loop_hook)(void *);
  void					*loop_hook_data;
  void					*loop_timer;
  mlx_img_list_t		*font;
  int					main_loop_active;
}						mlx_t;

int						mlx_do_sync(mlx_t *mlx);
int						mlx_shaders(glsl_info_t *glsl);
int						mlx_int_str_str(char *s, char *find, int len);
int						mlx_destroy_image(mlx_t *mlx, mlx_img_list_t *i);
int						mlx_int_str_str_cote(char *s, char *find, int len);

void					*mlx_new_image();
void					*mlx_xpm_to_image(mlx_t *mlx, char **x, int *w, int *h);

char					**mlx_int_str_to_wordtab(char *s);

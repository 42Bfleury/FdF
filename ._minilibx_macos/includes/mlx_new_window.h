/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_new_window.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ben <ben@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 00:05:05 by ben               #+#    #+#             */
/*   Updated: 2016/11/11 02:08:07 by ben              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#import <Cocoa/Cocoa.h>

#include "mlx_init.h"

@interface NSWindowEvent : NSWindow
{
	func_t	event_funct[MAX_EVENT];
	void	*(event_param[MAX_EVENT]);
	int		keyrepeat;
	int		keyflag;
	int		size_x;
	int		size_y;
}

- (NSWindowEvent *) initWithContentRect:(NSRect)rect styleMask:(NSUInteger)winstyle backing:(NSBackingStoreType)bck defer:(BOOL) dfr;
- (void) setEvent:(int)event andFunc:(func_t)func andParam:(void *)param;
- (void) setKeyRepeat:(int)mode;
- (void) exposeNotification:(NSNotification *)note;
- (void) closeNotification:(NSNotification *)note;
@end

@interface MlxWin : NSOpenGLView
{
	NSWindowEvent		*win;
	NSOpenGLContext		*ctx;
	glsl_info_t			glsl;
	int					openglwin;
	int					size_x;
	int					size_y;
	int					pixel_nb;
	GLuint				pixel_vbuffer;
	GLuint				pixel_texture;
	unsigned int		*pixtexbuff;
}

- (id) initWithRect: (NSRect)rect andTitle: (NSString *)title pfaAttrs: (NSOpenGLPixelFormatAttribute *)attrs;
- (void) selectGLContext;
- (void) flushGLContext;
- (void) pixelPutColor: (int)color X:(int)x Y:(int)y;
- (void) mlx_gl_draw;
- (void) mlx_gl_draw_img:(mlx_img_list_t *)img andCtx:(mlx_img_ctx_t *)imgctx andX:(int)x andY:(int)y;
- (void) mlx_gl_draw_font:(mlx_img_list_t *)img andCtx:(mlx_img_ctx_t *)imgctx andX:(int)x andY:(int)y andColor:(int)color glyphX:(int)gx glyphY:(int)gy;
- (NSOpenGLContext *) ctx;
- (void) setEvent:(int)event andFunc:(func_t)func andParam:(void *)param;
- (void) setKeyRepeat:(int)mode;
- (void) ctxNeedsUpdate;
@end

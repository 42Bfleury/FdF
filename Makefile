# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bfleury <bfleury@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/03 01:07:07 by bfleury           #+#    #+#              #
#    Updated: 2016/11/07 09:14:10 by bfleury          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= fdf
TYPEFILE	= executable

RED			= \033[31m
YELLOW		= \033[33m
GREEN		= \033[32m
ENDCOLOR	= \033[0m

CC			= clang
CFLAGS		+= -Wall -Wextra -Werror
LIBDIR		= ../Libft
MLXDIR		= minilibx
LIB			= -I$(LIBDIR)/includes -L$(LIBDIR) -lft \
			  -I$(MLXDIR) -L$(MLXDIR) -lmlx
FW			= -framework OpenGL -framework Appkit
RM			= rm -rf

#SRC 	= color.c \
		  conical.c \
		  draw.c \
		  event.c \
		  fdf.c \
		  iso.c \
		  map.c \
		  parallel.c \
		  point.c

SRC		= main.c \
		  init_fdf.c \
		  init_map.c \
		  key_hook.c \
		  image_put_pixel.c \
		  move_image.c

OBJ		= $(SRC:.c=.o)


all: $(NAME)

$(NAME):
		@make libftgnl -C $(LIBDIR)
		@echo "$(YELLOW)Generating $(NAME) objects...$(ENDCOLOR)"
		@$(CC) $(CFLAGS) -c $(SRC)
		@echo "$(GREEN)$(NAME) objects generated with success!$(ENDCOLOR)"
		@echo "$(YELLOW)Generating $(NAME) $(TYPEFILE)...$(ENDCOLOR)"
		@$(CC) $(CFLAGS) $(LIB) $(FW) $(OBJ) -o $(NAME)
		@echo "$(GREEN)$(NAME) $(TYPEFILE) generated with success!$(ENDCOLOR)"

objects:
		@echo "$(YELLOW)Generating $(NAME) objects...$(ENDCOLOR)"
		@$(CC) $(CFLAGS) -c $(SRC)
		@echo "$(GREEN)$(NAME) objects generated with success!$(ENDCOLOR)"

mlx:
		@make -C $(MLXDIR)

libft:
		@make libftgnl -C $(LIBDIR)

clean: cleanlibft cleanmlx cleanfdf

cleanfdf:
		@echo "$(RED)Removing $(NAME) objects...$(ENDCOLOR)"
		@$(RM) $(OBJ)
		@echo "$(GREEN)$(NAME) objects removed with success!$(ENDCOLOR)"

cleanmlx:
		@make clean -C $(MLXDIR)

cleanlibft:
		@make clean -C $(LIBDIR)

xclean: xcleanlibft xcleanmlx xcleanfdf

xcleanfdf:
		@echo "$(RED)Removing $(NAME) $(TYPEFILE)...$(ENDCOLOR)"
		@$(RM) $(NAME)
		@echo "$(GREEN)$(NAME) executable removed with success!$(ENDCOLOR)"

xcleanmlx:
		@make xclean -C $(MLXDIR)

xcleanlibft:
		@make xclean -C $(LIBDIR)

fclean: clean xclean

fcleanfdf: cleanfdf xcleanfdf

fcleanmlx:
		@make fclean -C $(MLXDIR)

fcleanlibft:
		@make fclean -C $(LIBDIR)

re: fclean all

refdf: fcleanfdf all

remlx: fcleanmlx mlx

relibft: fcleanlibft lib

.PHONY : all objects mlx libft \
		clean cleanfdf cleanmlx cleanlibft \
		xclean xcleanfdf xcleanmlx xcleanlibft \
		fclean fcleanfdf fcleanmlx fcleanlibft \
		re refdf remlx relibft

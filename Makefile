# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bfleury <bfleury@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/03 01:07:07 by bfleury           #+#    #+#              #
#    Updated: 2016/11/11 03:46:49 by bfleury          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= fdf
TYPEFILE	= executable

RED			= \033[31m
YELLOW		= \033[33m
GREEN		= \033[32m
ENDCOLOR	= \033[0m

SUCCESS		= "           $(GREEN)[SUCCESS!]$(ENDCOLOR)"
OBJECTS		= "$(YELLOW)Generating $(NAME) objects... $(ENDCOLOR)\c"
PROJECT		= "$(YELLOW)Generating $(NAME) $(TYPEFILE)...$(ENDCOLOR)\c"
RMOBJECTS	= "$(RED)Removing $(NAME) objects...  $(ENDCOLOR)\c"
RMPROJECT	= "$(RED)Removing $(NAME) $(TYPEFILE)...  $(ENDCOLOR)\c"

SRC_DIR		= srcs
OBJ_DIR		= obj
SRC			= $(shell find $(SRC_DIR) -name '*.c' -type f)
OBJ			= $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

CC			= clang
CFLAGS		+= -Wall -Wextra -Werror
LIBDIR		= ../Libft
MLX_DIR		= minilibx_macos
LIB			= -I $(LIBDIR)/includes -L $(LIBDIR) -lft \
			  -I includes
MLX			= -I $(MLX_DIR) -L $(MLX_DIR) -lmlx
FW			= -framework OpenGL -framework Appkit
RM			= rm -rf

all:		build $(NAME)

linux:		changevar all

build :
			@mkdir -p $(OBJ_DIR)

changevar:
			$(eval MLX_DIR:= minilibx)
			$(eval FW:= -L /usr/include -lXext -lX11)

$(NAME):	$(OBJ)
			@make libftgnl -C $(LIBDIR)
			@make -C $(MLX_DIR)
			@echo $(PROJECT)
			@$(CC) $(CFLAGS) $(LIB) $(FW) $(OBJ) -o $(NAME)
			@echo $(SUCCESS)

$(OBJ):		#$(SRC)/%.c
			@echo $(OBJECTS)
			@$(CC) $(CFLAGS) -c $(SRC)
			@echo $(SUCCESS)
			#@$(CC) -MMD $(IFLAGS) -o $@ -c $<

mlx:
			@make -C $(MLX_DIR)

libft:
			@make libftgnl -C $(LIBDIR)

clean:		cleanlibft cleanmlx cleanfdf

cleanfdf:
			@echo $(RMOBJECTS)
			@$(RM) $(OBJ) $(OBJ_DIR)
			@echo $(SUCCESS)

cleanmlx:
			@make clean -C $(MLX_DIR)

cleanlibft:
			@make clean -C $(LIBDIR)

xclean:		xcleanlibft xcleanmlx xcleanfdf

xcleanfdf:
			@echo $(RMPROJECT)
			@$(RM) $(NAME)
			@echo $(SUCCESS)

xcleanmlx:
			@make xclean -C $(MLX_DIR)

xcleanlibft:
			@make xclean -C $(LIBDIR)

fclean:		clean xclean

fcleanfdf:	cleanfdf xcleanfdf

fcleanmlx:
			@make fclean -C $(MLX_DIR)

fcleanlibft:
			@make fclean -C $(LIBDIR)

re:			fclean all

refdf:		fcleanfdf all

remlx:		fcleanmlx mlx

relibft:	fcleanlibft lib

.PHONY:		all objects mlx libft \
			clean cleanfdf cleanmlx cleanlibft \
			xclean xcleanfdf xcleanmlx xcleanlibft \
			fclean fcleanfdf fcleanmlx fcleanlibft \
			re refdf remlx relibft
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bfleury <bfleury@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/03 01:07:07 by bfleury           #+#    #+#              #
#    Updated: 2016/11/16 12:10:00 by bfleury          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= fdf
TYPEFILE		= executable
DEBUG			= FALSE

RED				= \033[31m
YELLOW			= \033[33m
GREEN			= \033[1;32m
END				= \033[0m

SUCCESS			= "$(GREEN)[SUCCESS!]$(END)"
PROJECT			= "$(YELLOW)Generating $(NAME) $(TYPEFILE)...         $(END)\c"
OBJ_MSG			= "$(YELLOW)Generating $(NAME) object...             $(END)\c"
OBJ_CLN			= "$(RED)Removing $(NAME) objects...              $(END)\c"
EXE_CLN			= "$(RED)Removing $(NAME) $(TYPEFILE)...           $(END)\c"

LIB_DIR			= libft
LIB				= -L $(LIB_DIR) -lftgnl

MLX_DIR			= minilibx
MLX				= -L $(MLX_DIR) -lmlx

SRC_DIR			= srcs
OBJ_DIR			= objs
SRC				= $(shell find $(SRC_DIR) -name '*.c' -type f)
OBJ				= $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

CC				= clang
RM				= rm -rf

CFLAGS			+= -Wall -Wextra -Werror
FW				= -framework OpenGL -framework Appkit

ifeq ($(DEBUG),TRUE)
	CFLAGS		+= -g -O0
endif

#################################### FDF #######################################



all:			build libft mlx $(NAME)

build :
				@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c
				@echo $(OBJ_MSG)
				@$(CC) $(CFLAGS) -o $@ -c $<
				@echo $(SUCCESS)

$(NAME):		$(OBJ)
				@echo $(PROJECT)
				@$(CC) $(CFLAGS) $(FW) $(LIB) $(MLX) $(OBJ) -o $(NAME)
				@echo $(SUCCESS)

clean:			cleanlibft cleanmlx
				@echo $(OBJ_CLN)
				@$(RM) $(OBJ)
				@echo $(SUCCESS)

xclean:			xcleanlibft xcleanmlx
				@echo $(EXE_CLN)
				@$(RM) $(NAME) $(OBJ_DIR)
				@echo $(SUCCESS)

fclean:			clean xclean

re:				fclean all




################################### LIBFT ######################################



libft:
				@make -C $(LIB_DIR)

cleanlibft:
				@make clean -C $(LIB_DIR)

xcleanlibft:
				@make xclean -C $(LIB_DIR)



#################################### MLX #######################################



mlx:
				@make -C $(MLX_DIR)

cleanmlx:
				@make clean -C $(MLX_DIR)

xcleanmlx:
				@make xclean -C $(MLX_DIR)



################################### PHONY ######################################



.PHONY:			all build clean xclean fclean re \
				libft cleanlibft xcleanlibft fcleanlibft relibft \
				mlx cleanmlx xcleanmlx fcleanmlx remlx \

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bfleury <bfleury@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/03 01:07:07 by bfleury           #+#    #+#              #
#    Updated: 2016/11/22 18:02:22 by bfleury          ###   ########.fr        #
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
LIB_MSG			= "$(YELLOW)Generating $(LIB) library...          $(END)\c"
MLX_MSG			= "$(YELLOW)Generating $(MLX) library...            $(END)\c"
OBJ_MSG			= "$(YELLOW)Generating $(NAME) object...             $(END)\c"
LIB_CLN			= "$(RED)Removing $(LIB) objects...            $(END)\c"
MLX_CLN			= "$(RED)Removing $(MLX) objects...              $(END)\c"
OBJ_CLN			= "$(RED)Removing $(NAME) objects...              $(END)\c"
LIB_RMV			= "$(RED)Removing $(LIB) library...            $(END)\c"
MLX_RMV			= "$(RED)Removing $(MLX) library...              $(END)\c"
EXE_RMV			= "$(RED)Removing $(NAME) $(TYPEFILE)...           $(END)\c"

LIB				= libft
LIB_DIR			= libft
LIB_FLG			= -L $(LIB_DIR) -lft

MLX				= mlx
MLX_DIR			= minilibx
MLX_FLG			= -L $(MLX_DIR) -lmlx

SRC_DIR			= srcs
OBJ_DIR			= objs
SRC				= main.c \
				init.c \
				parsing.c \
				draw.c \
				hooks.c \
				exit.c

OBJS			= $(SRC:%.c=$(OBJ_DIR)/%.o)

CC				= clang
RM				= rm -rf

CFLAGS			+= -Wall -Wextra -Werror
FW				= -framework OpenGL -framework Appkit

ifeq ($(DEBUG),TRUE)
	CFLAGS		+= -g -O0 -fsanitize=address
endif

#################################### FDF #######################################



all:			libft mlx build $(NAME)

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c
				@echo $(OBJ_MSG)
				@$(CC) $(CFLAGS) -o $@ -c $<
				@echo $(SUCCESS)

$(NAME):		$(OBJS)
				@echo $(PROJECT)
				@$(CC) $(CFLAGS) $(FW) $(LIB_FLG) $(MLX_FLG) $(OBJS) -o $(NAME)
				@echo $(SUCCESS)

build :
				@mkdir -p $(OBJ_DIR)

clean:			cleanlibft cleanmlx
				@echo $(OBJ_CLN)
				@$(RM) $(OBJS)
				@echo $(SUCCESS)

xclean:			xcleanlibft xcleanmlx
				@echo $(EXE_RMV)
				@$(RM) $(NAME) $(OBJ_DIR)
				@echo $(SUCCESS)

fclean:			clean xclean

re:				fclean all



################################### LIBFT ######################################



libft:
				@echo $(LIB_MSG)
				@make -C $(LIB_DIR)
				@echo $(SUCCESS)

cleanlibft:
				@echo $(LIB_CLN)
				@make clean -C $(LIB_DIR)
				@echo $(SUCCESS)

xcleanlibft:
				@echo $(LIB_RMV)
				@make xclean -C $(LIB_DIR)
				@echo $(SUCCESS)



#################################### MLX #######################################



mlx:
				@echo $(MLX_MSG)
				@make -C $(MLX_DIR)
				@echo $(SUCCESS)

cleanmlx:
				@echo $(MLX_CLN)
				@make clean -C $(MLX_DIR)
				@echo $(SUCCESS)

xcleanmlx:
				@echo $(MLX_RMV)
				@make xclean -C $(MLX_DIR)
				@echo $(SUCCESS)



################################### PHONY ######################################



.PHONY:			all build clean xclean fclean re \
				libft cleanlibft xcleanlibft fcleanlibft relibft \
				mlx cleanmlx xcleanmlx fcleanmlx remlx \

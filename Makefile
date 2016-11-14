# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bfleury <bfleury@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/03 01:07:07 by bfleury           #+#    #+#              #
#    Updated: 2016/11/14 02:04:31 by bfleury          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= fdf
TYPEFILE		= executable
DEBUG			= TRUE

RED				= \033[31m
YELLOW			= \033[33m
GREEN			= \033[1;32m
END				= \033[0m

SUCCESS			= "$(GREEN)[SUCCESS!]$(END)"
PROJECT			= "$(YELLOW)Generating $(NAME)   $(TYPEFILE)...       $(END)\c"
OBJ_MSG			= "$(YELLOW)Generating $(NAME)   object...           $(END)\c"
MLX_MSG			= "$(YELLOW)Generating $(MLX)   object...           $(END)\c"
LIB_MSG			= "$(YELLOW)Generating $(LIB) object...           $(END)\c"
LIB_CLN			= "$(RED)Removing   $(LIB) objects...          $(END)\c"
MLX_CLN			= "$(RED)Removing   $(MLX)   objects...          $(END)\c"
OBJ_CLN			= "$(RED)Removing   $(NAME)   objects...          $(END)\c"
EXE_CLN			= "$(RED)Removing   $(NAME)   $(TYPEFILE)...       $(END)\c"

LIB				= libft
LIB_DIR			= ../GNL/srcs
LIB_SRC			= $(shell find $(LIB_DIR) -name '*.c' -type f)
LIB_OBJ			= $(LIB_SRC:$(LIB_DIR)/%.c=$(OBJ_DIR)/%.o)

MLX				= MLX
MLX_DIR			= minilibx/srcs
MLX_SRC			= $(shell find $(MLX_DIR) -name '*.c' -type f)
MLX_OBJ			= $(MLX_SRC:$(MLX_DIR)/%.c=$(OBJ_DIR)/%.o)

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



all:			build $(NAME)

build :
				@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c
				@echo $(OBJ_MSG)
				@$(CC) $(CFLAGS) -o $@ -c $<
				@echo $(SUCCESS)

$(NAME):		$(LIB_OBJ) $(MLX_OBJ) $(OBJ)
				@echo $(PROJECT)
				@$(CC) $(CFLAGS) $(FW) $(LIB_OBJ) $(MLX_OBJ) $(OBJ) -o $(NAME)
				@echo $(SUCCESS)

clean:			cleanlibft cleanmlx
				@echo $(OBJ_CLN)
				@$(RM) $(OBJ)
				@echo $(SUCCESS)

xclean:
				@echo $(EXE_CLN)
				@$(RM) $(NAME) $(OBJ_DIR)
				@echo $(SUCCESS)

fclean:			clean xclean

re:				fclean all



################################### LINUX ######################################



linux:			changevar all

changevar:
				$(eval FW:= -L/usr/include -lXext -lX11 -lm -lbsd)

relinux:		fclean linux



################################### LIBFT ######################################



$(OBJ_DIR)/%.o:	$(LIB_DIR)/%.c
				@echo $(LIB_MSG)
				@$(CC) -o $@ -c $<
				@echo $(SUCCESS)

cleanlibft:
				@echo $(LIB_CLN)
				@$(RM) $(LIB_OBJ)
				@echo $(SUCCESS)



#################################### MLX #######################################



$(OBJ_DIR)/%.o:	$(MLX_DIR)/%.c
				@echo $(MLX_MSG)
				@gcc -o $@ -c $<
				@echo $(SUCCESS)

cleanmlx:
				@echo $(MLX_CLN)
				@$(RM) $(MLX_OBJ)
				@echo $(SUCCESS)



################################### PHONY ######################################



.PHONY:			all clean xclean fclean re \
				build cleanlibft cleanmlx linux changevar

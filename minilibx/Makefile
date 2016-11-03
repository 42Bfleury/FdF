# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bfleury <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/03 04:46:11 by bfleury           #+#    #+#              #
#    Updated: 2016/11/03 06:05:42 by bfleury          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libmlx.a
FILETYPE= library

RED		= \033[31m
YELLOW	= \033[33m
GREEN	= \033[32m
ENDCOLOR= \033[0m

$(CC)	= gcc
CFLAGS	+= -O2
RM		= rm -rf

SRC		= mlx_shaders.c \
		  mlx_new_window.m \
		  mlx_init_loop.m \
		  mlx_new_image.m \
		  mlx_xpm.c \
		  mlx_int_str_to_wordtab.c

OBJ1	= $(SRC:.c=.o)
OBJ		= $(OBJ1:.m=.o)

all: $(NAME)

$(NAME): objects
	@echo "$(YELLOW)Generating $(NAME) $(FILETYPE)...$(ENDCOLOR)"
	@ar -r $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "$(GREEN)$(NAME) $(FILETYPE) generated with success!$(ENDCOLOR)"

objects:
	@echo "$(YELLOW)Generating $(NAME) objects...$(ENDCOLOR)"
	@$(CC) -c $(SRC)
	@echo "$(GREEN)$(NAME) objects generated with success!$(ENDCOLOR)"

clean:
	@echo "$(RED)Removing $(NAME) objects...$(ENDCOLOR)"
	@rm -f $(OBJ) *~
	@rm -f mlx_app
	@echo "$(GREEN)$(NAME) objects removed with success!$(ENDCOLOR)"

xclean:
	@echo "$(RED)Removing $(NAME) $(FILETYPE)...$(ENDCOLOR)"
	@rm -f $(NAME)
	@echo "$(GREEN)$(NAME) $(FILETYPE) removed with success!$(ENDCOLOR)"

fclean: clean xclean

re: fclean all

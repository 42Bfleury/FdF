# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bfleury <bfleury@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/11 03:44:46 by bfleury           #+#    #+#              #
#    Updated: 2016/11/11 04:10:03 by bfleury          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libmlx.a
TYPEFILE	= library

RED			= \033[31m
YELLOW		= \033[33m
GREEN		= \033[1;32m
ENDCOLOR	= \033[0m

SUCCESS		= "           $(GREEN)[SUCCESS!]$(ENDCOLOR)"
OBJECTS		= "$(YELLOW)Generating $(NAME) objects... $(ENDCOLOR)\c"
PROJECT		= "$(YELLOW)Generating $(NAME) $(TYPEFILE)...$(ENDCOLOR)\c"
RMOBJECTS	= "$(RED)Removing $(NAME) objects...  $(ENDCOLOR)\c"
RMPROJECT	= "$(RED)Removing $(NAME) $(TYPEFILE)...  $(ENDCOLOR)\c"

SRC_DIR		= srcs
OBJ_DIR		= objs
SRC			= $(shell find $(SRC_DIR) -name '*.m' -type f)
OBJ			= $(SRC:$(SRC_DIR)/%.m=$(OBJ_DIR)/%.o)
CC			= clang
CFLAGS		+= -Wall -Wextra -Werror -O2
RM			= rm -rf

all:		build $(NAME)

build :
			@mkdir -p $(OBJ_DIR)

$(NAME):	$(OBJ)
			@ar -r $(NAME) $(OBJ)
			@ranlib $(NAME)

$(OBJ):
			@echo $(OBJECTS)
			@$(CC) $(CFLAGS) -c $@
			@echo $(SUCCESS)

clean:
			@echo $(RMOBJECTS)
			@$(RM) $(OBJ) $(OBJ_DIR)
			@echo $(SUCCESS)

xclean:
			@echo $(RMPROJECT)
			@$(RM) $(NAME)
			@echo $(SUCCESS)

fclean:		clean xclean

re:			fclean all

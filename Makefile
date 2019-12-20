# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hezzahir <hamza.ezzahiry@gmail.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/19 18:32:21 by hezzahir          #+#    #+#              #
#    Updated: 2019/10/21 11:02:51 by hezzahir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = wolf3d

SRC_PATH = srcs
SRC_NAME = main.c parsing.c

OBJ_PATH = objs
OBJ_NAME = $(SRC_NAME:.c=.o)

CC = clang
CFLAGS = -Wall -Werror -Wextra

CPPFLAGS = -I includes -I libft/includes

HEADER = includes/wolf3d.h

LDFLAGS = -L libft
LDLIBS = -O2 -lft -lm -lmlx -framework OpenGL -framework AppKit

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

all: $(NAME)

$(NAME): $(OBJ)
		@echo "																";
		@echo "																";
		@echo " ██╗    ██╗ ██████╗ ██╗     ███████╗ ██████╗ ██████╗ 		";
		@echo " ██║    ██║██╔═══██╗██║     ██╔════╝ ╚════██╗██╔══██╗		";
		@echo " ██║ █╗ ██║██║   ██║██║     █████╗    █████╔╝██║  ██║		";
		@echo " ██║███╗██║██║   ██║██║     ██╔══╝    ╚═══██╗██║  ██║		";
		@echo " ╚███╔███╔╝╚██████╔╝███████╗██║      ██████╔╝██████╔╝		";
		@echo " ╚══╝╚══╝  ╚═════╝ ╚══════╝╚═╝      ╚═════╝ ╚═════╝ 			";
		@echo "																";
		@echo "				Made by : \033[1;91mSpiderX\033[m				";
		@echo "																";
		@make -C libft
		@$(CC) $(LDFLAGS) $(LDLIBS) $^ -o $@
		@echo "Compilation of Wolf3D:  \033[1;32mOK\033[m"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(HEADER)
		@mkdir $(OBJ_PATH) 2> /dev/null || true
		@$(CC) $(CFLAGS) -c $< $(CPPFLAGS) -o $@

clean:
		@make -C libft clean
		@rm -f $(OBJ)
		@rmdir $(OBJ_PATH) 2> /dev/null || true
		@echo "Wolf3D : Removing Objs"

fclean: clean
		@make -C libft fclean
		@rm -f $(NAME)
		@echo "Wolf3D : Removing Fractol"

re: fclean all

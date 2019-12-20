# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hezzahir <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/08 15:00:21 by hezzahir          #+#    #+#              #
#    Updated: 2018/11/16 02:26:02 by hezzahir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

HEAD = libft.h

all: $(NAME)

$(NAME):
	gcc -I$(HEAD) -Wall -Werror -Wextra -c *.c
	ar rc $(NAME) *.o
	ranlib $(NAME)
clean:
	/bin/rm -rf *.o
fclean: clean
	/bin/rm -f $(NAME)
re: fclean all

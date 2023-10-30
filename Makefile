# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akambou <akambou@student.42barcelona.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/11 18:35:06 by akambou           #+#    #+#              #
#    Updated: 2023/10/30 02:58:51 by akambou          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc

FLAGS = -Wall -Wextra -Werror

SOURCE  =  src/moves/*.c \
		   src/sort/*.c \
		   src/utils/*.c \
		   src/push_swap.c

$(NAME):
	$(CC) $(FLAGS) $(SOURCE) -Iincludes -o $(NAME)

all: $(NAME)

clean:
	@rm -rf src/*.o
	@rm -rf src/moves/*.o
	@rm -rf src/sort/*.o
	@rm -rf src/utils/*.o

fclean: clean
	@rm -rf $(NAME)

re: fclean all

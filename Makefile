# **************************************************************************** #
#	  #
#	 :::	  ::::::::	#
#	Makefile	   :+:	  :+:	:+:	#
#	 +:+ +:+	 +:+	  #
#	By: akambou <akambou@student.42barcelona.com>  +#+  +:+	   +#+	 #
#	 +#+#+#+#+#+   +#+	#
#	Created: 2023/10/11 18:35:06 by akambou	   #+#	#+#	  #
#	Updated: 2023/10/30 02:58:51 by akambou	  ###   ########.fr	#
#	  #
# **************************************************************************** #

NAME = push_swap

CC = gcc
RM = rm -rf

CFLAGS = -Wall -Wextra -Werror -o$(INCL)

INCL = includes/push_swap.h
OBJ_DIR = obj/
OBJS = $(SRCS:%.c=$(OBJ_DIR)%.o)
SRCS = $(wildcard src/moves/*.c src/sort/*.c src/utils/*.c src/*.c)

$(OBJ_DIR)%.o: %.c
	@mkdir -p $(@D)
	@printf "\033[0;33m\rCompiling -> $< ✅                        \033[0m"
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@echo -e "\033[0;32mPush Swap created 📚\033[0m"

clean:
	@$(RM) $(OBJ) $(OBJ_DIR)
	@echo -e "\033[0;31mCleaned objects 🧹\033[0m"

fclean: clean
	@$(RM) $(NAME) $(OBJ_DIR) $(OBJ)
	@echo -e "\033[0;31mCleaned libft 🧹\033[0m"
re: fclean all

.PHONY: all clean fclean re

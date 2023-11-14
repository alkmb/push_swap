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

FLAGS = -Wall -Wextra -Werror

SOURCE  =	$(wildcard src/moves/*.c) \
			$(wildcard src/sort/*.c) \
			$(wildcard src/utils/*.c) \
			src/push_swap.c

OBJ = $(patsubst src/%.c,obj/%.o,$(SOURCE))

$(NAME): $(OBJ)
	@echo "🔨 Building $(NAME)..."
	@$(CC) $(FLAGS) $(OBJ) -Iincludes -o $(NAME)
	@echo "✅ $(NAME) compiled successfully."

obj/%.o : src/%.c
	@mkdir -p $(@D)
	@echo "🔨 Compiling $<..."
	@$(CC) $(FLAGS) -c $< -o $@
	@echo "✅ $< compiled successfully."

all: $(NAME)

clean:
	@echo "🧹 Cleaning object files..."
	@rm -rf obj
	@echo "✅ Object files cleaned successfully."

fclean: clean
	@echo "🧹 Cleaning $(NAME)..."
	@rm -rf $(NAME)
	@echo "✅ $(NAME) cleaned successfully."

re: fclean all

.PHONY: all clean fclean re

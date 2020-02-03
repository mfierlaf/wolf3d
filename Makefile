# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tde-brit <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/24 14:58:04 by tde-brit          #+#    #+#              #
#    Updated: 2019/11/12 12:04:43 by tde-brit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
GREEN = \033[0;32m
NC = \033[0m

NAME = Wolf3D

SRCS = src/main.c src/key.c src/parsing.c src/tools.c src/bresenham.c \
src/raycasting.c src/draw.c

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	@make re -C ./libft
	@echo "${GREEN}Libft Done ✓${NC}"
	@make clean
	@gcc $(FLAGS) -o $(NAME) $(SRCS) -L libft/ -lft  -L ./minilibx_macos \
	-lmlx -framework OpenGL -framework AppKit
	@echo "${GREEN}Compilation Done ✓${NC}"

clean:
	@make clean -C ./libft

fclean: clean
	@rm -f $(NAME)
	@make fclean -C ./libft

re: fclean all

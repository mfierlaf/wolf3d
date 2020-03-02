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

NAME = Wolf3D
FLAGS = -Wall -Wextra -Werror -O3

MLX_DIR = ./minilibx_macos
MLX = -L$(MLX_DIR) -lmlx -framework OpenGL -framework Appkit -O3

INCL = header/
LIBFT_DIR = libft/

SRCS_DIR = ./srcs/
SRCS =	main.c key.c parsing.c tools.c textures.c\
		raycasting.c draw.c minimap.c move.c

FILES = $(addprefix $(SRCS_DIR),$(SRCS))
OBJS_DIR = ./objs/
OBJS = $(addprefix $(OBJS_DIR), $(SRCS:.c=.o))

all : $(NAME)

$(NAME) : $(OBJS)
	@echo "Compiling libft"
	@make -C $(LIBFT_DIR)
	@echo "Compiling minilibx"
	@make -C $(MLX_DIR)
	@echo "Creating binary file."
	@gcc $(FLAGS) -L$(LIBFT_DIR) -lft $(MLX) $(OBJS) -o $(NAME)
	@echo "Cleaning libft"

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	@echo "Compiling $@"
	@mkdir -p $(dir $@) && gcc $(FLAGS) -c $< -o $@

clean :
	@echo "Removing .o files."
	@make clean -C $(LIBFT_DIR)
	@make clean -C $(MLX_DIR)
	@rm -rf $(OBJS_DIR)

fclean : clean
	@echo "Removing binary file."
	@make fclean -C $(LIBFT_DIR)
	@rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfierlaf <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/04 15:16:48 by mfierlaf          #+#    #+#              #
#    Updated: 2019/10/30 17:02:05 by mfierlaf         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FCT = ft_isalpha ft_putendl_fd ft_putstr_fd ft_strdup ft_strstr ft_isdigit \
ft_putchar ft_putnbr ft_strcat ft_strncat ft_tolower ft_atoi ft_isprint \
ft_putchar_fd ft_putnbr_fd ft_strcmp ft_strncmp ft_toupper ft_isalnum \
ft_itoa ft_putendl ft_putstr ft_strcpy ft_strncpy ft_isascii ft_memset \
ft_bzero ft_memcpy ft_memccpy ft_memmove ft_memchr ft_memcmp ft_strlen \
ft_strlcat ft_strchr ft_strrchr ft_strnstr ft_memalloc ft_memdel ft_strnew \
ft_strdel ft_strclr ft_striter ft_striteri ft_strmap ft_strmapi ft_strequ \
ft_strnequ ft_strsub ft_strjoin ft_strtrim ft_strsplit ft_lstnew \
ft_freechararray ft_lstdelone ft_lstdel ft_lstadd ft_lstiter ft_lstmap \
ft_print_table ft_sqrt ft_strjoin_free ft_printf get_next_line ft_strlcpy

all : $(NAME)

$(NAME) :
	@gcc -Wall -Werror -Wextra -c $(addsuffix .c, $(FCT))
	@ar rc $(NAME) $(addsuffix .o, $(FCT))
	@ranlib $(NAME)
clean :
	@rm -rf $(addsuffix .o, $(FCT))
fclean : clean
	@rm -rf $(NAME)
re : fclean all

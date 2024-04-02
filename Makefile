# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iboiraza <iboiraza@student.42urduliz.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/09 10:13:19 by iboiraza          #+#    #+#              #
#    Updated: 2024/04/01 16:50:32 by iboiraza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= cc
HEADERS_DIR	= .
CFLAGS	= -Wall -Wextra -Werror -I $(HEADERS_DIR)
NAME	= libftprintf.a
RM		= rm -fr

CFILES = ft_printf.c ft_write_pointer.c ft_write_num.c ft_write_char.c \
		 ft_write_str.c

OFILES = $(CFILES:.c=.o)

all: $(NAME)

$(NAME): $(OFILES)
	ar rcs $(NAME) $(OFILES)

clean:
	$(RM) $(OFILES)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re

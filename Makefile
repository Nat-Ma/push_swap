# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: natalierauh <natalierauh@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/08 19:05:59 by natalierauh       #+#    #+#              #
#    Updated: 2024/08/16 18:25:52 by natalierauh      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

INCLUDES = -I includes/.

NAME = push_swap
LIBFT = libft/libft.a

SRC = main.c init_stack.c free_mem.c error.c validate_input.c ft_atol.c \
	swap.c rotate.c push.c tiny_sort.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

libft/libft.a:
	make -C libft

$(NAME): $(OBJ) libft/libft.a
	$(CC) $(CFLAGS) $(OBJ) -g -Llibft -lft -o $@

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -g -Ilibft/includes -c $< -o $@

clean:
	make clean -C libft
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME) libft/libft.a

re: fclean all

.PHONY: all clean fclean re

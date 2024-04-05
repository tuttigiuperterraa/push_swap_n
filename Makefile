# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gcosenza <gcosenza@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/19 17:07:02 by aconti            #+#    #+#              #
#    Updated: 2024/04/05 08:51:01 by gcosenza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = gcc
CFLAGS = -Wall -Wextra -Werror
DEBUG_FLAGS = -g

SRCS = atoi.c checks.c main.c math.c push_utils.c push.c rev_rotate.c rotate_utils.c rotate.c sort.c stackA.c swap.c utils.c
OBJ = $(SRCS:.c=.o)

NAME = push_swap

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(DEBUG_FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

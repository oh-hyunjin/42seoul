# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyoh <hyoh@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/03 12:29:03 by hyoh              #+#    #+#              #
#    Updated: 2022/11/03 14:17:03 by hyoh             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap

CC			=	cc
CFLAG		=	-Wall -Wextra -Werror
AR			=	ar -crs
RM			=	rm -f

LIB_DIR		=	./libft

SRC			=	push_swap.c

OBJ			=	$(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	make -C $(LIB_DIR)
	$(CC) $(CFLAG) $(OBJ) -L $(LIB_DIR) -l ft -o $(NAME)

%.o : %.C
	$(CC) $(CFLAG) -c $< -o $@

clean :
	make clean -C $(LIB_DIR)

fclean : clean
	make fclean -C $(LIB_DIR)
	$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re
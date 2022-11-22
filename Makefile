# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyoh <hyoh@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/03 12:29:03 by hyoh              #+#    #+#              #
#    Updated: 2022/11/22 08:52:39 by hyoh             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap

CC			=	cc
CFLAG		=	-Wall -Wextra -Werror
AR			=	ar -crs
RM			=	rm -f

SRC_DIR		=	./src
LIB_DIR		=	./lib

SRC			=	main.c\
				push_swap.c\
				instruction.c\
				instruction2.c\
				instruction_utils.c\
				greedy.c\
				utils.c

OBJ		=	$(addprefix $(SRC_DIR)/, $(SRC:.c=.o))

all : $(NAME)

$(NAME) : $(OBJ)
	make -C $(LIB_DIR)
	$(CC) $(CFLAG) $(OBJ) -L $(LIB_DIR) -l _ft -o $(NAME)

%.o : %.C
	$(CC) $(CFLAG) -c $< -o $@

clean :
	make clean -C $(LIB_DIR)
	$(RM) $(OBJ)

fclean : clean
	make fclean -C $(LIB_DIR)
	$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re
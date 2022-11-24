# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyoh <hyoh@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/03 12:29:03 by hyoh              #+#    #+#              #
#    Updated: 2022/11/24 09:32:58 by hyoh             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap
NAME_BN		=	checker

CC			=	cc
CFLAG		=	-Wall -Wextra -Werror -g3#지우기
AR			=	ar -crs
RM			=	rm -f

SRC_DIR		=	./src
SRC_BN_DIR	=	./bonus
LIB_DIR		=	./lib

SRC			=	main.c\
				push_swap.c\
				instruction.c\
				instruction2.c\
				instruction_utils.c\
				greedy.c\
				utils.c

SRC_BN		=	checker_bonus.c\
				push_swap_bonus.c\
				instruction_utils_bonus.c\
				instruction_together_bonus.c\
				utils_bonus.c

OBJ			=	$(addprefix $(SRC_DIR)/, $(SRC:.c=.o))
OBJ_BN		=	$(addprefix $(SRC_BN_DIR)/, $(SRC_BN:.c=.o))

ifdef WITH_BONUS
	NAME = $(NAME_BN)
	OBJECT = $(OBJ_BN)
else
	OBJECT = $(OBJ)
endif

all : $(NAME)

$(NAME) : $(OBJECT)
	make -C $(LIB_DIR)
	$(CC) $(CFLAG) $(OBJECT) -L $(LIB_DIR) -l _ft -o $(NAME)

%.o : %.c
	$(CC) $(CFLAG) -c $< -o $@

bonus :
	make WITH_BONUS=1 all

clean :
	make clean -C $(LIB_DIR)
	$(RM) $(OBJ) $(OBJ_BN)

fclean : clean
	make fclean -C $(LIB_DIR)
	$(RM) $(NAME) $(NAME_BN)

re : fclean all

.PHONY: all clean fclean re bonus
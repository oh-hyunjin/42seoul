# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyoh <hyoh@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/10 14:01:37 by hyoh              #+#    #+#              #
#    Updated: 2022/11/23 15:23:17 by hyoh             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc
CFLAG = -Wall -Wextra -Werror
RM = rm -f
AR = ar -crs

SRCS	=	ft_printf.c \
			option.c \
			type.c \
			put.c \
			getlen.c


OBJECT = $(SRCS:.c=.o)

all : $(NAME)

bonus :
	make WITH_BONUS=1 all

%.o : %.c
	$(CC) $(CFLAG) -c $< -o $@

$(NAME) : $(OBJECT)
	$(AR) $@ $^

clean :
	$(RM) $(OBJECT)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re bonus

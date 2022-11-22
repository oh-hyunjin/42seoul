# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyoh <hyoh@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/22 08:11:20 by hyoh              #+#    #+#              #
#    Updated: 2022/11/22 08:50:04 by hyoh             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	lib_ft.a

CC				=	cc
CFLAG			=	-Wall -Wextra -Werror
RM				=	rm -f
AR				=	ar -crs

LIBFT_DIR		=	./src/libft
FT_PRINTF_DIR	=	./src/ft_printf

LIBFT_SRC		=	ft_isalpha.c \
					ft_isdigit.c \
					ft_isalnum.c \
					ft_isascii.c \
					ft_isprint.c \
					ft_strlen.c \
					ft_memset.c \
					ft_bzero.c \
					ft_memcpy.c \
					ft_memmove.c \
					ft_strlcpy.c \
					ft_strlcat.c \
					ft_toupper.c \
					ft_tolower.c \
					ft_strchr.c \
					ft_strrchr.c \
					ft_strncmp.c \
					ft_memcmp.c \
					ft_memchr.c \
					ft_strnstr.c \
					ft_atoi.c \
					ft_calloc.c \
					ft_strdup.c \
					ft_substr.c \
					ft_strjoin.c \
					ft_strtrim.c \
					ft_split.c \
					ft_itoa.c \
					ft_strmapi.c \
					ft_striteri.c \
					ft_putchar_fd.c \
					ft_putstr_fd.c \
					ft_putendl_fd.c \
					ft_putnbr_fd.c \
					ft_lstnew.c \
					ft_lstadd_front.c \
					ft_lstsize.c \
					ft_lstlast.c \
					ft_lstadd_back.c \
					ft_lstdelone.c \
					ft_lstclear.c \
					ft_lstiter.c \
					ft_lstmap.c

FT_PRINTF_SRC	=	ft_printf.c \
					option.c \
					type.c \
					put.c \
					getlen.c \
					ft_printf_bonus.c \
					option_bonus.c \
					type_bonus.c \
					put_bonus.c \
					getlen_bonus.c

LIBFT_OBJ		=	$(addprefix $(LIBFT_DIR)/, $(LIBFT_SRC:.c=.o))
FT_PRINTF_OBJ	=	$(addprefix $(FT_PRINTF_DIR)/, $(FT_PRINTF_SRC:.c=.o))

all : $(NAME)

$(NAME) : $(LIBFT_OBJ) $(FT_PRINTF_OBJ)

%.o : %.c
	$(CC) $(CFLAG) -c $< -o $@
	$(AR) $(NAME) $@

clean :
	$(RM) $(LIBFT_OBJ)
	$(RM) $(FT_PRINTF_OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean all #ㅇㅣ게먼디

.PHONY : all clean fclean re libft ft_printf
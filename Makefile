# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pferrete <pferrete@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/03 14:55:28 by pferrete          #+#    #+#              #
#    Updated: 2023/05/16 17:07:24 by pferrete         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# name of project
NAME=libftprintf.a

# .c files
C_SOURCE=\
	ft_printf.c \
	ft_putchar.c \
	ft_puthex.c \
	ft_putnbr.c \
	ft_putptr.c \
	ft_putstr.c \
	ft_putunsig.c \

# .h files
H_SOURCES=ft_printf.h

# Objects files
OBJ=$(C_SOURCE:.c=.o)

# flags compiler
CCFLAGS = -Wall -Wextra -Werror

AR = ar

ARFLAGS = rcs

# compilation
all: $(NAME)

$(NAME) : $(OBJ)
	$(AR) $(ARFLAGS) $(NAME) $(OBJ)

%.o: %.c %.h
	$(CC) $(CCFLAGS) -c $(C_SOURCE)

clean:
	rm -f $(NAME) $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re


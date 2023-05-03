# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pferrete <pferrete@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/03 14:55:28 by pferrete          #+#    #+#              #
#    Updated: 2023/05/03 16:27:21 by pferrete         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# name of project
NAME=libftprinf.a

# .c files
C_SOURCE = \

# .h files
H_SOURCES=libftprintf.h

# Objects files
OBJ=$(C_SOURCE:.c=.o)

# flags compiler
CCFLAGS = -Wall -Wextra -Werror

AR=@ar
ARARFLAG = rcs

# compilation
all: $(NAME)

$(NAME) : $(OBJ)
	$(AR) $(ARFLAGS) $(NAME) $(OBJ)

%.o: %.c %.h
	$(CC) $(CCFLAGS) -c $< -o $@

clean:
	rm -f $(NAME) $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bschmid <marvin@42lausanne.ch>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/19 11:12:49 by bschmid           #+#    #+#              #
#    Updated: 2024/08/14 12:02:03 by bschmid          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = $(shell find ft_printf libft GNL -name "*.c")
NAME = my_lib.a
CFLAGS = -Wall -Werror -Wextra
OBJS = ${SRCS:.c=.o}
LIBC = ar rcs
CC = cc

RM = rm -f

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
		${LIBC} ${NAME} ${OBJS}

all: 	${NAME}

clean:
		${RM} ${OBJS}

fclean: clean
		${RM} ${NAME}

re: fclean all

.PHONY : all clean fclean re

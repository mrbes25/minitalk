# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bschmid <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/26 09:05:25 by bschmid           #+#    #+#              #
#    Updated: 2024/08/26 10:12:43 by bschmid          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# Standard
NAME				= client
SVR					= server

# Directories
MY_LIB				= ./my_lib/my_lib.a
INC					= inc/
SRC_DIR				= src/
OBJ_DIR				= obj/

# Compiler and CFlags
CC					= gcc
CFLAGS				= -Wall -Werror -Wextra -I
RM					= rm -f

# Create full paths for source and object files
SRCCL 				= $(addprefix $(SRC_DIR), $(addsuffix .c, $(NAME)))
SRCSV 				= $(addprefix $(SRC_DIR), $(addsuffix .c, $(SVR)))

OBJCL 				= $(addprefix $(OBJ_DIR), $(addsuffix .o, $(NAME)))
OBJSV 				= $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SVR)))

# Targets
start:
					@make all

$(MY_LIB):
					@make -C ./my_lib

all:				$(NAME) $(SVR)

$(NAME):			$(OBJCL) $(MY_LIB)
					@$(CC) $(CFLAGS) $(INC) $(OBJCL) $(MY_LIB) -o $(NAME)

$(SVR):				$(OBJSV) $(MY_LIB)
					@$(CC) $(CFLAGS) $(INC) $(OBJSV) $(MY_LIB) -o $(SVR)

# Compile object files from source files
$(OBJ_DIR)%.o:		$(SRC_DIR)%.c
					@mkdir -p $(@D)
					@$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
					@$(RM) -r $(OBJ_DIR)
					@make clean -C ./my_lib

fclean:				clean
					@$(RM) $(NAME) $(SVR)
					@$(RM) $(MY_LIB)

re:					fclean all

# Phony targets represent actions not files
.PHONY:				start all clean fclean re bonus

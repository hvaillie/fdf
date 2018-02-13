# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hvaillie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/13 15:34:39 by hvaillie          #+#    #+#              #
#    Updated: 2018/02/13 15:34:44 by hvaillie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = main.c \
	  parser.c \
	  manage_mem.c \
	  load_file.c

OBJ = $(SRC:.c=.o)

SRC_PATH = srcs/
SRC_POS = $(addprefix $(SRC_PATH),$(SRC))

INC_PATH = includes/

LIBFT =	./libft/libft.a
INC_LIBFT_PATH = libft/includes

CC = gcc
FLAGS = -Wall -Wextra -Werror -I $(INC_LIBFT_PATH) -I $(INC_PATH)

# COLORS
C_NO			=	"\033[00m"
C_OK			=	"\033[35m"
C_GOOD			=	"\033[32m"
C_ERROR			=	"\033[31m"
C_WARN			=	"\033[33m"

# DBG MESSAGE
SUCCESS			=	$(C_GOOD)SUCCESS$(C_NO)
OK				=	$(C_OK)OK$(C_NO)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
		@$(CC) $(FLAGS) $(OBJ) $(LIBFT) -o $(NAME)
		@echo "Linking" [ $(NAME) ] $(OK)

$(OBJ): $(SRC_POS)
		@$(CC) $(FLAGS) -c $(SRC_POS)
		@echo "Compiling" [ $(SRC_POS) ] $(SUCCESS)

$(LIBFT):
		@make -C ./libft/

clean:
		@rm -f $(OBJ)
		@echo "Cleaning" [ $(OBJ) ] $(OK)
			@make clean -C ./libft/

fclean: clean
		@rm -f $(NAME)
		@echo "Cleaning" [ $(NAME) ] $(OK)
			@make fclean2 -C ./libft/

re: fclean all

.PHONY : all, re, clean, flcean

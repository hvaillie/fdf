# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hvaillie <hvaillie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 17:14:41 by hvaillie          #+#    #+#              #
#    Updated: 2017/12/08 17:26:47 by hvaillie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -Wextra -Werror -Wall
INCLUDE = includes

NAME = libft.a

SRC = ft_strlen.c ft_strdup.c    ft_strcpy.c   ft_strncpy.c  ft_strcat.c   \
	 ft_strncat.c ft_strlcat.c   ft_strchr.c   ft_strrchr.c  ft_strstr.c   \
	 ft_strnstr.c ft_strcmp.c    ft_strncmp.c  ft_atoi.c     ft_isalpha.c  \
	 ft_isdigit.c ft_isalnum.c   ft_isascii.c  ft_isprint.c  ft_toupper.c  \
	 ft_tolower.c ft_memset.c    ft_bzero.c    ft_memcpy.c   ft_memccpy.c  \
	 ft_memmove.c ft_memchr.c    ft_memcmp.c   ft_memalloc.c ft_memdel.c   \
	 ft_strnew.c  ft_strdel.c    ft_strclr.c   ft_striter.c  ft_striteri.c \
	 ft_strmap.c  ft_strmapi.c   ft_strequ.c   ft_strnequ.c  ft_strsub.c   \
	 ft_strjoin.c ft_strtrim.c   ft_strsplit.c ft_itoa.c     ft_putchar.c  \
	 ft_putstr.c  ft_putendl.c   ft_putnbr.c   ft_isinteger.c \
	 ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
	 ft_lstnew.c  ft_lstdelone.c ft_lstdel.c   ft_lstadd.c   ft_lstiter.c \
	 ft_lstmap.c  ft_lstaddlast.c ft_lstdelm.c \
	 ft_isupper.c ft_islower.c   ft_issepar.c  ft_lgint.c    ft_abs.c \
	 ft_min.c     ft_max.c       ft_sqrt.c     ft_strchrx.c  ft_sqrtround.c \
	 ft_itoa_base.c ft_atoi_base.c ft_strnchr.c \
	 get_next_line.c

OBJ = $(SRC:.c=.o)

SRC_PATH = srcs/

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

$(NAME): $(OBJ)
	@ar -rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "Compiling" [ $(NAME) ] $(SUCCESS)

%.o: $(SRC_PATH)/%.c
	@$(CC) -c -o $@ $< $(FLAGS) -I $(INCLUDE)
	@echo "Linking" [ $< ] $(OK)


clean:
	@/bin/rm -f $(OBJ)
	@echo "Cleaning" [ $(OBJ) ] $(OK)

fclean: clean fclean2

fclean2:
	@/bin/rm -f $(NAME)
	@echo "Cleaning" [ $(NAME) ] $(OK)

re: fclean all

.PHONY : all, re, clean, fclean

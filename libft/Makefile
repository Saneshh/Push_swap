# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hsolet <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/01 03:17:57 by hsolet            #+#    #+#              #
#    Updated: 2024/04/10 12:44:18 by hsolet           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra -g
SRC = 		 ft_isdigit.c \
			 ft_isalnum.c \
			 ft_putnbr_fd.c \
			 ft_substr.c \
			 ft_isprint.c \
			 ft_strdup.c \
			 ft_itoa.c \
			 ft_tolower.c \
			 ft_isalpha.c \
			 ft_strlcpy.c \
			 ft_putendl_fd.c \
			 ft_strlen.c \
			 ft_atoi.c \
			 ft_putstr_fd.c \
			 ft_isascii.c \
			 ft_strjoin.c \
			 ft_strncmp.c \
			 ft_putchar_fd.c \
			 ft_toupper.c \
			 ft_strtrim.c \
			 ft_strchr.c \
			 ft_strrchr.c \
			 ft_strlcat.c \
			 ft_strnstr.c \
			 ft_bzero.c \
			 ft_memcmp.c \
			 ft_memchr.c \
			 ft_memmove.c \
			 ft_memcpy.c \
			 ft_calloc.c \
			 ft_strmapi.c \
			 ft_striteri.c \
			 ft_split.c \
			 ft_memset.c \
			 ft_printf/ft_putnbr.c \
			 ft_printf/ft_count_nbr.c \
			 ft_printf/ft_count_hexa.c \
			 ft_printf/ft_str_len.c \
			 ft_printf/ft_void_hexa.c \
			 ft_printf/ft_putstr.c \
			 ft_printf/ft_putnbr_base.c \
			 ft_printf/ft_printf.c \
			 ft_printf/ft_putchar.c \

OBJ = $(SRC:.c=.o)
NAME = libft.a

all : $(NAME)

$(NAME): $(OBJ)
	@ar -rcs $(NAME) $(OBJ)
	@echo "\033[0mlibrary Libft Created ☑️"

%.o: %.c
	@echo -n "\033[0mCompilation $@ : "
	@$(CC) -o $@ -c $< $(CFLAGS)
	@echo -n "\033[0m ☑️ \n"

clean: 
	@rm -f $(OBJ)
	@echo "Object clean ☑️"

fclean: clean
	@rm -f $(NAME)
	@echo "Clean All ☑️"

re: fclean all


.PHONY: clean fclean re all

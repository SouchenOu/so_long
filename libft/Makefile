# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: souchen <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/08 14:59:25 by souchen           #+#    #+#              #
#    Updated: 2022/03/27 19:33:08 by souchen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
CC=cc
FLAGS    = -Wall -Werror -Wextra -I libft.h
AR=ar crs
RM=rm -rf
FICHIER= ft_isalpha ft_isdigit ft_isalnum ft_isascii ft_strlen \
		 ft_toupper ft_tolower ft_strchr ft_strrchr ft_strncmp \
		 ft_strnstr ft_strlcpy ft_strlcat ft_memcpy \
		 ft_memset ft_bzero ft_memmove ft_memchr ft_memcmp ft_calloc \
		 ft_substr ft_strjoin ft_strtrim ft_split ft_itoa \
		 ft_strmapi  ft_putchar_fd ft_putstr_fd ft_putendl_fd \
		 ft_putnbr_fd ft_isprint ft_striteri ft_lstnew ft_lstadd_front \
		 ft_lstsize ft_lstlast ft_lstadd_back ft_lstdelone \
		 ft_lstclear ft_lstiter get_next_line  get_next_line_utils ft_printf ft_printf_chr \
		 ft_printf_nbr ft_printf_utils ft_putnbrx ft_put0x ft_putnstr ft_nbrlen ft_putuns_fd ft_atoi
OBJ= $(FICHIER:=.o)
SRC=$(FICHIER:=.c)
NAME=libft.a

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

bonus : all

%.o: %.c
	$(CC) $(FLAGS) -c $? -o $@
	

clean:
	$(RM) $(OBJ) 

fclean: clean
	$(RM) $(NAME)
re: fclean all

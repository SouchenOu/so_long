# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: souchen <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/15 11:08:10 by souchen           #+#    #+#              #
#    Updated: 2022/03/27 19:32:54 by souchen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
CC = cc
NAME_M = so_long
NAME_B = so_long_bonus
RM = rm -rf
FILES_M = so_long.c map.c check_maps.c movements_person.c key.c collectable.c

FILES_B = so_long_bonus.c check_maps_bonus.c collectable_bonus.c key_bonus.c map_bonus.c movements_enemy_bonus.c  movements_person_bonus.c check_enemy.c animation.c

OBJ_FILES_M = $(FILES_M:.c=.o)

OBJ_FILES_B = $(FILES_B:.c=.o)

HEADER = header/so_long.h

HEADER_B = header/so_long_bonus.h

LIBFT = libft/libft.a

MLXFLAGS = -lmlx -framework OpenGL -framework AppKit -lz
FLAGS = -Wall -Wextra -Werror
all: $(NAME_M)
bonus: $(NAME_B)
$(NAME_M): $(OBJ_FILES_M) $(LIBFT)
	cc $(OBJ_FILES_M) $(LIBFT) $(FLAGS) $(MLXFLAGS) -o $(NAME_M)

$(NAME_B): $(OBJ_FILES_B) $(LIBFT)
	cc $(OBJ_FILES_B) $(LIBFT) $(FLAGS) $(MLXFLAGS) -o $(NAME_B)

%.o : %.c $(HEADER) $(HEADER_B)
	$(CC) $(FLAGS)  -c $< -o $@


$(LIBFT):
	make -C libft
	make clean -C libft
clean:
	$(RM) $(OBJ_FILES_M)
	$(RM) $(OBJ_FILES_B)

fclean: clean
	$(RM) $(NAME_M)
	$(RM) $(NAME_B)
	$(RM) libft/libft.a

re: fclean all

.PHONY: all clean fclean re

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tamarant <tamarant@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/16 16:56:38 by tamarant          #+#    #+#              #
#    Updated: 2020/02/20 14:35:27 by tamarant         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ./test

FILES = checker.c \
        operations.c \
        save_data.c \
        not_mine_get_next_line.c \

SRC = $(addprefix src/,$(FILES))

OBJ = $(addprefix obj/,$(FILES:.c=.o))

LIB = ft_printf/libft/libft.a

LIB2 = ft_printf/libftprintf.a

FLAGS =

all : $(NAME)

$(NAME) : $(OBJ) inc/
	@make -C ft_printf/libft/
	@make -C ft_printf/
	gcc -o $(NAME) $(FLAGS) $(OBJ) $(LIB)  $(LIB2)

obj/%.o: src/%.c
	@mkdir -p obj/
	@gcc $(FLAGS) -Iinc -o $@ -c $<

clean :
	@make clean -C ft_printf/libft/
	@make clean -C ft_printf/
	@rm -rf obj/

fclean : clean
	@make fclean -C ft_printf/libft/
	@make fclean -C ft_printf/
	@rm -f $(NAME)

re : fclean all
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fboggs <fboggs@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/15 17:31:35 by fboggs            #+#    #+#              #
#    Updated: 2020/05/14 03:25:42 by mac              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PUSH_SWAP = push_swap

HEADER_NAME = push_swap.h
PRINTF_A = ft_printf/libftprintf.a

INC_DIR = ./inc/
INC_PRINTF = ./ft_printf/inc/
SRC_DIR = ./src/
OBJ_DIR = ./obj/

PS_SRC_NAME = push_swap.c not_mine_get_next_line.c operations.c\
save_data.c sort_main.c sort_main_help.c\

HEADER = $(addprefix $(INC_DIR), $(HEADER_NAME))

SRC_PS = $(addprefix $(SRC_DIR), $(PS_SRC_NAME))
OBJ_PS = $(addprefix $(OBJ_DIR), $(PS_SRC_NAME:.c=.o))

FLAGS = -Wall -Wextra -Werror
GCC_PRINTF = -L ./printf -l ftprintf

all: $(PUSH_SWAP)

$(PUSH_SWAP): $(OBJ_DIR) $(OBJ_PS) $(PRINTF_A) $(HEADER)
	gcc $(GCC_PRINTF) $(addprefix -I, $(INC_DIR)) $(OBJ_PS) $(FLAGS) -o $(PUSH_SWAP)

$(OBJ_DIR):
	@mkdir -p obj

$(PRINTF_A):
	make -C ft_printf/

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEADER)
	gcc -c -I $(INC_DIR) -I $(INC_PRINTF) $(FLAGS) $< -o $@

clean:
	make -C ./printf clean
	rm -rf $(OBJ_DIR)

fclean: clean
	make -C ./printf fclean
	rm -f $(PUSH_SWAP)

re: fclean all
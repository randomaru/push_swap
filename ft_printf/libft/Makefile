# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tamarant <tamarant@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/09 18:10:20 by tamarant          #+#    #+#              #
#    Updated: 2020/05/28 16:36:56 by mac              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_atoi.c \
      ft_atoi_base.c \
      ft_bzero.c \
      ft_clear_table.c \
      ft_countwords.c \
      ft_free.c \
      ft_is_minus_inf.c \
      ft_isalnum.c \
      ft_isalpha.c \
      ft_isascii.c \
      ft_isdigit.c \
      ft_isinf.c \
      ft_isnan.c \
      ft_isprint.c \
      ft_iterative_factorial.c \
      ft_iterative_power.c \
      ft_itoa.c \
      ft_lltoa.c \
      ft_llutoa.c \
      ft_lstadd.c \
      ft_lstdel.c \
      ft_lstdelone.c \
      ft_lstiter.c \
      ft_lstmap.c \
      ft_lstnew.c \
      ft_memalloc.c \
      ft_memccpy.c \
      ft_memchr.c \
      ft_memcmp.c \
      ft_memcpy.c \
      ft_memdel.c \
      ft_memmove.c \
      ft_memset.c \
      ft_pow.c \
      ft_pow_double.c \
      ft_putchar.c \
      ft_putchar_fd.c \
      ft_putendl.c \
      ft_putendl_fd.c \
      ft_putnbr.c \
      ft_putnbr_fd.c \
      ft_putnbr_max.c \
      ft_putstr.c \
      ft_putstr_fd.c \
      ft_sqrt.c \
      ft_strcat.c \
      ft_strchr.c \
      ft_strclr.c \
      ft_strcmp.c \
      ft_strcpy.c \
      ft_strdel.c \
      ft_strdup.c \
      ft_strequ.c \
      ft_striter.c \
      ft_striteri.c \
      ft_strjoin.c \
      ft_strjoin_free.c \
      ft_strlcat.c \
      ft_strlen.c \
      ft_strmap.c \
      ft_strmapi.c \
      ft_strncat.c \
      ft_strncmp.c \
      ft_strncpy.c \
      ft_strnequ.c \
      ft_strnew.c \
      ft_strnstr.c \
      ft_strrchr.c \
      ft_strsplit.c \
      ft_strstr.c \
      ft_strsub.c \
      ft_strtrim.c \
      ft_tolower.c \
      ft_toupper.c \
      ft_ulltoa.c \
      get_next_line.c \
      int_max_atoi.c \
      itoa_base.c \
      number_len.c \
      number_len_ll.c \
      number_len_ull.c \
      to_uppercase.c \
      ulltoa_base.c \

HEADER = libft.h

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(HEADER) $(OBJ)
				@gcc $(FLAGS) -I $(HEADER) -c $(SRC)
				ar rc $(NAME) $(OBJ)
				ranlib $(NAME)

clean:
				rm -rf $(OBJ)

fclean: clean
				rm -rf $(NAME)
				rm -rf $(OBJ)

re: fclean all

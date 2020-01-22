cmake_minimum_required(VERSION 3.15)
project(push_swap C)

set(CMAKE_C_STANDARD 11)

include_directories(libft)

add_executable(push_swap
        inc/push_swap.h
        src/save_data.c
        src/operations.c
        src/push_swap.c
        src/checker.c

        )
target_link_libraries(push_swap /Users/tamarant/Desktop/projects/push_swap/ft_printf/libft/libft.a)
target_link_libraries(push_swap /Users/tamarant/Desktop/projects/push_swap/ft_printf/libftprintf.a)

#target_link_libraries(push_swap /Users/mac/Desktop/projects/push_swap/ft_printf/libft/libft.a)
#target_link_libraries(push_swap /Users/mac/Desktop/projects/push_swap/ft_printf/libftprintf.a)

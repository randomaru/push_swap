/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamarant <tamarant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 13:29:30 by tamarant          #+#    #+#             */
/*   Updated: 2020/01/28 21:24:08 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "not_mine_get_next_line.h"
# include "../ft_printf/libft/libft.h"
# include "../ft_printf/inc/ft_printf.h"

	typedef struct		s_number
	{
		int 			number;
		int				index;
		int 			rank;
		struct s_number	*next;
		struct s_number	*prev;

	}					t_num;

	typedef struct		s_args
	{
		t_num 			*head_a;
		t_num 			*head_b;
		t_num 			*tail_a;
		t_num 			*tail_b;

		int 			stack_a_num;
		int 			stack_b_num;
		int 			max_index_stack_a;
		int 			min_index_stack_a;
	}					t_args;

void 					final_free(t_num **head);
t_num					*new_t_num(void);
t_args 					*new_t_args(void);
void					set_index(t_num **head);
int						save_numbers(char *argv, t_num **new, t_args **storage);
int						s_swap(t_num **head);
int						r_rotate(t_num **head, t_num **tail);
int						rr_reverse(t_num **head, t_num **tail);
//int						push(char c, t_num **head_a, t_num **head_b);
int						push(char c, t_args **storage);
void	set_rank(t_args **storage);
int		set_sub_rank(t_args **storage, int rank, int index_min);
int		sort_by_rank(t_args **storage);
int		sort_by_sub_rank(t_args **storage);

void	**sort_stack_a(t_args **storage);

void	**sort_stack_a(t_args **storage);


int		is_sorted(t_num *head);


#endif

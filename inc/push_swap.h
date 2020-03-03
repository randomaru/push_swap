/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamarant <tamarant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 13:29:30 by tamarant          #+#    #+#             */
/*   Updated: 2020/03/03 18:14:58 by tamarant         ###   ########.fr       */
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
//		int 			sub_rank;
//		int				depth;
		struct s_number	*next;
		struct s_number	*prev;
	}					t_num;

	typedef struct		s_args
	{
		t_num 			*head_a;
		t_num 			*head_b;
		t_num 			*tail_a;
		t_num 			*tail_b;
		int				curr_rank;
		int 			stack_a_num;
		int 			stack_b_num;
	}					t_args;

void 					final_free(t_num **head);
t_num					*new_t_num(void);
t_args 					*new_t_args(void);
void					set_index(t_num **head);
int						save_numbers(char *argv, t_num **new, t_args **storage);
int						s_swap(t_num **head);
int						r_rotate(t_num **head, t_num **tail);
int						rr_reverse(t_num **head, t_num **tail);
int						push(char c, t_args **storage);
void					print_stacks(t_num *head_a, t_num *head_b);
int		stack_b_division(t_args **storage);
int		stack_a_division(t_args **storage, int step);
int		find_min_stack_b(t_args *storage);
int		find_min_stack_a(t_args *storage, int rank);
int		small_sort(t_args **storage, int subrank);
int		sort_head_a(t_args **storage);
int		find_len_of_rank(t_num *head, int rank);
int		sort_4_6(t_args **storage, int len);
int 	is_tail_sorted(t_args *storage, int len, int rank);
int 	is_stack_a_sorted(t_args *storage);
int		sort_main(t_args **storage);





#endif

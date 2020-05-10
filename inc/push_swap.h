/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamarant <tamarant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 13:29:30 by tamarant          #+#    #+#             */
/*   Updated: 2020/05/10 22:14:58 by mac              ###   ########.fr       */
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
		int 			rank;/////delete
		int				flag;
		int 			sort;
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

		int				min;
		int 			mid;
		int				max;
		int				flag;
		int 			next;
		char 			curr_stack;
		int 			counter;
	}					t_args;

void					final_free(t_num **head);
t_num					*new_t_num(void);
t_args					*new_t_args(void);
int						set_index(t_num **head);
int						save_numbers(char *argv, t_num **new, t_args **storage);
int						s_swap(t_num **head, int *counter);
int						r_rotate(t_num **head, t_num **tail, int *counter);
int						rr_reverse(t_num **head, t_num **tail, int *counter);
int						rrr_reverse(t_args **storage);
int						push(char c, t_args **storage, int *counter);
void					print_stacks(t_num *head_a, t_num *head_b);
int						sort_main(t_args **storage);

int						find_stack_min(t_args *storage);
int						find_stack_max(char c, t_args *storage);
int 					find_not_sorted_part_max(t_args *storage);
int						is_sorted(t_args *storage);

int		small_sort(t_args **storage);



#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamarant <tamarant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 13:29:30 by tamarant          #+#    #+#             */
/*   Updated: 2020/05/30 18:38:41 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../ft_printf/libft/libft.h"
# include "../ft_printf/inc/ft_printf.h"

typedef struct		s_number
{
	int				number;
	int				index;
	int				flag;
	int				sort;
	struct s_number	*next;
	struct s_number	*prev;
}					t_num;

typedef struct		s_args
{
	t_num			*head_a;
	t_num			*head_b;
	t_num			*tail_a;
	t_num			*tail_b;
	int				stack_a_num;
	int				stack_b_num;
	int				flag;
	int				tmp_flag;
	int				next;
	int				counter;
	int				flag_v;
	int				index;
	int				changes;
}					t_args;

void				final_free(t_args **storage, t_num **new);
t_num				*new_t_num(void);
t_args				*new_t_args(void);
int					set_index(t_args **storage);
void				set_prev(t_num **head);
int					save_numbers(char *argv, t_num **new, t_args **storage);
void				s_swap(char c, t_num **head, int *counter);
void				ss_swap(t_args **storage);
void				r_rotate(char c, t_num **head, t_num **tail, int *counter);
void				rr_rotate(t_args **storage, int checker);
void				rr_reverse(char c, t_num **head,
								t_num **tail, int *counter);
void				rrr_reverse(t_args **storage, int checker);
void				push(char c, t_args **storage, int *counter);
void				print_stacks(t_num *head_a, t_num *head_b);
int					sort_main(t_args **storage);
int					find_stack_max(char c, t_args *storage);
int					is_all_sorted(t_args *storage);
void				sort_3(t_args **storage);
void				sort_4(t_args **storage);
int					find_small_part_max(int flag, t_args *storage);
int					find_len_of_part(int flag, t_args **storage);
void				sort_5(t_args **storage);
void				small_sort_a(int len, t_args **storage);
int					find_max_part(int max_min, int len, t_args *storage);
int					small_sort_b(t_args **storage);
void				output_stacks(t_args **storage);
int					find_zero_len(char *str);
int					check_args(int argc, char **argv,
							t_num *new, t_args *storage);
int					init_new(t_num **new, t_args **storage);
int					parse_args(t_args *storage, char *line);
void				output_stacks(t_args **storage);
void				push_help(t_num **to, t_num **from,
							t_num *tmp_next, t_args **storage);
int					first_division(int mid, t_args **storage);
void				sort_3_help_1(t_args *const *storage,
								int min, int mid, int max);
int					sort_3_help_2(t_args **storage, int mid, int max, int len);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamarant <tamarant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 13:29:30 by tamarant          #+#    #+#             */
/*   Updated: 2020/01/20 19:59:33 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../ft_printf/libft/libft.h"
# include "../ft_printf/inc/ft_printf.h"
	typedef struct		s_number
	{
		int 			number;
		int				index;
		int 			group;
		struct s_number	*next;
		struct s_number	*prev;

	}					t_num;

void 					final_free(t_num **head);
t_num					*new_t_num(void);
void					set_index(t_num **head);
int 					save_numbers(char *argv, t_num **new, t_num **head, t_num **tail);
void					s_swap(t_num **head);
void					r_reverse(t_num **head, t_num **tail);
void					rr_reverse(t_num **head, t_num **tail);
void					push(char c, t_num **head_a, t_num **head_b);

#endif

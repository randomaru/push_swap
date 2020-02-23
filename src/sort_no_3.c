/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_no_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamarant <tamarant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 19:41:52 by tamarant          #+#    #+#             */
/*   Updated: 2020/02/23 19:01:06 by tamarant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_part(t_args **storage)
{
	int step_width;
	t_num *tmp;

	tmp = (*storage)->head_a;
 	step_width = (*storage)->stack_a_num / 2;
 	while (tmp)
	{
		if (tmp->index >= 1 && tmp->index < 1 + step_width)
			tmp->rank = 2;
		else
			tmp->rank = 1;
		tmp = tmp->next;
	}
 	sort_by_part(storage);
 	(*storage)->curr_rank = 2;
 }

 void	sort_by_part(t_args **storage)
 {
	 int 	count;

	 count = (*storage)->stack_a_num;
	 while (count--)
	 {
		 if ((*storage)->head_a->rank == 1)
			 r_rotate(&(*storage)->head_a, &(*storage)->tail_a);
		 else if ((*storage)->head_a->rank == 2)
		 {
			 push('b', storage);
			 (*storage)->stack_a_num -= 1;
			 (*storage)->stack_b_num += 1;
		 }
	 }
 }

int		stack_b_division(t_args **storage)
{
 	int		step_width;
 	int		min;
 	int		rank;
 	t_num	*tmp;

 	if ((*storage)->stack_b_num < 4)
 		return (0);
 	if ((*storage)->stack_b_num > 3)
 		step_width = (*storage)->stack_b_num / 2 + (*storage)->stack_b_num % 2;
 	min = find_min_stack_b(*storage);
	tmp = (*storage)->head_b;
	(*storage)->curr_rank += 1;
	while (tmp)
	{

		if (tmp->index >= min && tmp->index < min + step_width)
		{
			r_rotate(&(*storage)->head_b, &(*storage)->tail_b);
			tmp = tmp->next;
		}
		else
		{
			tmp->rank = (*storage)->curr_rank;
			push('a', storage);
			tmp = (*storage)->head_b;
		}
	}
	return (1);
 }

 int	find_min_stack_b(t_args *storage)
 {
 	t_num *tmp;
 	int min;

	 if (!tmp)
		 return (0);
 	tmp = storage->head_b;
 	min = tmp->index;
 	while (tmp)
	{
 		if (tmp->index < min)
 			min = tmp->index;
 		tmp = tmp->next;
	}
 	return (min);

 }
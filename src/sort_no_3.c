/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_no_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamarant <tamarant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 19:41:52 by tamarant          #+#    #+#             */
/*   Updated: 2020/03/06 17:46:41 by tamarant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		stack_a_division(t_args **storage, int step)
{
	int		step_width;
	int 	min;
	int 	len;
	t_num	*tmp;

	min = find_min_stack_a(*storage, (*storage)->curr_rank);
	len = find_len_of_rank((*storage)->head_a, (*storage)->curr_rank);
	step_width = len / 2;
	(*storage)->curr_rank += 1;
	if (step == 1)
	{
		while (len--)
		{
			tmp = (*storage)->head_a;
			if (tmp->index >= min && tmp->index < min + step_width)
			{
				tmp->rank = (*storage)->curr_rank;
				push('b', storage);
			}
			else
				r_rotate(&(*storage)->head_a, &(*storage)->tail_a);

		}
	}
	else
	{
		while (len--)
			push('b', storage);
	}
	return (1);
}

int		stack_b_division(t_args **storage)
{
 	int		step_width;
 	int		min;
	int		count;
 	t_num	*tmp;

 	if (!(*storage)->head_b || (*storage)->stack_b_num < 4)
 		return (0);
 	step_width = (*storage)->stack_b_num / 2;
 	min = find_min_stack_b(*storage);
 	(*storage)->curr_rank += 1;
	count = (*storage)->stack_b_num;
	while (count--)
	{
		if (((*storage)->head_b) && (*storage)->head_b->index >= min && (*storage)->head_b->index < min + step_width)
		{
			(*storage)->head_b->rank = (*storage)->curr_rank;
			r_rotate(&(*storage)->head_b, &(*storage)->tail_b);
		}
		else
		{
			push('a', storage);
			print_stacks((*storage)->head_a, (*storage)->head_b);

		}
	/*	tmp = (*storage)->head_b;
		if (tmp->index >= min && tmp->index < min + step_width)
		{
			tmp->rank = (*storage)->curr_rank;
			r_rotate(&(*storage)->head_b, &(*storage)->tail_b);
		}
		else
			push('a', storage);*/
	}
	return (1);
 }


 int	small_sort(t_args **storage, int subrank)
 {
    t_num *curr;
    t_num *next = NULL;

	if ((*storage)->head_b && (*storage)->stack_b_num < 4)
	{
		(*storage)->curr_rank = (*storage)->head_b->rank;
		while ((*storage)->head_b)
		{
			curr = (*storage)->head_b;
			if (curr->next)
				next = curr->next;
			if (next && curr < next)
				s_swap(&(*storage)->head_b);
			push('a', storage);
			if ((*storage)->head_a->next->rank == (*storage)->curr_rank
			&& (*storage)->head_a->index > (*storage)->head_a->next->index)
				s_swap(&(*storage)->head_a);
		}
		while ((*storage)->head_a->rank == (*storage)->curr_rank)
			r_rotate(&(*storage)->head_a, &(*storage)->tail_a);

	}
    return (1);
 }

int    sort_head_a(t_args **storage)
{
	int len;
	t_num *curr, *next = NULL, *prev = NULL;

	(*storage)->curr_rank = ((*storage)->head_a->rank);
	len = find_len_of_rank((*storage)->head_a, (*storage)->curr_rank);
	if (len < 4)
	{
		while (len < 4)
		{
			while ((*storage)->head_a->rank == (*storage)->curr_rank)
			{
				curr = (*storage)->head_a;
				if (curr->next && curr->next->rank == (*storage)->curr_rank)
					next = curr->next;
				if (next && curr->index > next->index)
					s_swap(&(*storage)->head_a);
				r_rotate(&(*storage)->head_a, &(*storage)->tail_a);
				next = NULL;
			}
			(*storage)->curr_rank -= 1;
			len = find_len_of_rank((*storage)->head_a, (*storage)->curr_rank);
		}
	}
	if (len > 3 && len < 7)
	{
		sort_4_6(storage, len);
		(*storage)->curr_rank -= 1;
	}
	else
		stack_a_division(storage, 0);
	return (1);
}

int		sort_main(t_args **storage)
{
	stack_a_division(storage, 1);
	print_stacks((*storage)->head_a, (*storage)->head_b);
	while (!(is_stack_a_sorted(*storage)))
	{
		while ((*storage)->head_b)
		{
			if (!(stack_b_division(storage)))
			{
				print_stacks((*storage)->head_a, (*storage)->head_b);
				small_sort(storage, 0);
				print_stacks((*storage)->head_a, (*storage)->head_b);
			}
			print_stacks((*storage)->head_a, (*storage)->head_b);
		}
		sort_head_a(storage);
		print_stacks((*storage)->head_a, (*storage)->head_b);
	}
	return (1);
}
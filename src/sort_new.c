/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamarant <tamarant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 20:22:29 by tamarant          #+#    #+#             */
/*   Updated: 2020/02/20 18:21:39 by tamarant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int		set_depth(t_args **storage, int depth) {
	t_num *tmp;
	int step_width;
	int index_min;


	find_max_min(storage);
	if ((*storage)->is_sort == 3) {
		tmp = (*storage)->head_a;
		if ((*storage)->stack_a_num > 6) {
			step_width = (*storage)->stack_a_num / 3;
			while (tmp) {
				tmp->depth++;
				if (tmp->index >= (*storage)->min_index_stack_a &&
					tmp->index < (*storage)->min_index_stack_a + step_width)
					tmp->sub_rank = 1;
				else if (tmp->index >= (*storage)->min_index_stack_a + step_width &&
						 tmp->index < (*storage)->min_index_stack_a + step_width * 2)
					tmp->sub_rank = 2;
				else
					tmp->sub_rank = 3;
				tmp = tmp->next;
			}
		} else if ((*storage)->stack_a_num > 3 && ((*storage)->stack_a_num < 7)) {
			step_width = (*storage)->stack_a_num / 2;
			while (tmp) {
				if (tmp->index >= (*storage)->min_index_stack_a &&
					tmp->index < (*storage)->min_index_stack_a + step_width)
					tmp->sub_rank = 1;
				else if (tmp->index >= (*storage)->min_index_stack_a + step_width &&
						 tmp->index < (*storage)->min_index_stack_a + step_width * 2)
					tmp->sub_rank = 2;
			}
		}
		if ((*storage)->stack_a_num > 3 && ((*storage)->stack_a_num < 7))
			sort_by_depth(storage, 2);
		if ((*storage)->stack_a_num > 6)
			sort_by_depth(storage, 3);
		if ((*storage)->stack_a_num > 6)
			return (set_depth(storage, depth += 1));
		if ((*storage)->stack_a_num < 6) {
			sort_third(storage);
			return (1); //// можно начинать сортировать, базовый случай достигнут
		}
	}
}

void sort_by_depth(t_args **storage, int step_width)
{
	int 	count;

	count = (*storage)->stack_a_num;
	if (step_width == 3)
	{
		while (count--)
		{
			if ((*storage)->head_a->sub_rank == 3)
				r_rotate(&(*storage)->head_a, &(*storage)->tail_a);
			else if ((*storage)->head_a->sub_rank == 2)
			{
				push('b', storage);
				(*storage)->stack_a_num -= 1;
			}
			else if ((*storage)->head_a->sub_rank == 1)
			{
				push('b', storage);
				r_rotate(&(*storage)->head_b, &(*storage)->tail_b);
				(*storage)->stack_a_num -= 1;
			}
		}
	}
	else if (step_width == 2)
	{
		while (count--)
		{
			if ((*storage)->head_a->sub_rank == 2)
			{
				if ((*storage)->head_a->index < ((*storage)->head_b->index))
				{
					push('b', storage);
					s_swap(&(*storage)->head_b);
				}
				else
					push('b', storage);
			}
			else if ((*storage)->head_a->sub_rank == 1)
				rr_reverse(&(*storage)->head_a, &(*storage)->tail_a);
		}
	}

}

int		is_sorted_stack_a(t_args *storage)
{
	t_num *tmp;
	int curr;

	tmp = storage->head_a;
	while (tmp)
	{
		curr = tmp->index;
		tmp = tmp->next;
		if ((tmp) && curr > tmp->index)
			return (-1);
	}
	return (1);
}

int 	sort_third_down(t_args **storage, int depth, int sub_rank)
{
	t_num *curr;
	t_num *prev = NULL;

	while ((*storage)->tail_b->depth == depth && (*storage)->tail_b->sub_rank == sub_rank)
	{
		curr = (*storage)->tail_b;
		if ((curr->prev) && curr->prev->sub_rank == sub_rank && curr->prev->depth == depth)
			prev = curr->prev;
		if (curr->index > prev->index)
		{
			rr_reverse(&(*storage)->head_b, &(*storage)->tail_b);
			rr_reverse(&(*storage)->head_b, &(*storage)->tail_b);
			s_swap(&(*storage)->head_b);
		}
		else
			rr_reverse(&(*storage)->head_b, &(*storage)->tail_b);
		prev = NULL;
	}
	sort_third_up(storage, depth, sub_rank);
	print_stacks((*storage)->head_a, (*storage)->head_b);
}


int 	sort_third_up(t_args **storage, int depth, int sub_rank)
{
	t_num *curr;
	t_num *next;

	while ((*storage)->head_b->depth == depth && (*storage)->head_b->sub_rank == sub_rank)
	{
		curr = (*storage)->head_b;
		next = curr->next;
		if (next && curr->index < next->index)
			s_swap(&(*storage)->head_b);
		if ((*storage)->head_a->index > (*storage)->head_a->next->index)
			s_swap(&(*storage)->head_a);
		if ((*storage)->head_b->depth == depth && (*storage)->head_b->sub_rank == sub_rank)
			push('a', storage);
	}
	if (is_sorted_stack_a(*storage) == 1)
		return (1);
	return (-1);
}


int 	sort_third(t_args **storage)
{
	t_num	*curr;
	t_num	*next;

	find_max_min(storage);
	while (is_sorted_stack_a(*storage) == -1)
	{
		curr = (*storage)->head_a;
		next = curr->next;
		if (curr->index == (*storage)->max_index_stack_a)
			r_rotate(&(*storage)->head_a, &(*storage)->tail_a);
		else if ((next) && curr->index < next->index)
			s_swap(&(*storage)->head_a);
		else
			rr_reverse(&(*storage)->head_a, &(*storage)->tail_a);
	}
	print_stacks((*storage)->head_a, (*storage)->head_b);
	sort_third_up(storage, (*storage)->head_a->depth, (*storage)->head_a->sub_rank -= 1);
	print_stacks((*storage)->head_a, (*storage)->head_b);
	sort_third_down(storage, (*storage)->head_a->depth, (*storage)->head_a->sub_rank -= 1);
	return (1);
}

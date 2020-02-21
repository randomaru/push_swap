/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamarant <tamarant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 20:22:29 by tamarant          #+#    #+#             */
/*   Updated: 2020/02/21 17:40:58 by tamarant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int		set_depth(t_args **storage, int depth) {
	t_num *tmp;
	int step_width;
	int index_min;


	find_max_min(storage);
	if ((*storage)->is_sort == 3)
	{
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
		if ((*storage)->stack_a_num < 6)
		{
//			sort_third(storage);
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
		if ((*storage)->curr_subrank == -1)
			(*storage)->curr_subrank = 3;
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
			if ((*storage)->curr_subrank == -1)
				(*storage)->curr_subrank = 2;
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

int 	sort_third_down(t_args **storage, int depth, int sub_rank)
{
	t_num *curr;
	t_num *prev = NULL;

	while ((*storage)->tail_b->depth == depth && (*storage)->tail_b->sub_rank == sub_rank)
	{
		curr = (*storage)->tail_b;
		if ((curr->prev) && curr->prev->sub_rank == sub_rank && curr->prev->depth == depth)
			prev = curr->prev;
		if (prev && curr->index > prev->index)
		{
			rr_reverse(&(*storage)->head_b, &(*storage)->tail_b);
			rr_reverse(&(*storage)->head_b, &(*storage)->tail_b);
			s_swap(&(*storage)->head_b);
		}
		else
			rr_reverse(&(*storage)->head_b, &(*storage)->tail_b);
		prev = NULL;
	}
	sort_up_b(storage);
	print_stacks((*storage)->head_a, (*storage)->head_b);
}


int		sort_up_b(t_args **storage)
{
	t_num *curr;
	t_num *next;

	next = NULL;
	curr = (*storage)->head_b;
	if (curr->next)
		next = curr->next;
	while (curr->depth == (*storage)->curr_depth && curr->sub_rank == (*storage)->curr_subrank)
	{
		curr = (*storage)->head_b;
		if (curr->next)
			next = curr->next;
		if (next && curr->index < next->index)
			s_swap(&curr);
		if ((*storage)->head_a->index > (*storage)->head_a->next->index)
			s_swap(&(*storage)->head_a);
		if (curr->depth == (*storage)->curr_depth && curr->sub_rank == (*storage)->curr_subrank)
			push('a', storage);
	}
//	if (is_sorted_stack_a(*storage) == 1)
//		return (1);
	if (is_sorted_first_three(*storage) == 1)
		return (1);
	return (-1);
}

int		sort_up_a(t_args **storage)
{
	t_num *curr;
	t_num *next;

	next = NULL;
	curr = (*storage)->head_a;
	if (curr->next)
		next = curr->next;
	while (curr->depth == (*storage)->curr_depth && curr->sub_rank == (*storage)->curr_subrank)
	{
		if (next && curr->index > next->index)
			s_swap(&curr);
		else
		{
			rr_reverse(&curr, &(*storage)->tail_a);
			s_swap(&curr);
			r_rotate(&curr, &(*storage)->tail_a);
		}
	}
	if (is_sorted_first_three(*storage) == 1)
		return (1);
	return (-1);
}

int		is_depth(t_args **storage, int depth)
{
	t_num *tmp;

	tmp = (*storage)->head_b;
	while (tmp)
	{
		if (tmp->depth == depth)
			return (1);
		tmp = tmp->next;
	}
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
	(*storage)->curr_subrank -= 1;
	print_stacks((*storage)->head_a, (*storage)->head_b);
	sort_up_b(storage);
	(*storage)->curr_subrank -= 1;

	print_stacks((*storage)->head_a, (*storage)->head_b);
	sort_third_down(storage, (*storage)->head_a->depth, (*storage)->head_a->sub_rank -= 1);
	print_stacks((*storage)->head_a, (*storage)->head_b);

	return (1);
}

/*int 	sort_up(t_args **storage, char stack)
{
	t_num *curr;
	t_num *next;
	t_num *other;

	curr = NULL;
	next = NULL;
	other = NULL;
	if (stack == 'b')
	{
		curr = (*storage)->head_b;
		if (curr->next)
			next = curr->next;
		other = (*storage)->head_a;
	}
	else
	{
		curr = (*storage)->head_a;
		if (curr->next)
			next = curr->next;
		other = (*storage)->head_b;
	}
	while (curr->depth == (*storage)->curr_depth && curr->sub_rank == (*storage)->curr_subrank)
	{
		if (next && curr->index < next->index)
			s_swap(&curr);
		if ((*storage)->head_a->index > (*storage)->head_a->next->index)
			s_swap(&(*storage)->head_a);
		if (curr->depth == (*storage)->curr_depth && curr->sub_rank == (*storage)->curr_subrank)
			push('a', storage);
	}
	if (is_sorted_stack_a(*storage) == 1)
		return (1);
	return (-1);
}*/


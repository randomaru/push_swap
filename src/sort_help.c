/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_help.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamarant <tamarant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 13:22:10 by tamarant          #+#    #+#             */
/*   Updated: 2020/03/06 17:18:15 by tamarant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int 	is_stack_a_sorted(t_args *storage)
{
	t_num	*head;

	if (storage->head_b)
		return (0);
	if (!(head = storage->head_a))
		return (0);
	while (head)
	{
		if (head->next && head->index > head->next->index)
			return (0);
		head = head->next;
	}
	return (1);
}

int 	is_tail_sorted(t_args *storage, int len, int rank)
{
	t_num *tail;

 	if (!(tail = storage->tail_a))
		return (-1);
	while (len--)
	{
		if (tail->rank == rank && tail->prev->rank == rank)
			if (tail->index < tail->prev->index)
				return (0);
		tail = tail->prev;
	}
	return (1);
}

int		find_len_of_rank(t_num *head, int rank)
{
	int len;

	len = 0;
	while (head && head->rank == rank)
	{
		len++;
		head = head->next;
	}
	return (len);
}

int		find_min_stack_b(t_args *storage)
{
	t_num *tmp;
	int min;

	if (!storage->head_b)
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

int		find_min_stack_a(t_args *storage, int rank)
{
	t_num   *head;
	int     min;

	if (!(head = storage->head_a))
		return (0); ////// нормально обработай ошибки в воспомогательных функциях
	min = head->index;
	while (head && head->rank == rank)
	{
		if (head->index < min)
			min = head->index;
		head = head->next;
	}
	return (min);
}



int		sort_4_6(t_args **storage, int len)
{
	int		step_width;
	int		min;
	t_num	*curr;
	t_num 	*next;

	step_width = len / 2;
	min = find_min_stack_a(*storage, (*storage)->curr_rank);
	while (len--)
	{
		curr = (*storage)->head_a;
		if (curr->index >= min && curr->index < min + step_width)
			r_rotate(&(*storage)->head_a, &(*storage)->tail_a);
		else
			push('b', storage);
	}
	print_stacks((*storage)->head_a, (*storage)->head_b); ////
	if (!(is_tail_sorted(*storage, step_width, (*storage)->curr_rank))) /// rank == 1??
	{
		if (step_width == 2)
		{
			rr_reverse(&(*storage)->head_a, &(*storage)->tail_a);
			rr_reverse(&(*storage)->head_a, &(*storage)->tail_a);
			s_swap(&(*storage)->head_a);
			r_rotate(&(*storage)->head_a, &(*storage)->tail_a);
			r_rotate(&(*storage)->head_a, &(*storage)->tail_a);
		}
		if (step_width == 3)
		{
			rr_reverse(&(*storage)->head_a, &(*storage)->tail_a);
			while ((*storage)->tail_a->rank == (*storage)->curr_rank) //// перепиши это нормально
			{
				rr_reverse(&(*storage)->head_a, &(*storage)->tail_a);
				if ((*storage)->head_a->index > (*storage)->head_a->next->index)
				{
					s_swap(&(*storage)->head_a);
					print_stacks((*storage)->head_a, (*storage)->head_b); ////
				}
			}
			print_stacks((*storage)->head_a, (*storage)->head_b); ////
			while (step_width--) ////////////////AAAAAAAAAAAAAAAAAAAA
			{
				r_rotate(&(*storage)->head_a, &(*storage)->tail_a);
				if ((*storage)->head_a->next && (*storage)->head_a->next->rank == (*storage)->curr_rank
				&& (*storage)->head_a->index > (*storage)->head_a->next->index)
					s_swap(&(*storage)->head_a);
			}
		}
	}
	if ((*storage)->head_b)
		push('a', storage);
	while ((*storage)->head_b)
	{
		push('a', storage);
		if ((*storage)->head_a->index > (*storage)->head_a->next->index)
			s_swap(&(*storage)->head_a);
	}
	print_stacks((*storage)->head_a, (*storage)->head_b); //////
	while ((*storage)->head_a->rank == (*storage)->curr_rank)
	{
		next = NULL;
		curr = (*storage)->head_a;
		if (curr->next && curr->next->rank == (*storage)->curr_rank)
			next = curr->next;
		if (next && curr->index > next->index)
			s_swap(&(*storage)->head_a);
		r_rotate(&(*storage)->head_a, &(*storage)->tail_a);
	}
}
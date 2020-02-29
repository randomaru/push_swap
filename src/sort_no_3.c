/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_no_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamarant <tamarant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 19:41:52 by tamarant          #+#    #+#             */
/*   Updated: 2020/02/29 14:17:11 by tamarant         ###   ########.fr       */
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
	int count = (*storage)->stack_b_num;
	while (tmp && count--)
	{

		if (tmp->index >= min && tmp->index < min + step_width)
		{
            tmp = tmp->next;
			r_rotate(&(*storage)->head_b, &(*storage)->tail_b);
		}
		else
		{
			tmp->rank = (*storage)->curr_rank;
			push('a', storage);
            (*storage)->stack_b_num -= 1;
			tmp = (*storage)->head_b;
		}
	}
	return (1);
 }


 int    stack_b_op(t_args **storage)
 {
    int i = 0;
    t_num *curr;
    t_num *next = NULL;

    while (stack_b_division(storage) == 1)
    {
        print_stacks((*storage)->head_a, (*storage)->head_b);

    }
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
            if ((*storage)->head_a->next->rank == (*storage)->curr_rank && (*storage)->head_a->index > (*storage)->head_a->next->index)
                s_swap(&(*storage)->head_a);
        }
        print_stacks((*storage)->head_a, (*storage)->head_b);
        while ((*storage)->head_a->rank == (*storage)->curr_rank)
            r_rotate(&(*storage)->head_a, &(*storage)->tail_a);
    }
     print_stacks((*storage)->head_a, (*storage)->head_b);
        if (!(*storage)->head_b)
            sort_head_a(storage);
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
				if (curr->next->rank == (*storage)->curr_rank)
					next = curr->next;
				if (next && curr->index > next->index)
					s_swap(&(*storage)->head_a);
				if ((*storage)->tail_a->rank == (*storage)->curr_rank)
					prev = (*storage)->tail_a;
				if (prev && prev->index > curr->index)
				{
					rr_reverse(&(*storage)->head_a, &(*storage)->tail_a);
					s_swap(&(*storage)->head_a);
				}
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
	}
	else
	{
		(*storage)->curr_rank -= 1;
		/////push b curr_rank
		stack_b_op(storage);
	}
	 print_stacks((*storage)->head_a, (*storage)->head_b);
}


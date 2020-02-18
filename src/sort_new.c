/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamarant <tamarant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 20:22:29 by tamarant          #+#    #+#             */
/*   Updated: 2020/02/18 21:11:48 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int set_depth(t_args **storage, int depth)
{
	t_num *tmp;
	int step_width;
	int index_min;


	find_max_min(storage);
	if ((*storage)->is_sort == 3)
	{
		tmp = (*storage)->head_a;
		if ((*storage)->stack_a_num > 6)
		{
			step_width = (*storage)->stack_a_num / 3;
			while (tmp)
			{
				if (tmp->index >= (*storage)->min_index_stack_a && tmp->index < (*storage)->min_index_stack_a+ step_width)
					tmp->sub_rank = 1;
				else if (tmp->index >= (*storage)->min_index_stack_a+ step_width && tmp->index < (*storage)->min_index_stack_a + step_width * 2)
					tmp->sub_rank = 2;
				else
					tmp->sub_rank = 3;
				tmp = tmp->next;
			}
		}
		else if ((*storage)->stack_a_num > 3 && ((*storage)->stack_a_num < 7))
		{
			step_width = (*storage)->stack_a_num / 2;
			while (tmp)
			{
				if (tmp->index >= (*storage)->min_index_stack_a && tmp->index < (*storage)->min_index_stack_a+ step_width)
					tmp->sub_rank = 1;
				else if (tmp->index >= (*storage)->min_index_stack_a+ step_width && tmp->index < (*storage)->min_index_stack_a + step_width * 2)
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
			return (1); //// можно начинать сортировать, базовый случай достигнут
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



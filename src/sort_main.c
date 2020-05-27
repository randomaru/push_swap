/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 19:07:42 by mac               #+#    #+#             */
/*   Updated: 2020/05/27 19:34:19 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void		stack_b_div_help(int mid, t_args **storage)
{
	push('a', storage, &(*storage)->counter);
	if ((*storage)->head_b && (*storage)->head_b->index < mid)
		rr_rotate(storage, 0);
	else
		r_rotate('a', &(*storage)->head_a,
				&(*storage)->tail_a, &(*storage)->counter);
	(*storage)->tail_a->sort = 1;
	(*storage)->next += 1;
}

int				stack_b_division(int mid, int max, t_args **storage)
{
	int		len;

	max = find_stack_max('b', *storage);
	mid = (max - (*storage)->next) / 2 + (*storage)->next;
	(*storage)->flag += 1;
	len = (*storage)->stack_b_num;
	if ((*storage)->stack_b_num <= 4)
		small_sort_b(storage);
	else
	{
		while (len--)
		{
			(*storage)->head_b->flag = (*storage)->flag;
			if ((*storage)->head_b->index == (*storage)->next)
				stack_b_div_help(mid, storage);
			else if ((*storage)->head_b->index < mid)
				r_rotate('b', &(*storage)->head_b,
						&(*storage)->tail_b, &(*storage)->counter);
			else
				push('a', storage, &(*storage)->counter);
		}
	}
	return (1);
}

void			sort_second_part(t_args **storage)
{
	int		max;
	int		mid;
	int		len;
	t_num	*tmp;

	if ((len = find_len_of_part(0, storage)) <= 3)
		small_sort_a(len, storage);
	max = find_small_part_max(0, *storage);
	mid = (max - (*storage)->next) / 2 + (*storage)->next;
	tmp = (*storage)->head_a;
	while (tmp->flag == 0)
	{
		if (tmp->index <= mid)
			push('b', storage, &(*storage)->counter);
		else
			r_rotate('a', &(*storage)->head_a,
					&(*storage)->tail_a, &(*storage)->counter);
		tmp = (*storage)->head_a;
	}
	while ((*storage)->tail_a->sort != 1
			&& (*storage)->head_b->index != (*storage)->next)
		rrr_reverse(storage, 0);
	while ((*storage)->tail_a->sort != 1)
		rr_reverse('a', &(*storage)->head_a,
				&(*storage)->tail_a, &(*storage)->counter);
}

void			sort_first_part(t_args **storage)
{
	(*storage)->tmp_flag = (*storage)->head_a->flag;
	while ((*storage)->head_a->flag == (*storage)->tmp_flag)
	{
		if ((*storage)->head_a->index == (*storage)->next)
		{
			r_rotate('a', &(*storage)->head_a,
					&(*storage)->tail_a, &(*storage)->counter);
			(*storage)->tail_a->sort = 1;
			(*storage)->next += 1;
		}
		else
			push('b', storage, &(*storage)->counter);
	}
}

int				sort_main(t_args **storage)
{
	int mid;
	int max;

	if ((*storage)->stack_a_num <= 5)
		small_sort_a((*storage)->stack_a_num, storage);
	else
	{
		max = find_stack_max('a', *storage);
		mid = max / 2 + (*storage)->next;
		first_division(mid, storage);
		max = mid;
		while (!is_all_sorted(*storage))
		{
			while ((*storage)->head_b)
				stack_b_division(mid, max, storage);
			if (!(*storage)->head_b && (*storage)->head_a->sort == 0
					&& (*storage)->head_a->flag != 0)
				sort_first_part(storage);
			else if (!(*storage)->head_b &&
			(*storage)->head_a->sort == 0 && (*storage)->head_a->flag == 0)
				sort_second_part(storage);
		}
	}
	return (1);
}

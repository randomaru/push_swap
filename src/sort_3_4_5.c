/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 19:10:13 by mac               #+#    #+#             */
/*   Updated: 2020/05/27 20:10:31 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void		sort_5_help(t_args *const *storage, int max, int min)
{
	int part;

	part = find_max_part(max, 5, *storage);
	if (part == 3)
	{
		part = find_max_part(min, 5, *storage);
		max = min;
	}
	if (part == 1)
	{
		while ((*storage)->head_a->index != max)
			r_rotate('a', &(*storage)->head_a,
					&(*storage)->tail_a, &(*storage)->counter);
	}
	else
	{
		while ((*storage)->head_a->index != max)
			rr_reverse('a', &(*storage)->head_a,
					&(*storage)->tail_a, &(*storage)->counter);
	}
}

void			sort_5(t_args **storage)
{
	int max;
	int min;

	max = find_small_part_max((*storage)->head_a->flag, *storage);
	min = max - 4;
	if ((*storage)->tail_a->index == max)
		rr_reverse('a', &(*storage)->head_a,
				&(*storage)->tail_a, &(*storage)->counter);
	else
		sort_5_help(storage, max, min);
	push('b', storage, &(*storage)->counter);
	sort_4(storage);
	push('a', &(*storage), &(*storage)->counter);
	if ((*storage)->head_a->index < (*storage)->head_a->next->index)
	{
		(*storage)->head_a->sort = 1;
		(*storage)->next += 1;
	}
	else
	{
		r_rotate('a', &(*storage)->head_a,
				&(*storage)->tail_a, &(*storage)->counter);
		(*storage)->tail_a->sort = 1;
		(*storage)->next += 1;
	}
}

static void		sort_4_help(t_args **storage, int max)
{
	int part;

	part = find_max_part(max, 0, *storage);
	if (part == 1)
	{
		while ((*storage)->head_a->index != max)
			r_rotate('a', &(*storage)->head_a,
					&(*storage)->tail_a, &(*storage)->counter);
	}
	else
	{
		while ((*storage)->head_a->index != max)
			rr_reverse('a', &(*storage)->head_a,
					&(*storage)->tail_a, &(*storage)->counter);
	}
	push('b', storage, &(*storage)->counter);
	sort_3(storage);
	push('a', &(*storage), &(*storage)->counter);
	r_rotate('a', &(*storage)->head_a,
			&(*storage)->tail_a, &(*storage)->counter);
	(*storage)->tail_a->sort = 1;
	(*storage)->next += 1;
}

void			sort_4(t_args **storage)
{
	int max;
	int flag;

	max = find_small_part_max((*storage)->head_a->flag, *storage);
	if ((*storage)->stack_a_num == 4)
		sort_4_help(storage, max);
	else
	{
		flag = (*storage)->head_a->flag;
		while ((*storage)->head_a->flag == flag)
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
		if ((*storage)->head_b)
			small_sort_b(storage);
	}
}

void			sort_3(t_args **storage)
{
	int min;
	int mid;
	int max;
	int len;

	max = find_small_part_max((*storage)->head_a->flag, *storage);
	mid = max - 1;
	min = mid - 1;
	len = 3;
	if ((*storage)->stack_a_num == 3)
		sort_3_help_1(storage, min, mid, max);
	else
	{
		while (len != 0)
			len = sort_3_help_2(storage, mid, max, len);
	}
}

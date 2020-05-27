/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 19:24:05 by mac               #+#    #+#             */
/*   Updated: 2020/05/27 20:12:21 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	small_sort_a(int len, t_args **storage)
{
	if (len == 2)
	{
		if ((*storage)->stack_a_num != 2)
		{
			if ((*storage)->head_a->index > (*storage)->head_a->next->index)
				s_swap('a', &(*storage)->head_a, &(*storage)->counter);
			r_rotate('a', &(*storage)->head_a,
					&(*storage)->tail_a, &(*storage)->counter);
			(*storage)->tail_a->sort = 1;
			(*storage)->next += 1;
			r_rotate('a', &(*storage)->head_a,
					&(*storage)->tail_a, &(*storage)->counter);
			(*storage)->tail_a->sort = 1;
			(*storage)->next += 1;
		}
		else if ((*storage)->head_a->index > (*storage)->head_a->next->index)
			s_swap('a', &(*storage)->head_a, &(*storage)->counter);
	}
	else if (len == 3)
		sort_3(storage);
	else if (len == 4)
		sort_4(storage);
	else if (len == 5)
		sort_5(storage);
}

void	small_sort_b_help(t_args **storage)
{
	if ((*storage)->head_b && (*storage)->head_b->next
	&& (*storage)->head_b->index < (*storage)->head_b->next->index)
		s_swap('b', &(*storage)->head_b, &(*storage)->counter);
	(*storage)->head_b->flag = (*storage)->flag;
	push('a', storage, &(*storage)->counter);
	if ((*storage)->head_a->index > (*storage)->head_a->next->index)
		s_swap('a', &(*storage)->head_a, &(*storage)->counter);
}

int		small_sort_b(t_args **storage)
{
	if ((*storage)->head_b && (*storage)->stack_b_num <= 4)
	{
		while ((*storage)->head_b
		&& (*storage)->head_b->index == (*storage)->next)
		{
			push('a', storage, &(*storage)->counter);
			r_rotate('a', &(*storage)->head_a,
					&(*storage)->tail_a, &(*storage)->counter);
			(*storage)->tail_a->sort = 1;
			(*storage)->next += 1;
		}
		while ((*storage)->head_b)
			small_sort_b_help(storage);
		while ((*storage)->head_a->index == (*storage)->next)
		{
			r_rotate('a', &(*storage)->head_a,
					&(*storage)->tail_a, &(*storage)->counter);
			(*storage)->tail_a->sort = 1;
			(*storage)->next += 1;
		}
	}
	return (1);
}

void	sort_3_help_1(t_args *const *storage, int min, int mid, int max)
{
	if ((*storage)->head_a->index == max)
	{
		r_rotate('a', &(*storage)->head_a,
				&(*storage)->tail_a, &(*storage)->counter);
		if ((*storage)->head_a->index > (*storage)->head_a->next->index)
			s_swap('a', &(*storage)->head_a, &(*storage)->counter);
	}
	else if ((*storage)->tail_a->index == min)
	{
		if ((*storage)->head_a->index > (*storage)->head_a->next->index)
			s_swap('a', &(*storage)->head_a, &(*storage)->counter);
		rr_reverse('a', &(*storage)->head_a,
				&(*storage)->tail_a, &(*storage)->counter);
	}
	else if ((*storage)->head_a->index > (*storage)->head_a->next->index)
		s_swap('a', &(*storage)->head_a, &(*storage)->counter);
	else if ((*storage)->head_a->index == min
			&& (*storage)->tail_a->index == mid)
	{
		rr_reverse('a', &(*storage)->head_a,
				&(*storage)->tail_a, &(*storage)->counter);
		s_swap('a', &(*storage)->head_a, &(*storage)->counter);
	}
}

int		sort_3_help_2(t_args **storage, int mid, int max, int len)
{
	if ((*storage)->head_a->index == (*storage)->next)
	{
		r_rotate('a', &(*storage)->head_a,
				&(*storage)->tail_a, &(*storage)->counter);
		(*storage)->tail_a->sort = 1;
		(*storage)->next += 1;
		len--;
	}
	else if (((*storage)->head_a->index == max
			|| (*storage)->head_a->index == mid)
			&& (*storage)->head_a->next->index == (*storage)->next)
		s_swap('a', &(*storage)->head_a, &(*storage)->counter);
	else if (len == 3 && (*storage)->head_a->index != (*storage)->next)
		push('b', storage, &(*storage)->counter);
	else if ((*storage)->head_b->index == (*storage)->next)
		push('a', storage, &(*storage)->counter);
	return (len);
}

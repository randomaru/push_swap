/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_main_help.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 19:09:25 by mac               #+#    #+#             */
/*   Updated: 2020/05/27 19:40:55 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int		find_len_of_part(int flag, t_args **storage)
{
	t_num	*tmp;
	int		len;

	tmp = (*storage)->head_a;
	len = 0;
	while (tmp && tmp->sort == 0 && tmp->flag == flag)
	{
		len++;
		tmp = tmp->next;
	}
	return (len);
}

int		is_all_sorted(t_args *storage)
{
	t_num *head_a;

	head_a = storage->head_a;
	if (storage->head_b != NULL || storage->head_a == NULL)
		return (0);
	if (storage->head_b == NULL)
	{
		while (head_a)
		{
			if (head_a->next && head_a->index > head_a->next->index)
				return (0);
			head_a = head_a->next;
		}
		return (1);
	}
	return (0);
}

int		find_stack_max(char c, t_args *storage)
{
	t_num	*tmp;
	int		max;

	if ((c == 'a' && !storage->head_a) || (c == 'b' && !storage->head_b))
		return (0);
	if (c == 'a')
		tmp = storage->head_a;
	else
		tmp = storage->head_b;
	max = tmp->index;
	while (tmp)
	{
		if (tmp->index > max)
			max = tmp->index;
		tmp = tmp->next;
	}
	return (max);
}

int		find_small_part_max(int flag, t_args *storage)
{
	t_num	*tmp;
	int		max;

	if (!storage->head_a)
		return (0);
	tmp = storage->head_a;
	max = tmp->index;
	while (tmp && tmp->flag == flag)
	{
		if (tmp->index > max)
			max = tmp->index;
		tmp = tmp->next;
	}
	return (max);
}

int		find_max_part(int max_min, int len, t_args *storage)
{
	int		part;
	t_num	*tmp;

	part = 1;
	tmp = storage->head_a;
	while (tmp->index != max_min)
	{
		part++;
		tmp = tmp->next;
	}
	if (part == 1 || part == 2)
		return (1);
	else if (part == 3 && len == 5)
		return (3);
	else
		return (2);
}

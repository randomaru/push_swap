//
// Created by mac on 4/9/20.
//

#include "../inc/push_swap.h"

int		is_sorted(t_args *storage)
{
	t_num *head_a;

	head_a = storage->head_a;
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

int		find_stack_min(t_args *storage)
{
	t_num *tmp;
	int min;

	if (!storage->head_a)
		return (0);
	tmp = storage->head_a;
	min = tmp->index;
	while (tmp)
	{
		if (tmp->index < min)
			min = tmp->index;
		tmp = tmp->next;
	}
	return (min);
}

int 	find_stack_max(char c, t_args *storage)
{
	t_num	*tmp;
	int		max;

	if ((c == 'a' && !storage->head_a) || (c == 'b' && !storage->head_b))
		return (0);
	if (c =='a')
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

int 	find_not_sorted_part_max(t_args *storage)
{
	t_num	*tmp;
	int		max;

	if (!storage->head_a)
		return (0);
	tmp = storage->head_a;
	max = tmp->index;
	while (tmp && tmp->flag == 0)
	{
		if (tmp->index > max)
			max = tmp->index;
		tmp = tmp->next;
	}
	return (max);
}
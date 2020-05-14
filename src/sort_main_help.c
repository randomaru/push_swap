//
// Created by mac on 4/9/20.
//

#include "../inc/push_swap.h"

int 	find_len_of_part(int flag, t_args **storage)
{
	t_num	*tmp;
	int 	len;

	tmp = (*storage)->head_a;
	len = 0;
	while (tmp && tmp->sort == 0 && tmp->flag == flag )
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

int		is_part_sorted(int flag, t_args *storage)
{
	t_num	*tmp;

	tmp = storage->head_a;
	while(tmp->flag == flag)
	{
		if (tmp->next && tmp->next->flag == flag
		&& tmp->index > tmp->next->index)
			return (0);
		tmp = tmp->next;
	}
	return (1);
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

int 	find_small_part_max(int flag, t_args *storage)
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

int		sort_2(t_args **storage)
{
	if ((*storage)->head_a->index > (*storage)->head_a->next->index)
		if (s_swap(&(*storage)->head_a, &(*storage)->counter) == -1)
			return (0);
	if ((*storage)->stack_a_num > 2)
	{
		r_rotate(&(*storage)->head_a, &(*storage)->tail_a, &(*storage)->counter);
		r_rotate(&(*storage)->head_a, &(*storage)->tail_a, &(*storage)->counter);
	}
	return (1);
}

int 	sort_3(t_args **storage) {
	int min;
	int mid;
	int max;

//	max = find_small_part_max((*storage)->flag, *storage);
	max = find_small_part_max((*storage)->head_a->flag, *storage);
	mid = max - 1;
	min = mid - 1;
	if ((*storage)->stack_a_num == 3) {
		if ((*storage)->head_a->index == max) {
			r_rotate(&(*storage)->head_a, &(*storage)->tail_a, &(*storage)->counter);
			if ((*storage)->head_a->index > (*storage)->head_a->next->index)
				s_swap(&(*storage)->head_a, &(*storage)->counter);
		} else if ((*storage)->tail_a->index == min) {
			if ((*storage)->head_a->index > (*storage)->head_a->next->index)
				s_swap(&(*storage)->head_a, &(*storage)->counter);
			rr_reverse(&(*storage)->head_a, &(*storage)->tail_a, &(*storage)->counter);
		} else if ((*storage)->head_a->index > (*storage)->head_a->next->index)
			s_swap(&(*storage)->head_a, &(*storage)->counter);
		return (1);
	}
	else
	{
		int len = 3;
		while (len != 0)
		{
			if ((*storage)->head_a->index == (*storage)->next)
			{
				r_rotate(&(*storage)->head_a, &(*storage)->tail_a, &(*storage)->counter);
				(*storage)->tail_a->sort = 1;
				(*storage)->next += 1;
				len--;
			}
			else if (((*storage)->head_a->index == max || (*storage)->head_a->index == mid)
				&& (*storage)->head_a->next->index == (*storage)->next)
				s_swap(&(*storage)->head_a, &(*storage)->counter);
			else if (len == 3 && (*storage)->head_a->index != (*storage)->next)
				push('b', storage, &(*storage)->counter);
			else if ((*storage)->head_b->index == (*storage)->next)
				push('a', storage, &(*storage)->counter);
		}
	return (1);
	}
}
int		sort_4(t_args **storage)
{
	int max;
	int flag;

//	max = find_small_part_max((*storage)->flag, *storage);
	max = find_small_part_max((*storage)->head_a->flag, *storage);
	if ((*storage)->stack_a_num == 4)
	{
		if ((*storage)->tail_a->index == max)
			rr_reverse(&(*storage)->head_a, &(*storage)->tail_a, &(*storage)->counter);
		else
		{
			while ((*storage)->head_a->index != max)
				r_rotate(&(*storage)->head_a, &(*storage)->tail_a, &(*storage)->counter);
		}
		push('b', storage, &(*storage)->counter);
		sort_3(storage);
		push('a', &(*storage), &(*storage)->counter);
		r_rotate(&(*storage)->head_a, &(*storage)->tail_a, &(*storage)->counter);
		(*storage)->tail_a->sort = 1;
		(*storage)->next += 1;
	}
	else
	{
		flag = (*storage)->head_a->flag;
		while ((*storage)->head_a->flag == flag)
		{
			if ((*storage)->head_a->index == (*storage)->next)
			{
				r_rotate(&(*storage)->head_a, &(*storage)->tail_a, &(*storage)->counter);
				(*storage)->tail_a->sort = 1;
				(*storage)->next += 1;
			}
			else
				push('b', storage, &(*storage)->counter);
		}
		if ((*storage)->head_b)
			small_sort_b(storage);
	}
	return (1);
}

int 	sort_3_b(t_args **storage)
{

}
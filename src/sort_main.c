//
// Created by mac on 4/9/20.
//

#include "../inc/push_swap.h"

int		stack_b_division(int mid, int max, t_args **storage)
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
			{
				push('a', storage, &(*storage)->counter);
				if ((*storage)->head_b && (*storage)->head_b->index < mid)
					rr_rotate(storage);
				else
					r_rotate(&(*storage)->head_a, &(*storage)->tail_a, &(*storage)->counter);
				(*storage)->tail_a->sort = 1;
				(*storage)->next += 1;
			}
			else if ((*storage)->head_b->index < mid)
				r_rotate(&(*storage)->head_b, &(*storage)->tail_b, &(*storage)->counter);
			else
				push('a', storage, &(*storage)->counter);
		}
	}
}

int		small_sort_b(t_args **storage)
{
	if ((*storage)->head_b && (*storage)->stack_b_num <= 4)
	{
		while ((*storage)->head_b && (*storage)->head_b->index == (*storage)->next)
		{
			push('a', storage, &(*storage)->counter);
			r_rotate(&(*storage)->head_a, &(*storage)->tail_a, &(*storage)->counter);
			(*storage)->tail_a->sort = 1;
			(*storage)->next += 1;
		}
		while ((*storage)->head_b)
		{
			if ((*storage)->head_b && (*storage)->head_b->next
				&& (*storage)->head_b->index < (*storage)->head_b->next->index)
				s_swap(&(*storage)->head_b, &(*storage)->counter);
			(*storage)->head_b->flag = (*storage)->flag;
			push('a', storage, &(*storage)->counter);
			if ((*storage)->head_a->index > (*storage)->head_a->next->index)
				s_swap(&(*storage)->head_a, &(*storage)->counter);
		}
		while ((*storage)->head_a->index == (*storage)->next)
		{
			r_rotate(&(*storage)->head_a, &(*storage)->tail_a, &(*storage)->counter);
			(*storage)->tail_a->sort = 1;
			(*storage)->next += 1;
		}
	}
		return (1);
}

static int		first_division(int mid, t_args **storage)
{
	t_num	*tmp;
	int		len;

	len = (*storage)->stack_a_num;
	while (len--)
	{
		tmp = (*storage)->head_a;
		if (tmp->index <= mid)
			push('b', storage, &(*storage)->counter);
		else
			r_rotate(&(*storage)->head_a, &(*storage)->tail_a, &(*storage)->counter);
	}
}

void	small_sort_a(int len, t_args **storage)
{
	if (len == 2)
	{
		if ((*storage)->head_a->index > (*storage)->head_a->next->index)
			s_swap(&(*storage)->head_a, &(*storage)->counter);
		r_rotate(&(*storage)->head_a, &(*storage)->tail_a, &(*storage)->counter);
		(*storage)->tail_a->sort = 1;
		(*storage)->next += 1;
		r_rotate(&(*storage)->head_a, &(*storage)->tail_a, &(*storage)->counter);
		(*storage)->tail_a->sort = 1;
		(*storage)->next += 1;
	}
	else if (len == 3)
		sort_3(storage);
	else if (len == 4)
		sort_4(storage);
}

void	sort_second_part(t_args **storage)
{
	int max;
	int mid;
	t_num *tmp;

	max = find_not_sorted_part_max(*storage);
	mid = (max - (*storage)->next) / 2 + (*storage)->next;
	tmp = (*storage)->head_a;
	while (tmp->flag == 0)
	{
		if (tmp->index <= mid)
			push('b', storage, &(*storage)->counter);
		else
			r_rotate(&(*storage)->head_a, &(*storage)->tail_a, &(*storage)->counter);
		tmp = (*storage)->head_a;
	}
	print_stacks((*storage)->head_a, (*storage)->head_b);
	while ((*storage)->tail_a->sort != 1 && (*storage)->head_b->index != (*storage)->next)
		rrr_reverse(storage);
	while ((*storage)->tail_a->sort != 1)
		rr_reverse(&(*storage)->head_a, &(*storage)->tail_a, &(*storage)->counter);
}

int		sort_main(t_args **storage)
{
	int mid;
	int max;
	int len;

	max = find_stack_max('a', *storage);
	mid = max / 2 + (*storage)->next;
	first_division(mid, storage);
	print_stacks((*storage)->head_a, (*storage)->head_b);
	max = mid;
	while (!is_all_sorted(*storage))
	{
		while ((*storage)->head_b)
		{
			stack_b_division(mid, max, storage);
			print_stacks((*storage)->head_a, (*storage)->head_b);
		}
		////дописать случаи сортировки 1-6;
		len = find_len_of_part((*storage)->head_a->flag, storage);
	/*	if (len <= 4)
		{
			small_sort_a(len, storage);
			print_stacks((*storage)->head_a, (*storage)->head_b);
		}
		else */  ////фиксим
		if (!(*storage)->head_b && (*storage)->head_a->sort == 0 && (*storage)->head_a->flag != 0)
		{
			(*storage)->tmp_flag = (*storage)->head_a->flag;
			while ((*storage)->head_a->flag == (*storage)->tmp_flag)
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
			print_stacks((*storage)->head_a, (*storage)->head_b);

		}
		else if (!(*storage)->head_b &&
		(*storage)->head_a->sort == 0 && (*storage)->head_a->flag == 0)
			sort_second_part(storage);
	print_stacks((*storage)->head_a, (*storage)->head_b);
	}
}
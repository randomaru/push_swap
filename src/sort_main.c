//
// Created by mac on 4/9/20.
//

#include "../inc/push_swap.h"

int		stack_b_division(int mid, int max, t_args **storage)
{
	int		len;
	t_num	*tmp;

	mid = (max - (*storage)->next) / 2 + (*storage)->next;
	(*storage)->flag += 1;
	len = (*storage)->stack_b_num;
	if ((*storage)->stack_b_num < 4)
		small_sort(storage);
	else
	{
		while (len--)
		{
			tmp = (*storage)->head_b;
			if (tmp->index == (*storage)->next)
			{
				push('a', storage, &(*storage)->counter);
				tmp->flag = (*storage)->flag;
				r_rotate(&(*storage)->head_a, &(*storage)->tail_a, &(*storage)->counter);
				(*storage)->tail_a->sort = 1;
				(*storage)->next += 1;
			}
			else if (tmp->index < mid)
				r_rotate(&(*storage)->head_b, &(*storage)->tail_b, &(*storage)->counter);
			else
			{
				push('a', storage, &(*storage)->counter);
				tmp->flag = (*storage)->flag; ///можно вписать это в функцию push
			}
		}
	}
//	if ((*storage)->stack_b_num < 4)
//		small_sort(storage);
///////////////////////??????????????????????????
}

int		small_sort(t_args **storage)
{
	t_num	*curr;
	t_num	*next = NULL;

	if ((*storage)->head_b && (*storage)->stack_b_num < 4)
	{
		(*storage)->flag += 1;
		while ((*storage)->head_b)
		{
			curr = (*storage)->head_b;
			if (curr->next)
				next = curr->next;
			if (next && curr < next)
				s_swap(&(*storage)->head_b, &(*storage)->counter);
			push('a', storage, &(*storage)->counter); ///проверка на next?
			curr->flag = (*storage)->flag;
			if ((*storage)->head_a->index > (*storage)->head_a->next->index)
				s_swap(&(*storage)->head_a, &(*storage)->counter);
		}
		while ((*storage)->head_a->index == (*storage)->next)
		{
			r_rotate(&(*storage)->head_a, &(*storage)->tail_a, &(*storage)->counter);
			(*storage)->tail_a->sort = 1;
			(*storage)->next += 1;
			if ((*storage)->head_a->sort == 0 && (*storage)->head_a->next->sort == 0
				&& (*storage)->head_a->index > (*storage)->head_a->next->index)
				s_swap(&(*storage)->head_a, &(*storage)->counter); /////вот тут несного костыльно получилось
		}
	}
	return (1);
}

int		sort_main(t_args **storage)
{
	int mid;
	int max;
	int len;
	t_num *tmp;

	max = find_stack_max('a', *storage);
	mid = max / 2 + (*storage)->next;
	len = (*storage)->stack_a_num;
	while (len--)
	{
		tmp = (*storage)->head_a;
		if (tmp->index <= mid)
			push('b', storage, &(*storage)->counter);
		else
			r_rotate(&(*storage)->head_a, &(*storage)->tail_a, &(*storage)->counter);
	}
	print_stacks((*storage)->head_a, (*storage)->head_b);
	max = mid;
	///пока стек Б не пустой, делим напополам и сортируем
	while (!is_sorted(*storage))
	{
		while ((*storage)->head_b)
		{
			stack_b_division(mid, max, storage);
			print_stacks((*storage)->head_a, (*storage)->head_b);
		}
		////дописать случаи сортировки 1-6;
		if (!(*storage)->head_b && (*storage)->head_a->sort == 0 && (*storage)->head_a->flag != 0)
		{
			(*storage)->flag = (*storage)->head_a->flag;
			while ((*storage)->head_a->flag == (*storage)->flag)
				push('b', storage, &(*storage)->counter);
			max = find_stack_max('b', *storage);
		}
		else if (!(*storage)->head_b && (*storage)->head_a->sort == 0 && (*storage)->head_a->flag == 0)
		{
			max = find_not_sorted_part_max(*storage);
//			mid = max / 2 + (*storage)->next;
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
			max = mid;
			while ((*storage)->tail_a->sort != 1 && (*storage)->head_b->index != (*storage)->next)
				rrr_reverse(storage);
			while ((*storage)->tail_a->sort != 1)
				rr_reverse(&(*storage)->head_a, &(*storage)->tail_a, &(*storage)->counter);
		}
		print_stacks((*storage)->head_a, (*storage)->head_b);
	}

//	print_stacks((*storage)->head_a, (*storage)->head_b);
	

}
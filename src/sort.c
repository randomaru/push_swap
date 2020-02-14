//
// Created by mac on 28.01.2020.
//

#include <../inc/push_swap.h>

/*int		sort_by_sub_rank(t_args **storage)
{
	int count;

	//// 1 12 2 4 16 5 11 6 7 14 8 9 10 13 15 17 18 3
	count = (*storage)->stack_a_num;

	while (count--)
	{
		if ((*storage)->head_a->rank == 33)
			r_rotate(&(*storage)->head_a, &(*storage)->tail_a);
		else if ((*storage)->head_a->rank == 32)
		{
			push('b', storage);
			(*storage)->stack_a_num -= 1;
		}
		else if ((*storage)->head_a->rank == 31)
		{
			push('b', storage);
			r_rotate(&(*storage)->head_b, &(*storage)->tail_b);
			(*storage)->stack_a_num -= 1;
		}
	}
	return (0);
}*/ //// sort_by_sub_rank
/*int		set_sub_rank(t_args **storage, int rank, int index_min)
{
	int step_width;
	t_num *tmp;

	step_width = (*storage)->stack_a_num / 3;
	tmp = (*storage)->head_a;
	while (tmp)
	{
		if (tmp->index >= index_min && tmp->index < index_min + step_width)
			tmp->rank = rank + 1;
		else if (tmp->index >= index_min + step_width && tmp->index < index_min + step_width * 2)
			tmp->rank = rank + 2;
		else
			tmp->rank = rank + 3;
		tmp = tmp->next;
	}
	return (0);
}*/ //// set_sub_rank

int		sort_by_rank(t_args **storage)
{
	int 	count;

	count = (*storage)->stack_a_num;
	while (count--)
	{
		if ((*storage)->head_a->rank == 3)
			r_rotate(&(*storage)->head_a, &(*storage)->tail_a);
		else if ((*storage)->head_a->rank == 2)
		{
			push('b', storage);
			(*storage)->stack_a_num -= 1;
		}
		else if ((*storage)->head_a->rank == 1)
		{
			push('b', storage);
			r_rotate(&(*storage)->head_b, &(*storage)->tail_b);
			(*storage)->stack_a_num -= 1;
		}
	}
	return (0);
}

void	set_rank(t_args **storage)
{
	int step_width;
	t_num *tmp;

	step_width = (*storage)->stack_a_num / 3;
	(*storage)->step_width = step_width; ////можно убрать переменную
	tmp = (*storage)->head_a;
	while (tmp)
	{
		if (tmp->index >= 1 && tmp->index < 1 + step_width)
			tmp->rank = 1;
		else if (tmp->index >= 1 + step_width && tmp->index < 1 + step_width * 2)
			tmp->rank = 2;
		else
		{
			tmp->rank = 3;
			(*storage)->third_step_width += 1;
		}
		tmp = tmp->next;
	}
}


void	find_max_min(t_args **storage)
{
	t_num *tmp;

	tmp = (*storage)->head_a;
	while (tmp)
	{
		if ((*storage)->max_index_stack_a < tmp->index)
			(*storage)->max_index_stack_a = tmp->index;
		tmp = tmp->next;
	}
	tmp = (*storage)->head_a;
	(*storage)->min_index_stack_a = (*storage)->max_index_stack_a;
	while (tmp)
	{
		if ((*storage)->min_index_stack_a > tmp->index)
			(*storage)->min_index_stack_a = tmp->index;
		tmp = tmp->next;
	}
}

/*void	sort_stack_a(t_args **storage)
{
	find_max_min(storage);
	while (is_sorted(*storage) == -1)
	{
		if ((*storage)->head_a->index == (*storage)->max_index_stack_a && is_sorted(*storage) == 1)
		{
			r_rotate(&(*storage)->head_a, &(*storage)->tail_a);
			ft_printf("ra\n");
		}
		else if ((*storage)->head_a->index > (*storage)->head_a->next->index)
		{
			s_swap(&(*storage)->head_a);
			ft_printf("sa\n");
		}
		else if ((*storage)->head_a->index < (*storage)->tail_a->index)
		{
			rr_reverse(&(*storage)->head_a, &(*storage)->tail_a);
			ft_printf("rra\n");

		}
		else
		{
			r_rotate(&(*storage)->head_a, &(*storage)->tail_a);
			ft_printf("ra\n");
		}
	}

}*/ ////sort_stack_a

int		sort_32(t_args **storage, int step_width)
{
	////набросок, учитывать tail
	int tmp_index = 0;
	int inc = 0;

	if (!(is_sorted_checker((*storage)->head_a)))
		return (-1);
	if (!(*storage)->head_b)
		return (-1);
	tmp_index = (*storage)->head_a->index;
	while (step_width)
	{
		if ((*storage)->head_b->index < (*storage)->head_b->next->index)
		{
			s_swap(&(*storage)->head_b);
			inc++;
		}
		else if ((*storage)->head_b->index == tmp_index - 1 || (*storage)->head_b->index == tmp_index - 2)
		{
			push('a', storage);
			if ((*storage)->head_a->index > (*storage)->head_a->next->index)
				s_swap(&(*storage)->head_a);
			tmp_index = (*storage)->head_a->index;
			step_width--;
		}
		else if ((*storage)->head_b->index > (*storage)->head_b->next->index)
		{
			r_rotate(&(*storage)->head_b, &(*storage)->tail_b);
			inc++;
		}
		else while (inc-- > -1)
			rr_reverse(&(*storage)->head_b, &(*storage)->tail_b);
	}
	return (1);
}
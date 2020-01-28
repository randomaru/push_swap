//
// Created by mac on 28.01.2020.
//

#include <../inc/push_swap.h>

int		sort_by_sub_rank(t_args **storage)
{
	int count;

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
}

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

int		set_sub_rank(t_args **storage, int rank, int index_min)
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
}

void	set_rank(t_args **storage)
{
	int step_width;
	t_num *tmp;

	step_width = (*storage)->stack_a_num / 3;
	tmp = (*storage)->head_a;
	while (tmp)
	{
		if (tmp->index >= 1 && tmp->index < 1 + step_width)
			tmp->rank = 1;
		else if (tmp->index >= 1 + step_width && tmp->index < 1 + step_width * 2)
			tmp->rank = 2;
		else
			tmp->rank = 3;
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

void	**sort_stack_a(t_args **storage)
{
	find_max_min(storage);
	while (is_sorted((*storage)->head_a) == -1)
	{
		if ((*storage)->head_a->index == (*storage)->max_index_stack_a && is_sorted((*storage)->head_a->next) == 1)
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

}
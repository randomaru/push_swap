/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamarant <tamarant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 21:14:44 by tamarant          #+#    #+#             */
/*   Updated: 2020/02/26 15:10:16 by tamarant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	print_stacks(t_num *head_a, t_num *head_b)
{
	t_num *tmp_a;
	t_num *tmp_b;

	tmp_a = head_a;
	tmp_b = head_b;
	ft_printf("\n");
	while (tmp_a || tmp_b)
	{
//		if (tmp_b == NULL && tmp_a)
		if (tmp_a && !tmp_b)

		{
//			ft_printf("%7c | %7i\n", ' ', tmp_a->number);
			ft_printf("%7i r%i d%i sr%i | %16c\n", tmp_a->number, tmp_a->rank, tmp_a->depth, tmp_a->sub_rank, ' ');
			tmp_a = tmp_a->next;
		}
//		else if (tmp_a == NULL && tmp_b)
		else if (tmp_b && !tmp_a)
		{
//			ft_printf("%7c | %7i\n", ' ', tmp_b->number);
			ft_printf("%17c | %7i r%i d%i sr%i\n", ' ', tmp_b->number, tmp_b->rank, tmp_b->depth, tmp_b->sub_rank);

			tmp_b = tmp_b->next;
		}
		else if (tmp_a && tmp_b)
		{
//			ft_printf("%7i | %7i\n", tmp_a->number, tmp_b->number);
			ft_printf("%7i r%i d%i sr%i | %7i r%i d%i sr%i \n",
					tmp_a->number, tmp_a->rank, tmp_a->depth, tmp_a->sub_rank,
					tmp_b->number, tmp_b->rank, tmp_b->depth, tmp_b->sub_rank);
			tmp_a = tmp_a->next;
			tmp_b = tmp_b->next;
		}

	}
//	ft_printf("%7s | %7s\n", "stack A", "stack B");
	ft_printf("%17s | %17s\n", "stack A", "stack B");
}

int		is_sorted_stack_a(t_args *storage)
{
	t_num *tmp;
	int curr;

	tmp = storage->head_a;
	while (tmp)
	{
		curr = tmp->index;
		tmp = tmp->next;
		if ((tmp) && curr > tmp->index)
			return (-1);
	}
	return (1);
}

int is_sorted_first_three(t_args *storage)
{
	t_num *tmp;
	int curr;
	int i;

	i = 0;
	tmp = storage->head_a;
	while (tmp && i < 3)
	{
		curr = tmp->index;
		tmp = tmp->next;
		if ((tmp) && curr != tmp->index + 1)
			return (-1);
		i++;
	}
	return (1);
}

int		is_sorted_checker(t_num *head)
{
	t_num	*tmp;
	int 	prev_index;

	if (head == NULL)
		return (-1);
	tmp = head->next;
	prev_index = head->index;
	while (tmp)
	{
		if (prev_index > tmp->index)
			return (-1);
		prev_index = tmp->index;
		tmp = tmp->next;
	}
	return (1);
}

int s_swap(t_num **head)
{
	t_num	*tmp;

	tmp = *head;
	*head = (*head)->next;
	(*head)->prev = NULL;
	tmp->next = (*head)->next;
	(*head)->next = tmp;
	tmp->prev = (*head);
/*	tmp = *head;
	while (tmp != NULL)
	{
		ft_printf("%2i %2i\n", tmp->number, tmp->index);
		tmp = tmp->next;
	}*/
	return (1);
}

int r_rotate(t_num **head, t_num **tail)
{
	t_num *tmp;

	tmp = *head;
	if (!(*head)->next)
		return (1);
	*head = (*head)->next;

	(*head)->prev = NULL;
	(*tail)->next = tmp;
	tmp->prev = *tail;
	tmp->next = NULL;
	*tail = tmp;

	return (1);

/*	tmp = *head;
	while (tmp != NULL)
	{
		ft_printf("%2i %2i\n", tmp->number, tmp->index);
		tmp = tmp->next;
	}*/
}

int rr_reverse(t_num **head, t_num **tail)
{
	t_num *tmp;

	tmp = *tail;
	*tail = (*tail)->prev;
	(*tail)->next = NULL;
	(*head)->prev = tmp;
	tmp->prev = NULL;
	tmp->next = *head;
	*head = tmp;
/*	tmp = *head;
	while (tmp != NULL)
	{
		ft_printf("%2i %2i\n", tmp->number, tmp->index);
		tmp = tmp->next;
	}*/
	return (1);
}

int push(char c, t_args **storage)
{
	t_num **from;
	t_num **to;
	t_num *tmp;
	t_num *tmp_next;

	if (c == 'a')
	{
		from = &(*storage)->head_b;
		to = &(*storage)->head_a;
		(*storage)->stack_b_num -= 1;
		(*storage)->stack_a_num += 1;
	}
	else
	{
		from = &(*storage)->head_a;
		to = &(*storage)->head_b;
		if ((*storage)->tail_b == NULL)
			(*storage)->tail_b = (*storage)->head_a;
		(*storage)->stack_a_num -= 1;
		(*storage)->stack_b_num += 1;
	}
	if (*from == NULL)
		return (-1);
	tmp = *from;
	tmp_next = (*from)->next;
	if (*to == NULL)
	{
		*to = *from;
		tmp_next->prev = NULL;
		(*to)->prev = NULL;
		(*to)->next = NULL;
		*from = tmp_next;
	}
	else
	{
		if (tmp_next)
			tmp_next->prev = NULL;
		tmp->prev = NULL;
		tmp->next = *to;
		(*to)->prev = tmp;
		*to = tmp;
		*from = tmp_next;
	}
	return (1);
}


/*
73 r3 d2 sr1 |      65 r3 d1 sr2
74 r3 d2 sr1 |      64 r3 d1 sr2
75 r3 d2 sr1 |      72 r3 d1 sr2
76 r3 d2 sr1 |      69 r3 d1 sr2 ---> head B
78 r3 d2 sr2 |      71 r3 d1 sr2
79 r3 d2 sr3 |      66 r3 d1 sr2
80 r3 d2 sr3 |      70 r3 d1 sr2
81 r3 d2 sr3 |      68 r3 d1 sr2
			|      54 r2 d0 sr0
			|      32 r2 d0 sr0
			|      31 r2 d0 sr0
			|      33 r2 d0 sr0
			|      45 r2 d0 sr0
			|      30 r2 d0 sr0
			|      46 r2 d0 sr0
			|      39 r2 d0 sr0
			|      50 r2 d0 sr0
			|      49 r2 d0 sr0
			|      28 r2 d0 sr0
			|      48 r2 d0 sr0
			|      36 r2 d0 sr0
			|      53 r2 d0 sr0
			|      35 r2 d0 sr0
			|      38 r2 d0 sr0
			|      29 r2 d0 sr0
			|      43 r2 d0 sr0
			|      41 r2 d0 sr0
			|      51 r2 d0 sr0
			|      52 r2 d0 sr0
			|      40 r2 d0 sr0
			|      42 r2 d0 sr0
			|      37 r2 d0 sr0
			|      44 r2 d0 sr0
			|      34 r2 d0 sr0
			|      47 r2 d0 sr0
			|      18 r1 d0 sr0
			|      24 r1 d0 sr0
			|      13 r1 d0 sr0
			|      22 r1 d0 sr0
			|      21 r1 d0 sr0
			|       9 r1 d0 sr0
			|      10 r1 d0 sr0
			|       1 r1 d0 sr0
			|      27 r1 d0 sr0
			|      26 r1 d0 sr0
			|       4 r1 d0 sr0
			|      14 r1 d0 sr0
			|      17 r1 d0 sr0
			|       2 r1 d0 sr0
			|       3 r1 d0 sr0
			|      11 r1 d0 sr0
			|       6 r1 d0 sr0
			|      12 r1 d0 sr0
			|      16 r1 d0 sr0
			|      15 r1 d0 sr0
			|      20 r1 d0 sr0
			|      25 r1 d0 sr0
			|      19 r1 d0 sr0
			|       8 r1 d0 sr0
			|       7 r1 d0 sr0
			|      23 r1 d0 sr0
			|       5 r1 d0 sr0
			|      56 r3 d1 sr1
			|      55 r3 d1 sr1
			|      59 r3 d1 sr1
			|      60 r3 d1 sr1
			|      57 r3 d1 sr1
			|      58 r3 d1 sr1
			|      62 r3 d1 sr1
			|      63 r3 d1 sr1
			|      61 r3 d1 sr1
		stack A |           stack B*/

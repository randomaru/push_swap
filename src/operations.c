/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamarant <tamarant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 21:14:44 by tamarant          #+#    #+#             */
/*   Updated: 2020/03/03 20:48:07 by tamarant         ###   ########.fr       */
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
		if (tmp_a && !tmp_b)

		{
			ft_printf("%7i r%i d%i sr%i | %16c\n", tmp_a->number, tmp_a->rank, tmp_a->depth, tmp_a->sub_rank, ' ');
			tmp_a = tmp_a->next;
		}
		else if (tmp_b && !tmp_a)
		{
			ft_printf("%17c | %7i r%i d%i sr%i\n", ' ', tmp_b->number, tmp_b->rank, tmp_b->depth, tmp_b->sub_rank);

			tmp_b = tmp_b->next;
		}
		else if (tmp_a && tmp_b)
		{
			ft_printf("%7i r%i d%i sr%i | %7i r%i d%i sr%i \n",
					tmp_a->number, tmp_a->rank, tmp_a->depth, tmp_a->sub_rank,
					tmp_b->number, tmp_b->rank, tmp_b->depth, tmp_b->sub_rank);
			tmp_a = tmp_a->next;
			tmp_b = tmp_b->next;
		}

	}
	ft_printf("%17s | %17s\n", "stack A", "stack B");
}

int		s_swap(t_num **head)
{
	t_num	*tmp;

	if (head && *head && (*head)->next)
	{
		tmp = *head;
		*head = (*head)->next;
		tmp->next = (*head)->next;
		(*head)->next = tmp;
		if (tmp->next)
			tmp->next->prev = tmp; ///// ошибка
		tmp->prev = (*head);
		(*head)->prev = NULL;
		return (1);
	}
	return (-1);
}

int		r_rotate(t_num **head, t_num **tail)
{
	t_num *tmp;

	if (head && *head && (*head)->next)
	{
		tmp = *head;
		*head = (*head)->next;
		(*head)->prev = NULL;
		(*tail)->next = tmp;
		tmp->prev = *tail;
		tmp->next = NULL;
		*tail = tmp;
		return (1);
	}
	return (-1);
}

int		rr_reverse(t_num **head, t_num **tail)
{
	t_num *tmp;

	if (head && *head && (*head)->next)
	{
		tmp = *tail;
		*tail = (*tail)->prev;
		(*tail)->next = NULL;
		(*head)->prev = tmp;
		tmp->prev = NULL;
		tmp->next = *head;
		*head = tmp;
	}
	return (1);
}

int		push(char c, t_args **storage)
{
	t_num **from;
	t_num **to;
	t_num *curr;
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
	tmp_next = NULL;
	curr = *from; /// head_b
	if (curr->next)
		tmp_next = (*from)->next; ///head_b->next
	if (*to == NULL)
	{
		*to = *from;
		if (tmp_next)
			tmp_next->prev = NULL;
		(*to)->prev = NULL;
		(*to)->next = NULL;
		*from = tmp_next;
	}
	else
	{
		if (tmp_next)
			tmp_next->prev = NULL;
		curr->prev = NULL;
		curr->next = *to;
		(*to)->prev = curr;
//		*to = curr;
		*to = (*to)->prev;
		*from = tmp_next;
/*		*from = (*from)->next;
		(*from)->prev = NULL;
		(*to)->prev = curr;
		curr->next = *to;
		*to = (*to)->prev;*/
	}
	return (1);
}

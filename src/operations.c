/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamarant <tamarant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 21:14:44 by tamarant          #+#    #+#             */
/*   Updated: 2020/02/13 18:25:07 by tamarant         ###   ########.fr       */
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
		if (tmp_b == NULL && tmp_a)
		{
			ft_printf("%7i | %7c\n", tmp_a->number, ' ');
			tmp_a = tmp_a->next;
		}
		else if (tmp_a == NULL && tmp_b)
		{
			ft_printf("%7c | %7i\n", ' ', tmp_b->number);
			tmp_b = tmp_b->next;
		}
		else if (tmp_a && tmp_b)
		{
			ft_printf("%7i | %7i\n", tmp_a->number, tmp_b->number);
			tmp_a = tmp_a->next;
			tmp_b = tmp_b->next;
		}

	}
	ft_printf("%7s | %7s\n", "stack A", "stack B");
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

//int push(char c, t_num **head_a, t_num **head_b)
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
	}
	else
	{
		from = &(*storage)->head_a;
		to = &(*storage)->head_b;
		if ((*storage)->tail_b == NULL)
			(*storage)->tail_b = (*storage)->head_a;
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

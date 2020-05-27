/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamarant <tamarant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 21:14:44 by tamarant          #+#    #+#             */
/*   Updated: 2020/05/27 15:50:45 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	s_swap(char c, t_num **head, int *counter)
{
	t_num	*tmp;

	if (head && *head && (*head)->next)
	{
		tmp = *head;
		*head = (*head)->next;
		tmp->next = (*head)->next;
		(*head)->next = tmp;
		if (tmp->next)
			tmp->next->prev = tmp;
		tmp->prev = (*head);
		(*head)->prev = NULL;
		if (counter != NULL)
		{
			*counter += 1;
			if (c == 'a')
				ft_printf("sa\n");
			else if (c == 'b')
				ft_printf("sb\n");
		}
	}
}

void	r_rotate(char c, t_num **head, t_num **tail, int *counter)
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
		if (counter != NULL)
		{
			*counter += 1;
			if (c == 'a')
				ft_printf("ra\n");
			else if (c == 'b')
				ft_printf("rb\n");
		}
	}
}

void	rr_reverse(char c, t_num **head, t_num **tail, int *counter)
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
		if (counter != NULL)
		{
			*counter += 1;
			if (c == 'a')
				ft_printf("rra\n");
			else if (c == 'b')
				ft_printf("rrb\n");
		}
	}
}

void	push(char c, t_args **storage, int *counter)
{
	t_num **from;
	t_num **to;
	t_num *curr;
	t_num *tmp_next;

	from = ((c == 'a') ? (&(*storage)->head_b) : &(*storage)->head_a);
	to = ((c == 'a') ? (&(*storage)->head_a) : &(*storage)->head_b);
	if (c == 'a')
	{
		(*storage)->stack_b_num -= 1;
		(*storage)->stack_a_num += 1;
	}
	else
	{
		if ((*storage)->tail_b == NULL && to)
		{
			tmp_next = *to;
			while (tmp_next)
				tmp_next = tmp_next->next;
			(*storage)->tail_b = tmp_next;
		}
		(*storage)->stack_a_num -= 1;
		(*storage)->stack_b_num += 1;
	}
/*	if (c == 'a' && (*storage)->head_b)
	{
		from = &(*storage)->head_b;
		to = &(*storage)->head_a;
		(*storage)->stack_b_num -= 1;
		(*storage)->stack_a_num += 1;
	}
	else if (c == 'b' && (*storage)->head_a)
	{
		from = &(*storage)->head_a;
		to = &(*storage)->head_b;
		if ((*storage)->tail_b == NULL)
		{
			if (to)
			{
				tmp_next = *to;
				while (tmp_next)
					tmp_next = tmp_next->next;
				(*storage)->tail_b = tmp_next;
			}
		}
		(*storage)->stack_a_num -= 1;
		(*storage)->stack_b_num += 1;
	}*/
/*	else
		return ;*/
	if (*from == NULL)
		return ;
	tmp_next = NULL;
	curr = *from;
	if (curr->next)
		tmp_next = (*from)->next;
	if (*to == NULL)
	{
		*to = *from;
		if (tmp_next)
			tmp_next->prev = NULL;
		(*to)->prev = NULL;
		(*to)->next = NULL;
		*from = tmp_next;
		(*storage)->tail_b = *to;
	}
	else
	{
		if (tmp_next)
			tmp_next->prev = NULL;
		curr->prev = NULL;
		curr->next = *to;
		(*to)->prev = curr;
		*to = (*to)->prev;
		*from = tmp_next;
	}
	if (counter != NULL)
	{
		*counter += 1;
		if (c == 'a')
			ft_printf("pa\n");
		else if (c == 'b')
			ft_printf("pb\n");
	}
}

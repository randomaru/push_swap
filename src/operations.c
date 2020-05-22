/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamarant <tamarant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 21:14:44 by tamarant          #+#    #+#             */
/*   Updated: 2020/05/14 19:35:04 by mac              ###   ########.fr       */
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
			ft_printf("%6i f%2i in%2i s:%i | %8c\n", tmp_a->number, tmp_a->flag, tmp_a->index, tmp_a->sort, ' ');
			tmp_a = tmp_a->next;
		}
		else if (tmp_b && !tmp_a)
		{
			ft_printf("%19c | %6i f%2i in%2i s:%i\n", ' ', tmp_b->number, tmp_b->flag, tmp_b->index, tmp_b->sort);

			tmp_b = tmp_b->next;
		}
		else if (tmp_a && tmp_b)
		{
			ft_printf("%6i f%2i in%2i s:%i | %6i f%2i in%2i s:%i\n",
					tmp_a->number, tmp_a->flag, tmp_a->index, tmp_a->sort,
					tmp_b->number, tmp_b->flag, tmp_b->index, tmp_b->sort);
			tmp_a = tmp_a->next;
			tmp_b = tmp_b->next;
		}

	}
	ft_printf("%19s | %19s\n", "stack A", "stack B");
}

int		s_swap(char c, t_num **head, int *counter)
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
		if (counter != NULL)
		{
			*counter += 1;
			if (c == 'a')
				ft_printf("sa\n");
			else if (c == 'b')
				ft_printf("sb\n");
			return (1);
		}
		return (1);
	}
	return (-1);
}

int		ss_swap(t_args **storage)
{
	if (s_swap(0, &(*storage)->head_a, &(*storage)->counter) == -1)
		return (-1);
	if (s_swap(0, &(*storage)->head_b, &(*storage)->counter) == -1)
		return (-1);
	(*storage)->counter -= 1;
	ft_printf("ss\n");
	return (1);
}

int r_rotate(char c, t_num **head, t_num **tail, int *counter)
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
			return (1);
		}
		return (1);
	}
	return (-1);
}

void 	rr_rotate(t_args **storage)
{
	if ((*storage)->head_a && (*storage)->head_b)
	{
		r_rotate(0, &(*storage)->head_a, &(*storage)->tail_a, &(*storage)->counter);
		r_rotate(0, &(*storage)->head_b, &(*storage)->tail_b, &(*storage)->counter);
		(*storage)->counter -= 1;
		ft_printf("rr\n");
	}

}

int		rr_reverse(char c, t_num **head, t_num **tail, int *counter)
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
	if (counter != NULL)
	{
		*counter += 1;
		if (c == 'a')
			ft_printf("rra\n");
		else if (c == 'b')
			ft_printf("rrb\n");
	}
	return (1);
}

int		rrr_reverse(t_args **storage)
{
	rr_reverse(0, &(*storage)->head_a, &(*storage)->tail_a, &(*storage)->counter);
	rr_reverse(0, &(*storage)->head_b, &(*storage)->tail_b, &(*storage)->counter);
	(*storage)->counter -= 1;
	ft_printf("rrr\n");
	return (1);
}

int		push(char c, t_args **storage, int *counter)
{
	t_num **from;
	t_num **to;
	t_num *curr;
	t_num *tmp_next;

	if (c == 'a' && (*storage)->head_b)
	{
		from = &(*storage)->head_b;
		to = &(*storage)->head_a;
		(*storage)->stack_b_num -= 1;
		(*storage)->stack_a_num += 1;
/*		if ((*storage)->stack_b_num == 0)
			(*storage)->tail_b = NULL; ////*/
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
	}
	else
		return (-1);
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
		/*if (c == 'a')
			*/(*storage)->tail_b = *to;
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
		return (1);
	}
	return (1);
}

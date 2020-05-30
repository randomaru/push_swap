/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_help.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 15:23:08 by mac               #+#    #+#             */
/*   Updated: 2020/05/30 19:57:43 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	rrr_reverse(t_args **storage, int checker)
{
	if ((*storage)->head_a && (*storage)->stack_a_num > 1)
	{
		rr_reverse(0, &(*storage)->head_a,
				&(*storage)->tail_a, &(*storage)->counter);
	}
	if ((*storage)->head_b && (*storage)->stack_b_num > 1)
	{
		rr_reverse(0, &(*storage)->head_b,
				&(*storage)->tail_b, &(*storage)->counter);
	}
	if (checker == 0)
	{
		(*storage)->counter -= 1;
		ft_printf("rrr\n");
	}
}

void	rr_rotate(t_args **storage, int checker)
{
	if ((*storage)->head_a && (*storage)->stack_a_num > 1)
	{
		r_rotate(0, &(*storage)->head_a,
				&(*storage)->tail_a, &(*storage)->counter);
	}
	if ((*storage)->head_b && (*storage)->stack_b_num > 1)
	{
		r_rotate(0, &(*storage)->head_b,
				&(*storage)->tail_b, &(*storage)->counter);
	}
	if (checker == 0)
	{
		(*storage)->counter -= 1;
		ft_printf("rr\n");
	}
}

void	ss_swap(t_args **storage)
{
	if ((*storage)->head_a && (*storage)->head_b)
	{
		s_swap(0, &(*storage)->head_a, &(*storage)->counter);
		s_swap(0, &(*storage)->head_b, &(*storage)->counter);
		(*storage)->counter -= 1;
		ft_printf("ss\n");
	}
}

void	push_help(t_num **to, t_num **from, t_num *tmp_next, t_args **storage)
{
	t_num *curr;

	curr = *from;
	if (!(*storage))
		return ;
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
		*to = curr;
		*from = tmp_next;
	}
}

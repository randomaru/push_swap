/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_help.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 15:23:08 by mac               #+#    #+#             */
/*   Updated: 2020/05/27 15:23:30 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	rrr_reverse(t_args **storage, int checker)
{
	if ((*storage)->head_a && (*storage)->head_b)
	{
		rr_reverse(0, &(*storage)->head_a,
				   &(*storage)->tail_a, &(*storage)->counter);
		rr_reverse(0, &(*storage)->head_b,
				   &(*storage)->tail_b, &(*storage)->counter);
		if (checker == 0)
		{
			(*storage)->counter -= 1;
			ft_printf("rrr\n");
		}
	}
}

void	rr_rotate(t_args **storage, int checker)
{
	if ((*storage)->head_a && (*storage)->head_b)
	{
		r_rotate(0, &(*storage)->head_a,
				 &(*storage)->tail_a, &(*storage)->counter);
		r_rotate(0, &(*storage)->head_b,
				 &(*storage)->tail_b, &(*storage)->counter);
		if (checker == 0)
		{
			(*storage)->counter -= 1;
			ft_printf("rr\n");
		}
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

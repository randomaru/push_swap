/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_main_help.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 19:34:34 by mac               #+#    #+#             */
/*   Updated: 2020/05/27 19:35:20 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int		first_division(int mid, t_args **storage)
{
	t_num	*tmp;
	int		len;

	len = (*storage)->stack_a_num;
	while (len--)
	{
		tmp = (*storage)->head_a;
		if (tmp->index <= mid)
			push('b', storage, &(*storage)->counter);
		else
			r_rotate('a', &(*storage)->head_a,
					&(*storage)->tail_a, &(*storage)->counter);
	}
	return (1);
}

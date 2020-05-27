/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 15:24:23 by mac               #+#    #+#             */
/*   Updated: 2020/05/27 15:24:43 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	print_stacks(t_num *head_a, t_num *head_b)
{
	t_num *tmp_a;
	t_num *tmp_b;

	tmp_a = head_a;
	tmp_b = head_b;
	while (tmp_a || tmp_b)
	{
		if (tmp_b == NULL && tmp_a)
		{
			ft_printf("%13i | %7c\n", tmp_a->number, ' ');
			tmp_a = tmp_a->next;
		}
		else if (tmp_a == NULL && tmp_b)
		{
			ft_printf("%13c | %1i\n", ' ', tmp_b->number);
			tmp_b = tmp_b->next;
		}
		else if (tmp_a && tmp_b)
		{
			ft_printf("%13i | %1i\n", tmp_a->number, tmp_b->number);
			tmp_a = tmp_a->next;
			tmp_b = tmp_b->next;
		}
	}
}

void	print_stacks_help(t_num *head_a, t_num *head_b)
{
	write(1, "\033[0d\033[2J", 8);
	print_stacks(head_a, head_b);
	ft_printf("-----------------------------\n");
	ft_printf("%13s | %7s\n", "stack A", "stack B");
	ft_printf("-----------------------------\n");
}

void	output_stacks(t_args **storage)
{
	if ((*storage)->flag_v == 1)
	{
		usleep(100500);
		print_stacks_help((*storage)->head_a, (*storage)->head_b);
	}
}

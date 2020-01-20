/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamarant <tamarant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 13:28:17 by tamarant          #+#    #+#             */
/*   Updated: 2020/01/20 21:50:00 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include <stdio.h>

int		main(int argc, char **argv)
{
	t_num	*head;
	t_num	*head_b;
	t_num	*tail;
	t_num	*head_tmp;
	t_num	*new;
	int		i;

	new = NULL;
	head = NULL;
	head_b = NULL;
	tail = NULL;
	i = 1;
	if (!(new = new_t_num()))
		return (-1);
	if (argc < 2)
	{
		ft_printf("ERROR: number of arguments should be more than zero");
		return (0);
	}
	if (argc > 1)
	{
		while (argc > 1)
		{
			if (save_numbers(argv[i], &new, &head, &tail) == -1)
			{
				ft_printf("ERROR");
				if (head)
					final_free(&head);
				if (new)
					final_free(&new); ////Немного КОСТЫЛЬ
				return (0);
			}
			i++;
			argc--;
		}
	}
	set_index(&head);
	head_tmp = head;
	while (head_tmp != NULL)
	{
		ft_printf("%2i %2i\n", head_tmp->number, head_tmp->index);
		head_tmp = head_tmp->next;
	}
	ft_printf("\n");
/*	while (tail)
	{
		ft_printf("%2i %2i\n", tail->number, tail->index);
		tail = tail->prev;
	}*/
//	rr_reverse(&head, &tail);
	push('b', &head, &head_b);
	push('b', &head, &head_b);

	t_num *tmp_head_a = head;
	t_num *tmp_head_b = head_b;
	while (tmp_head_a || tmp_head_b)
	{
		if (tmp_head_b == NULL && tmp_head_a)
		{
			ft_printf("%7i | %7c\n", tmp_head_a->number, ' ');
			tmp_head_a = tmp_head_a->next;
		}
		else if (tmp_head_a == NULL && tmp_head_b)
		{
			ft_printf("%7c | %7i\n", ' ', tmp_head_b->number);
			tmp_head_b = tmp_head_b->next;
		}
		else if (tmp_head_a && tmp_head_b)
		{
			ft_printf("%7i | %7i\n", tmp_head_a->number, tmp_head_b->number);
			tmp_head_a = tmp_head_a->next;
			tmp_head_b = tmp_head_b->next;
		}

	}
	ft_printf("\n%7s | %7s\n", "stack A", "stack B");
	final_free(&head);
	return (0);
}
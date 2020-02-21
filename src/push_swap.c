/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamarant <tamarant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 13:28:17 by tamarant          #+#    #+#             */
/*   Updated: 2020/02/21 15:02:54 by tamarant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include <stdio.h>

/*void	print_stacks(t_num *head_a, t_num *head_b)
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
}*/ //// old print_stacks

int		main(int argc, char **argv)
{
	t_args	*storage;
	t_num	*new;
	int		i;

	new = NULL;
	i = 1;

	if (!(storage = new_t_args()))
		return (-1);
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
			if (save_numbers(argv[i], &new, &storage) == -1)
			{
				ft_printf("ERROR");
				if (new)
					final_free(&new); ////Немного КОСТЫЛЬ
				return (0);
			}
			i++;
			argc--;
		}
	}
	set_index(&storage->head_a);
	set_rank(&storage);
	sort_by_rank(&storage);
	print_stacks(storage->head_a, storage->head_b);
	storage->curr_rank = storage->head_a->rank;
	if (set_depth(&storage, storage->head_a->depth) == 1)
	{
		if (storage->curr_depth == -1)
			storage->curr_depth = storage->head_a->depth;
		print_stacks(storage->head_a, storage->head_b);
		sort_third(&storage);
	}
	/*	while (storage->is_sort != 0)
	{
		if (set_depth(&storage, storage->head_a->depth) == 1)
		{
			print_stacks(storage->head_a, storage->head_b);
			sort_third(&storage);
		}

	}*/


	/*	head_tmp = storage->head_a;
	while (head_tmp != NULL)
	{
		ft_printf("%2i %2i %2i\n", head_tmp->number, head_tmp->index, head_tmp->rank);
		head_tmp = head_tmp->next;
	}
	ft_printf("\n");*/ //проверка index && rank
/*	tail = storage->tail_a;
	while (tail)
	{
		ft_printf("%2i %2i\n", tail->number, tail->index);
		tail = tail->prev;
	}*/ //проверяем tail

/*
	set_sub_rank(&storage, 30, 13); //// обрати внимание на второй аргумент
	sort_by_sub_rank(&storage);
	print_stacks(storage->head_a, storage->head_b);*/

	final_free(&storage->head_a);

	return (0);
}

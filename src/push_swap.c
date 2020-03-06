/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamarant <tamarant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 13:28:17 by tamarant          #+#    #+#             */
/*   Updated: 2020/03/06 17:23:56 by tamarant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include <stdio.h>

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
	print_stacks(storage->head_a, storage->head_b);


	sort_main(&storage);

	ft_printf("sum of op: %i\n", storage->counter);

	final_free(&storage->head_a);

	return (0);
}

/// 24 14 17 11 1 20 15 10 16 4 22 3 2 23 21 18 6 8 19 12 25 5 26 7 9 13
/// 14 17 11 1 15 10 16 4 3 2 18 6 8 12 5 7 9 13 здесь поймали первую сегу
/// 10 7 8 9 3 5 1 6 2 4
/// 11 1 10 4 3 2 6 8 12 5 7 9   "8 7 9" не отсортировал и зациклился


/*
	1 r 3 |     13 r 1
	2 r 3 |      9 r 1
	3 r 3 |      7 r 1
	4 r 2 |     12 r 1
	5 r 2 |      8 r 1
	6 r 2 |     10 r 1
		  |     11 r 1
  stack A |    stack B

	11 r 1 |
	10 r 1 |
	12 r 1 |
	13 r 1 |
	 1 r 3 |
	 9 r 3 |
	 7 r 3 |
	 8 r 3 |
   stack A |    stack B*/

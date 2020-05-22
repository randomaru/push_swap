/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamarant <tamarant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 13:28:17 by tamarant          #+#    #+#             */
/*   Updated: 2020/05/22 21:43:21 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include <stdio.h>

int		main(int argc, char **argv)
{
	t_args	*storage;
	t_num	*new;
	t_num	*tmp;
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
				final_free(&storage);////отфришить нью нормально
				while (new)
				{
					tmp = new->next;
					if (new)
						free(new);
					new = tmp;
				}
				return (0);
			}
			i++;
			argc--;
		}
	}
	if (set_index(&storage->head_a) == -1)
	{
		ft_printf("There is duplicates.");
		final_free(&storage);
		return (0);
	}
	if (!is_all_sorted(storage))
		sort_main(&storage);
//	ft_printf("sum of op: %i\n", storage->counter);
	final_free(&storage);
	return (0);
}

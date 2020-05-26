/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamarant <tamarant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 13:28:17 by tamarant          #+#    #+#             */
/*   Updated: 2020/05/26 18:53:03 by mac              ###   ########.fr       */
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
	if (argc < 2 || *argv[1] == '\0')
	{
		ft_printf("Usage: ./push_swap [arg_1] [arg_2]...arg[n]\n");
		final_free(&storage, &new);
		return (0);
	}
	if (argc > 1)
	{
		while (argc > 1)
		{
			if (save_numbers(argv[i], &new, &storage) == -1)
			{
				write(2, "Error\n", 6);
				final_free(&storage, &new);
				return (0);
			}
			i++;
			argc--;
		}
	}
	if (set_index(&storage->head_a) == -1)
	{
		write(2, "Error\n", 6);
		final_free(&storage, &new);
		return (0);
	}
	if (!is_all_sorted(storage))
		sort_main(&storage);
	final_free(&storage, &new);
	exit(0);
	return (0);
}

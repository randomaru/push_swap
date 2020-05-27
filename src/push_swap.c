/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamarant <tamarant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 13:28:17 by tamarant          #+#    #+#             */
/*   Updated: 2020/05/27 14:52:13 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int			main(int argc, char **argv)
{
	t_args	*storage;
	t_num	*new;

	if (init_new(&new, &storage) == -1)
		return (0);
	if (argc < 2 || *argv[1] == '\0')
	{
		ft_printf("Usage: ./push_swap [arg_1] [arg_2]...arg[n]\n");
		final_free(&storage, &new);
		return (0);
	}
	if (argc > 1)
	{
		if (check_args(argc, argv, new, storage) == -1)
			return (0);
		if (!is_all_sorted(storage))
			sort_main(&storage);
	}
	final_free(&storage, &new);
	exit(0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_help.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamarant <tamarant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 15:20:35 by tamarant          #+#    #+#             */
/*   Updated: 2020/05/30 18:05:29 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int			check_args(int argc, char **argv, t_num *new, t_args *storage)
{
	int i;

	i = 1;
	while (argc > 1)
	{
		if (save_numbers(*(argv + i), &new, &storage) == -1)
		{
			write(2, "Error\n", 6);
			final_free(&storage, &new);
			return (-1);
		}
		i++;
		argc--;
	}
	if (set_index(&storage) == -1)
	{
		write(2, "Error\n", 6);
		final_free(&storage, &new);
		return (-1);
	}
	return (1);
}

int			init_new(t_num **new, t_args **storage)
{
	if (!(*new = new_t_num()))
	{
		write(2, "Error\n", 6);
		return (-1);
	}
	if (!(*storage = new_t_args()))
	{
		free(*new);
		write(2, "Error\n", 6);
		return (-1);
	}
	return (1);
}

static int	parse_rr(t_args *storage, char *line)
{
	if (!(ft_strcmp("ra", line)))
		r_rotate('a', &storage->head_a, &storage->tail_a, NULL);
	else if (!(ft_strcmp("rb", line)))
		r_rotate('b', &storage->head_b, &storage->tail_b, NULL);
	else if (!(ft_strcmp("rr", line)))
		rr_rotate(&storage, 1);
	else if (!(ft_strcmp("rra", line)))
		rr_reverse('a', &storage->head_a, &storage->tail_a, NULL);
	else if (!(ft_strcmp("rrb", line)))
		rr_reverse('b', &storage->head_b, &storage->tail_b, NULL);
	else if (!(ft_strcmp("rrr", line)))
		rrr_reverse(&storage, 1);
	else
		return (-1);
	return (1);
}

int			parse_args(t_args *storage, char *line)
{
	if (line == NULL)
		return (0);
	if (!(ft_strcmp("sa", line)))
		s_swap('a', &storage->head_a, NULL);
	else if (!(ft_strcmp("sb", line)))
		s_swap('b', &storage->head_b, NULL);
	else if (!(ft_strcmp("ss", line)))
		ss_swap(&storage);
	else if (!(ft_strcmp("pa", line)))
		push('a', &storage, NULL);
	else if (!(ft_strcmp("pb", line)))
		push('b', &storage, NULL);
	else if (*line == 'r')
	{
		if (parse_rr(storage, line) == -1)
			return (-1);
	}
	else
		return (-1);
	if (storage->flag_v == 1)
		output_stacks(&storage);
	return (1);
}

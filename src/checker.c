/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamarant <tamarant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 21:14:33 by tamarant          #+#    #+#             */
/*   Updated: 2020/05/27 02:39:23 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int		is_sorted(t_args *storage)
{
	t_num	*tmp;
	int 	prev_index;

	if (storage->head_b != NULL || storage->head_a == NULL)
		return (-1);
	tmp = storage->head_a->next;
	prev_index = storage->head_a->index;
	while (tmp)
	{
		if (prev_index > tmp->index)
			return (-1);
		prev_index = tmp->index;
		tmp = tmp->next;
	}
	return (1);
}

int		parse_args(t_args *storage, char *line)
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
	else if (!(ft_strcmp("ra", line)))
		r_rotate('a', &storage->head_a, &storage->tail_a, NULL);
	else if (!(ft_strcmp("rb", line)))
		r_rotate('b',&storage->head_b, &storage->tail_b, NULL);
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

int 	valid_and_parse_args(t_args *storage)
{
	int res;
	char *line;

	while ((res = get_next_line(0, &line)) > 0)

	{
		if (*line == '\0')
		{
			free(line);
			break ; /////pipe запустить гнл еще раз?????
		}
		if (parse_args(storage, line) == -1)
		{
			if (line)
				free(line);
			line = NULL;
			return (0);
		}
		if (line)
			free(line);
		line = NULL;
	}
	return ((is_sorted(storage) == 1) ? 1 : -1);
}

int 	main(int argc, char **argv)
{
	int		i;
	int		res;
	t_args	*storage;
	t_num	*new;


	i = 1;
	if (!(new = new_t_num()))
		return (-1);
	if (!(storage = new_t_args()))
		return (-1);
	if (argc < 2 || *argv[1] == '\0')
	{
		final_free(&storage, &new);
		return (0);
	}
	else
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
		if (set_index(&storage->head_a) == -1)
		{
			write(2, "Error\n", 6);
			final_free(&storage, &new);
			return (0);
		}
	}
	res = valid_and_parse_args(storage);
	if (res == 1)
		ft_printf("OK\n");
	else if (res == -1)
		ft_printf("KO\n");
	else
		write(2, "Error\n", 6);
	final_free(&storage, &new);
	exit(0);
//	return (0);
}
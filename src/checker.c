/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamarant <tamarant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 21:14:33 by tamarant          #+#    #+#             */
/*   Updated: 2020/05/22 17:06:07 by mac              ###   ########.fr       */
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
		return (s_swap('a', &storage->head_a, NULL));
	else if (!(ft_strcmp("sb", line)))
		return (s_swap('b', &storage->head_b, NULL));
	else if (!(ft_strcmp("ss", line)))
	{
		if (s_swap('a', &storage->head_a, NULL)
		&& s_swap('b',&storage->head_b, NULL))
			return (1);
	}
	else if (!(ft_strcmp("pa", line)))
		return (push('a', &storage, NULL));
	else if (!(ft_strcmp("pb", line)))
		return (push('b', &storage, NULL));
	else if (!(ft_strcmp("ra", line)))
		return (r_rotate('a', &storage->head_a, &storage->tail_a, NULL));
	else if (!(ft_strcmp("rb", line)))
		return (r_rotate('b',&storage->head_b, &storage->tail_b, NULL));
	else if (!(ft_strcmp("rr", line)))
	{
		if (r_rotate('a', &storage->head_a, &storage->tail_a, NULL)
			&& r_rotate('b', &storage->head_b, &storage->tail_b, NULL))
			return (1);
	}
	else if (!(ft_strcmp("rra", line)))
		return (rr_reverse('a', &storage->head_a, &storage->tail_a, NULL));
	else if (!(ft_strcmp("rrb", line)))
		return (rr_reverse('b', &storage->head_b, &storage->tail_b, NULL));
	else if (!(ft_strcmp("rrr", line)))
	{
		if (rr_reverse('a', &storage->head_a, &storage->tail_a, NULL)
		&& rr_reverse('b', &storage->head_b, &storage->tail_b, NULL))
			return (1);
	}
	return (-1);
}

int 	valid_and_parse_args(t_args *storage)
{
	int res;
	char *line;

	while ((res = not_mine_get_next_line(0, &line)) > 0)

	{
		if (*line == '\0')
		{
			free(line);
			break ; /////pipe запустить гнл еще раз?????
		}
		if (parse_args(storage, line) == -1)
		{
			printf("ERROR\n");
			return (0);
		}
		free(line);
		line = NULL;
	}
	return ((is_sorted(storage) == 1) ? 1 : -1);
}

int 	main(int argc, char **argv)
{
	int i = 1;
	t_args	*storage;
	t_num	*new;

	if (!(new = new_t_num()))
		return (-1);
	if (!(storage = new_t_args()))
		return (-1);
	if (argc < 2)
	{
		ft_printf("\n");
		final_free(&storage);
		return (0);
	}
	else
	{
		while (argc > 1)
		{
			if (save_numbers(argv[i], &new, &storage) == -1)
			{
				ft_printf("ERROR\n");
				final_free(&storage); ////Немного КОСТЫЛЬ
				return (0);
			}
			i++;
			argc--;
		}
//		set_index(&storage->head_a);
		if (set_index(&storage->head_a) == -1)
		{
			ft_printf("There is duplicates.");
			final_free(&storage);
			return (0);
		}
	}
	if (valid_and_parse_args(storage) == 1)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	final_free(&storage);
	return (0);
}
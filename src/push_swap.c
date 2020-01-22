/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamarant <tamarant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 13:28:17 by tamarant          #+#    #+#             */
/*   Updated: 2020/01/22 21:25:47 by tamarant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include <stdio.h>

void	print_stacks(t_num *head_a, t_num *head_b)
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
}

/*int		save_args(int argc, char **argv)
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
}*/

int		main(int argc, char **argv)
{
	t_args	*storage;
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

//	push('b', &head, &head_b);
	print_stacks(head, head_b);
	push('b', &head, &head_b);
	print_stacks(head, head_b);
	if (push('a', &head, &head_b) == -1)
		return (-1);
	print_stacks(head, head_b);
	final_free(&head);
	final_free(&head_b);

	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamarant <tamarant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 13:28:17 by tamarant          #+#    #+#             */
/*   Updated: 2020/01/17 23:49:08 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include <stdio.h>

int		main(int argc, char **argv)
{
	t_num	*head;
	t_num	*tail;
	t_num	*head_tmp;
	t_num	*new;
	int		i;

	new = NULL;
	head = NULL;
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
	while (tail)
	{
		ft_printf("%2i %2i\n", tail->number, tail->index);
		tail = tail->prev;
	}
	final_free(&head);
	return (0);
}
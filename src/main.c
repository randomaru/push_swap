/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamarant <tamarant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 13:28:17 by tamarant          #+#    #+#             */
/*   Updated: 2020/01/16 19:50:04 by tamarant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include <stdio.h>

t_num		*new_t_num(void)
{
	t_num *new;

	if (!(new = (t_num*)malloc(sizeof(t_num))))
		return (NULL);
	new->number = 0;
	new->index = -1;
	new->group = 0;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	set_index(t_num **head)
{
	int		index;
	int		min;
	int 	num_amount;
	t_num	*tmp;
	t_num	*num_min;

	num_amount = 0;
	index = 0;
	tmp = *head;
	num_min = NULL;
	while (tmp)
	{
		num_amount++;
		tmp = tmp->next;
	}
	while (index != num_amount)
	{
		tmp = *head;
		if (tmp->index == -1)
			min = tmp->number;
		else
		{
			while (tmp->index != -1)
				tmp = tmp->next;
			min = tmp->number;
		}
		while (tmp)
		{
			if (tmp->index == -1 && tmp->number <= min)
			{
				min = tmp->number;
				num_min = tmp;
			}
			tmp = tmp->next;
		}
		num_min->index = index;
		index++;
	}
}

int 	save_numbers(char *argv, t_num **new, t_num **head)
{
	if (argv == NULL)
		return (-1);
	while (*argv != '\0')
	{
		if (*argv == ' ')
			argv += 1;
		else if (*argv >= '0' && *argv <= '9')
		{
			if (new)
			{
				if (!((*new)->next = new_t_num()))
					return(-1); /////////FREEEEE
				*new = (*new)->next;
			}
			if (((*new)->number = ft_atoi(argv)) == -1)
				return (-1); /////////FREEEEE
			if (*head == NULL)
				*head = *new;
			argv += number_len((*new)->number); //// *
			while (*argv == ' ')
			{
				argv += 1;
				if (*argv != ' ' && *argv != '\0' && (*argv < '0' || *argv > '9'))
					return (-1);
			}
			if (*argv == '\0')
				break ;
		}
		else
			return (-1); //////FREEEEEEE
	}
	return (0);
}

int		main(int argc, char **argv)
{
	t_num	*head;
	t_num	*new;
	int		i;

	new = NULL;
	head = NULL;
	i = 1;
	if (!(new = new_t_num()))
		return (-1);
	if (argc < 2)
	{
		ft_printf("ERROR: number of arguments should be more than zero");
		return (0);
	}
/*	if (argc == 2)
		return (0);*/
	if (argc > 1)
	{
		while (argc > 1)
		{
			if (save_numbers(argv[i], &new, &head) == -1)
			{
				ft_printf("ERROR");
				////FREEE T_NUM
				return (0);
			}
			i++;
			argc--;
		}
	}
	set_index(&head);
	while (head != NULL)
	{
		ft_printf("%2i %2i\n", head->number, head->index);
		head = head->next;
	}
	return (0);
}
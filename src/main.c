/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamarant <tamarant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 13:28:17 by tamarant          #+#    #+#             */
/*   Updated: 2020/01/17 23:17:33 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include <stdio.h>

void 		final_free(t_num **head)
{
	t_num *tmp;
	while (*head)
	{
		tmp = (*head)->next;
		free(*head);
		*head = tmp;
	}
}

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
			if (*head == NULL)
				*head = *new;
			else if (new)
			{
				if (!((*new)->next = new_t_num()))
					return(-1);
				*new = (*new)->next;
			}
			if (((*new)->number = ft_atoi(argv)) == -1)
				return (-1);
			if (*head == NULL)
				*head = *new;
			argv += number_len((*new)->number);
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
			return (-1);
	}
	return (0);
}

int		main(int argc, char **argv)
{
	t_num	*head;
	t_num	*head_tmp;
	t_num	*new;
	int		i;

	new = NULL;
	head = NULL;
	i = 1;
	if (!(new = new_t_num()))
		return (-1);
//	head = new;
	if (argc < 2)
	{
		ft_printf("ERROR: number of arguments should be more than zero");
		return (0);
	}
	if (argc > 1)
	{
		while (argc > 1)
		{
			if (save_numbers(argv[i], &new, &head) == -1)
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
	final_free(&head);
	return (0);
}
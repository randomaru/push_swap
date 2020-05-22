/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamarant <tamarant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 21:14:53 by tamarant          #+#    #+#             */
/*   Updated: 2020/05/22 21:11:00 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void		free_head(t_num **head)
{
	t_num *tmp;
	while (*head)
	{
		tmp = (*head)->next;
		free(*head);
		*head = tmp;
	}
}

void		final_free(t_args **storage)
{
	t_num *tmp;
	while ((*storage)->head_a)
	{
		tmp = (*storage)->head_a->next;
		free((*storage)->head_a);
		(*storage)->head_a = tmp;
	}
	(*storage)->tail_a = NULL;
//	free((*storage)->tail_b);
	(*storage)->tail_b= NULL;
	(*storage)->stack_a_num = 0;
	(*storage)->stack_b_num = 0;
	(*storage)->flag = 0;
	(*storage)->tmp_flag = 0;
	(*storage)->next = 0;
	(*storage)->counter = 0;
	free(*storage);
	*storage = NULL;
}

t_num		*new_t_num(void)
{
	t_num *new;

	if (!(new = (t_num*)malloc(sizeof(t_num))))
		return (NULL);
	new->number = 0;
	new->index = -1;
	new->flag = 0;
	new->sort = 0;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

t_args		*new_t_args(void)
{
	t_args *new;

	if (!(new = (t_args*)malloc(sizeof(t_args))))
		return (NULL);
	new->head_a = NULL;
	new->head_b = NULL;
	new->tail_a = NULL;
	new->tail_b = NULL;
	new->stack_a_num = 0;
	new->stack_b_num = 0;

	new->min = 0;
	new->mid = 0;
	new->max = 0;
	new->flag = 0;
	new->next = 1;
	new->curr_stack = 'a';
	new->counter = 0;
	return (new);
}

void		set_prev(t_num **head)
{
	t_num *tmp_head;
	t_num *tmp;

	tmp_head = *head;
	while (tmp_head)
	{
		tmp = tmp_head;
		tmp_head = tmp_head->next;
		if (tmp_head)
			tmp_head->prev = tmp;
	}
}

int			save_numbers(char *argv, t_num **new, t_args **storage)
{
	if (argv == NULL || *new == NULL)
		return (-1);
	while (*argv != '\0')
	{
		if (*argv == ' ')
			argv += 1;
		else if ((*argv >= '0' && *argv <= '9') || *argv == '-')
		{
			if ((*storage)->head_a == NULL)
				(*storage)->head_a = *new;
			else
			{
				if (!((*new)->next = new_t_num()))
					return(-1);
				*new = (*new)->next;
			}
			(*new)->number = ft_atoi(argv); /////переполнение??
			argv += number_len((*new)->number);
			(*storage)->stack_a_num += 1;
			while (*argv == ' ')
			{
				argv += 1;
				if (*argv != ' ' && *argv != '\0' && (*argv < '0' || *argv > '9' ) && *argv != '-')
					return (-1);
			}
			if (*argv == '\0')
			{
				(*storage)->tail_a = *new;
				break ;
			}
		}
		else
			return (-1);
	}
	set_prev(&(*storage)->head_a);
	return (0);
}

int			set_index(t_num **head)
{
	int		index;
	int		min;
	int 	num_amount;
	t_num	*tmp;
	t_num	*num_min;
	int		changes;

	num_amount = 0;
	index = 1;
	tmp = *head;
	num_min = NULL;
	while (tmp)
	{
		num_amount++;
		tmp = tmp->next;
	}
	while (index != num_amount + 1)
	{
		changes = 0;
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
				changes = 1;
			}
			tmp = tmp->next;
			if (changes && tmp && (min == tmp->number))
				return (-1);
		}
		num_min->index = index;
		index++;
	}
	return (1);
}

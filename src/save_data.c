//
// Created by mac on 17.01.2020.
//

#include "../inc/push_swap.h"

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

void	set_prev(t_num **head)
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

int 	save_numbers(char *argv, t_num **new, t_num **head, t_num **tail)
{
	if (argv == NULL || *new == NULL)
		return (-1);
	while (*argv != '\0')
	{
		if (*argv == ' ')
			argv += 1;
		else if (*argv >= '0' && *argv <= '9')
		{
			if (*head == NULL)
				*head = *new;
			else
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
			{
				*tail = *new;
				break ;
			}
		}
		else
			return (-1);
	}
	set_prev(head);
	return (0);
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
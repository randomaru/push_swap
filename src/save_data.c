/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamarant <tamarant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 21:14:53 by tamarant          #+#    #+#             */
/*   Updated: 2020/05/27 13:36:51 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static int	if_str_end(t_args **storage, t_num **new, char *argv)
{
	if (*argv == '\0')
	{
		(*storage)->tail_a = *new;
		return (1);
	}
	return (0);
}

static int	write_num(t_args **storage, t_num **new, char **argv, int sign)
{
	if ((*storage)->head_a == NULL)
		(*storage)->head_a = *new;
	else
	{
		if (!((*new)->next = new_t_num()))
			return (-1);
		*new = (*new)->next;
	}
	if (**argv == '-' || **argv == '+')
		sign = 1;
	if (int_max_atoi(&(*new)->number, *argv) == -1)
		return (-1);
	*argv += number_len((*new)->number) + sign + find_zero_len(*argv);
	(*storage)->stack_a_num += 1;
	while (**argv == ' ')
	{
		*argv += 1;
		if (**argv != ' ' && **argv != '\0'
		&& (**argv < '0' || **argv > '9') && **argv != '-')
			return (-1);
	}
	return (1);
}

int			save_numbers(char *argv, t_num **new, t_args **storage)
{
	int sign;

	sign = 0;
	if (argv == NULL || *new == NULL || *argv == '\0')
		return (-1);
	while (*argv != '\0')
	{
		if (*argv == ' ')
			argv += 1;
		else if ((*argv >= '0' && *argv <= '9')
			|| (*argv == '-' && (*(argv + 1) >= '0' && *(argv + 1) <= '9'))
			|| (*argv == '+' && (*(argv + 1) >= '0' && *(argv + 1) <= '9')))
		{
			if (write_num(storage, new, &argv, sign) == -1)
				return (-1);
			if (if_str_end(storage, new, argv) == 1)
				break ;
			sign = 0;
		}
		else
			return (-1);
	}
	set_prev(&(*storage)->head_a);
	return (0);
}

static int	set_index_help(t_args **storage, t_num **tmp, t_num **num_min)
{
	int min;

	(*storage)->changes = 0;
	*tmp = (*storage)->head_a;
	if ((*tmp)->index == -1)
		min = (*tmp)->number;
	else
	{
		while ((*tmp)->index != -1)
			(*tmp) = (*tmp)->next;
		min = (*tmp)->number;
	}
	while (*tmp)
	{
		if ((*tmp)->index == -1 && (*tmp)->number <= min)
		{
			min = (*tmp)->number;
			*num_min = *tmp;
			(*storage)->changes = 1;
		}
		(*tmp) = (*tmp)->next;
		if ((*storage)->changes && *tmp && (min == (*tmp)->number))
			return (-1);
	}
	return (0);
}

int			set_index(t_args **storage)
{
	int		num_amount;
	t_num	*tmp;
	t_num	*num_min;

	num_amount = 0;
	tmp = (*storage)->head_a;
	num_min = NULL;
	while (tmp)
	{
		num_amount++;
		tmp = tmp->next;
	}
	while ((*storage)->index != num_amount + 1)
	{
		if (set_index_help(storage, &tmp, &num_min) == -1)
			return (-1);
		num_min->index = (*storage)->index;
		(*storage)->index += 1;
	}
	return (1);
}

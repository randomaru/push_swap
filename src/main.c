/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamarant <tamarant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 13:28:17 by tamarant          #+#    #+#             */
/*   Updated: 2020/01/16 17:44:04 by tamarant         ###   ########.fr       */
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
	new->index = 0;
	new->group = 0;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

int 	save_numbers(char *argv, t_num **new, t_num **head)
{
	if (argv == NULL)
		return (-1);
	while (*argv != '\0')
	{
		if (*argv == ' ')
			*argv += 1;
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
	if (argc == 2)
		return (0);
	if (argc > 2)
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
	while (head != NULL)
	{
		ft_printf("%i\n", head->number);
		head = head->next;
	}
	return (0);
}
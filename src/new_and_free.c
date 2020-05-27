/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_and_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamarant <tamarant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 12:52:12 by tamarant          #+#    #+#             */
/*   Updated: 2020/05/27 13:27:35 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void		free_t_num(t_num *head)
{
	t_num *tmp_next;

	if (head)
	{
		while (head)
		{
			tmp_next = head->next;
			head->number = 0;
			head->index = 0;
			head->flag = 0;
			head->sort = 0;
			head->prev = NULL;
			head->next = NULL;
			free(head);
			head = tmp_next;
		}
	}
}

void		final_free(t_args **storage, t_num **new)
{
	if ((*storage)->head_a)
		free_t_num((*storage)->head_a);
	if ((*storage)->head_b)
		free_t_num((*storage)->head_b);
	if (*new && (*storage)->head_a == NULL && (*storage)->head_b == NULL)
		free(*new);
	(*storage)->tail_a = NULL;
	(*storage)->tail_b = NULL;
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
	new->flag = 0;
	new->next = 1;
	new->counter = 0;
	new->flag_v = 0;
	new->index = 1;
	new->changes = 0;
	return (new);
}

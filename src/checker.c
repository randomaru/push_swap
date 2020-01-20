#include "../inc/push_swap.h"

void s_swap(t_num **head)
{
	t_num	*tmp;

	tmp = *head;
	*head = (*head)->next;
	(*head)->prev = NULL;
	tmp->next = (*head)->next;
	(*head)->next = tmp;
	tmp->prev = (*head);
/*	tmp = *head;
	while (tmp != NULL)
	{
		ft_printf("%2i %2i\n", tmp->number, tmp->index);
		tmp = tmp->next;
	}*/
}

void	r_reverse(t_num **head, t_num **tail)
{
	t_num *tmp;

	tmp = *head;
	*head = (*head)->next;
	(*head)->prev = NULL;
	(*tail)->next = tmp;
	tmp->prev = *tail;
	tmp->next = NULL;
	*tail = tmp;

/*	tmp = *head;
	while (tmp != NULL)
	{
		ft_printf("%2i %2i\n", tmp->number, tmp->index);
		tmp = tmp->next;
	}*/
}

void	rr_reverse(t_num **head, t_num **tail)
{
	t_num *tmp;

	tmp = *tail;
	*tail = (*tail)->prev;
	(*tail)->next = NULL;
	(*head)->prev = tmp;
	tmp->prev = NULL;
	tmp->next = *head;
	*head = tmp;
/*	tmp = *head;
	while (tmp != NULL)
	{
		ft_printf("%2i %2i\n", tmp->number, tmp->index);
		tmp = tmp->next;
	}*/
}

int push(char c, t_num **head_a, t_num **head_b)
{
	t_num **from;
	t_num **to;
	t_num *tmp;
	t_num *tmp_next;

	if (c == 'a')
	{
		from = head_b;
		to = head_a;
	}
	else
	{
		from = head_a;
		to = head_b;
	}
	if (*from == NULL)
		return (-1);
	tmp = *from;
	tmp_next = (*from)->next;
	if (*to == NULL)
	{
		*to = *from;
		tmp_next->prev = NULL;
		(*to)->prev = NULL;
		(*to)->next = NULL;
		*from = tmp_next;
	}
	else
	{
		if (tmp_next)
			tmp_next->prev = NULL;
		tmp->prev = NULL;
		tmp->next = *to;
		(*to)->prev = tmp;
		*to = tmp;
		*from = tmp_next;
	}
	return (0);
}
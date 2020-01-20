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

void	push(char c, t_num **head_a, t_num **head_b)
{
	t_num *tmp;
	t_num *tmp_next;
	if (c == 'a')
	{
		tmp = *head_b;
		*head_b = (*head_b)->next;
		(*head_a)->prev = tmp;
		tmp->next = *head_a;
		*head_a = tmp;
//		*head_b = NULL;
	}
	if (c == 'b')
	{
		tmp = *head_a;
		tmp_next = (*head_a)->next;
		if (*head_b == NULL)
		{
			*head_b = *head_a;
			tmp_next->prev = NULL;
			(*head_b)->prev = NULL;
			(*head_b)->next = NULL;
			*head_a = tmp_next;
		}
		else
		{
			tmp_next->prev = NULL;
			tmp->prev = NULL;
			tmp->next = *head_b;
			(*head_b)->prev = tmp;
			(*head_b) = tmp;
			*head_a = tmp_next;
		}


	}

}
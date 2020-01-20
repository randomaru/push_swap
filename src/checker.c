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
	t_num *head_tmp;
	t_num *tail_tmp;

	head_tmp = *head;
	tail_tmp = *tail;

	*head = *tail;
	(*head)->next = head_tmp->next;
	*tail = head_tmp;
	(*tail)->prev = tail_tmp->prev;
	tail_tmp = (*tail)->prev;
	tail_tmp->next = *tail;
	head_tmp = (*head)->next;
	head_tmp->prev = *head;
	(*head)->prev = NULL;
	(*tail)->next = NULL;
/*	head_tmp = *head;
	while (head_tmp != NULL)
	{
		ft_printf("%2i %2i\n", head_tmp->number, head_tmp->index);
		head_tmp = head_tmp->next;
	}*/
}

void	rr_reverse(t_num **head, t_num **tail)
{

}
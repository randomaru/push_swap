/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_data_help.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 13:20:28 by mac               #+#    #+#             */
/*   Updated: 2020/05/27 13:38:02 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

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

int		find_zero_len(char *str)
{
	int i;
	int len;

	i = 0;
	len = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] == '0')
	{
		len++;
		i++;
	}
	if (str[i] >= '1' && str[i] <= '9')
		return (len);
	else if (str[i] == '\0' || str[i] == ' ')
		return (len - 1);
	else
		return (-1);
}

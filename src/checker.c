/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamarant <tamarant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 21:14:33 by tamarant          #+#    #+#             */
/*   Updated: 2020/01/28 01:53:26 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	putstr_fd(char const *s, int fd)
{
	while (s && *s)
		putchar_fd(*s++, fd);
}

void	putendl_fd(char const *s, int fd)
{
	putstr_fd(ft_strjoin(s, "\n"), fd);
}

void	putendl(char const *s)
{
	putendl_fd(s, 1);
}


t_args		*new_storage(void)
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
	return (new);
}

int		is_sorted(t_args *storage)
{
	t_num	*tmp;
	int 	prev_index;

	if (storage->head_b != NULL)
		return (-1);
	else if (storage->head_a == NULL)
		return (-1);
	tmp = storage->head_a->next;
	prev_index = storage->head_a->index;
	while (tmp)
	{
		if (prev_index > tmp->index)
			return (-1);
		prev_index = tmp->index;
		tmp = tmp->next;
	}
	return (1);
}

int		parse_args(t_args *storage, char *line)
{
	if (!(ft_strcmp("sa", line)))
		return (s_swap(&storage->head_a));
	else if (!(ft_strcmp("sb", line)))
		return (s_swap(&storage->head_b));
	else if (!(ft_strcmp("ss", line)))
	{
		if (s_swap(&storage->head_a) && s_swap(&storage->head_b))
			return (1);
	}
	else if (!(ft_strcmp("pa", line)))
		return (push('a', &storage->head_a, &storage->head_b));
	else if (!(ft_strcmp("pb", line)))
		return (push('b', &storage->head_a, &storage->head_b));
	else if (!(ft_strcmp("ra", line)))
		return (r_rotate(&storage->head_a, &storage->tail_a));
	else if (!(ft_strcmp("rb", line)))
		return (r_rotate(&storage->head_b, &storage->tail_b));
	else if (!(ft_strcmp("rr", line)))
	{
		if (r_rotate(&storage->head_a, &storage->tail_a)
			&& r_rotate(&storage->head_b, &storage->tail_b))
			return (1);
	}
	else if (!(ft_strcmp("rra", line)))
		return (rr_reverse(&storage->head_a, &storage->tail_a));
	else if (!(ft_strcmp("rrb", line)))
		return (rr_reverse(&storage->head_b, &storage->tail_b));
	else if (!(ft_strcmp("rrr", line)))
	{
		if (rr_reverse(&storage->head_a, &storage->tail_a)
		&& rr_reverse(&storage->head_b, &storage->tail_b))
			return (1);
	}
	else
		return (-1);
}

int 	valid_and_parse_args(t_args *storage)
{
	int res;
	char *line;

	while ((res = not_mine_get_next_line(0, &line)) != EOF)
	{
		if (parse_args(storage, line) == -1)
		{
			printf("ERROR\n");
			return (0);
		}
		if (line == NULL)
			return ((is_sorted(storage) == 1) ? 1 : -1);
		putendl(line);
		free(line);
		line = NULL;
	}
	return (-1);

}

int 	main(int argc, char **argv)
{
	int i = 1;
	t_args	*storage;
	t_num	*head;
	t_num	*head_b;
	t_num	*tail;
	t_num	*head_tmp;
	t_num	*new;
	char	*line = NULL;
	int res;

	if (!(new = new_t_num()))
		return (-1);
	if (!(storage = new_t_args()))
		return (-1);
	if (argc < 2)
	{
		ft_printf("\n");
		return (0);
	}
	else
	{
		while (argc > 1)
		{
			if (save_numbers(argv[i], &new, &head, &tail) == -1)
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
		set_index(&head);
		head_tmp = head;
	}
	storage->head_a = head;
	if (valid_and_parse_args(storage) == 1)
		ft_printf("OK");
	else
		ft_printf("KO");
	return (0);
}
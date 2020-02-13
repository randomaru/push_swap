/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamarant <tamarant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 21:14:33 by tamarant          #+#    #+#             */
/*   Updated: 2020/02/13 19:27:20 by tamarant         ###   ########.fr       */
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
	if (line == NULL)
		return (0);
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
		return (push('a', &storage));
	else if (!(ft_strcmp("pb", line)))
		return (push('b', &storage));
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

//	int fd = open("/Users/tamarant/Desktop/projects/push_swap/src/test_checker", O_RDONLY);
	while ((res = not_mine_get_next_line(0, &line)) > 0)

	{
		if (*line == '\0')
		{
			free(line);
			break ; /////pipe запустить гнл еще раз?????
		}
		if (parse_args(storage, line) == -1)
		{
			printf("ERROR\n");
			return (0);
		}
		putendl(line);
		free(line);
		line = NULL;
	}
	return ((is_sorted(storage) == 1) ? 1 : -1);
}

int 	main(int argc, char **argv)
{
	int i = 1;
	t_args	*storage;
	t_num	*new;
	char	*line = NULL;

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
			if (save_numbers(argv[i], &new, &storage) == -1)
			{
				ft_printf("ERROR");
				if (storage->head_a)
					final_free(&storage->head_a); ////Немного КОСТЫЛЬ
				return (0);
			}
			i++;
			argc--;
		}
		set_index(&storage->head_a);
	}
	print_stacks(storage->head_a, storage->head_b);
	if (valid_and_parse_args(storage) == 1)
	{
		print_stacks(storage->head_a, storage->head_b);
		ft_printf("OK");
	}
	else
	{
		print_stacks(storage->head_a, storage->head_b);
		ft_printf("KO");
	}
		return (0);
}
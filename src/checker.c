/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamarant <tamarant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 21:14:33 by tamarant          #+#    #+#             */
/*   Updated: 2020/05/30 18:05:29 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int			valid_and_parse_args(t_args *storage)
{
	char *line;

	if (storage->flag_v == 1)
		output_stacks(&storage);
	while (get_next_line(0, &line) > 0)
	{
		if (*line == '\0')
		{
			free(line);
			break ;
		}
		if (parse_args(storage, line) == -1)
		{
			if (line)
				free(line);
			line = NULL;
			return (0);
		}
		if (line)
			free(line);
		line = NULL;
	}
	return ((is_all_sorted(storage) == 1) ? 1 : -1);
}

static void	args_errors(int res)
{
	if (res == -1)
		ft_printf("KO\n");
	else
		write(2, "Error\n", 6);
}

static int	is_flag(int *argc, char **argv, t_args **storage)
{
	if (!ft_strcmp("-v", *(argv + 1)))
	{
		(*storage)->flag_v = 1;
		*argc -= 1;
		return (1);
	}
	return (0);
}

int			main(int argc, char **argv)
{
	int		res;
	t_args	*storage;
	t_num	*new;

	if (init_new(&new, &storage) == -1)
		return (0);
	if (argc < 2 || *argv[1] == '\0')
	{
		final_free(&storage, &new);
		return (0);
	}
	else
	{
		if (is_flag(&argc, argv, &storage))
			argv += 1;
		if (check_args(argc, argv, new, storage) == -1)
			return (0);
	}
	if ((res = valid_and_parse_args(storage)) == 1)
		ft_printf("OK\n");
	else
		args_errors(res);
	final_free(&storage, &new);
	exit(0);
}

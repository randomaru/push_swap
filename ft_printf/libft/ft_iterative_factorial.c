/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamarant <tamarant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 18:51:39 by tamarant          #+#    #+#             */
/*   Updated: 2020/04/07 21:32:00 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_iterative_factorial(int nb)
{
	int i;

	i = nb;
	if (nb == 0)
	{
		return (1);
	}
	if (nb < 0 || nb > 12)
	{
		return (0);
	}
	while (i > 1)
	{
		nb = nb * (i - 1);
		i--;
	}
	return (nb);
}

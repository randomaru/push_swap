/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_max_atoi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamarant <tamarant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 23:12:00 by mac               #+#    #+#             */
/*   Updated: 2020/05/26 23:57:13 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_if_neg(const char *str, int i)
{
	int neg;

	neg = 0;
	if (str[i] == '-')
		neg = 1;
	return (neg);
}

int				int_max_atoi(int *n, const char *str)
{
	int			i;
	int			neg;
	long long   res;

	i = 0;
	res = 0;
	if (str == NULL || str[i] == '\0')
		return (-1);
	while ((str[i] == 32) || (str[i] >= 9 && str[i] <= 13 && str[i] != '\0'))
		i++;
	if ((neg = ft_if_neg(str, i)) && str[i + 1] >= '0' && str[i + 1] <= '9')
		i++;
	if (str[i] == '+' && str[i + 1] >= '0' && str[i + 1] <= '9')
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		if ((!neg && (res * 10 + (str[i] - '0') > 2147483647))
		|| (neg && (res * 10 + (str[i] - '0') > 2147483648)))
			return (-1);
		res = res * 10 + (str[i++] - '0');
	}
	if (neg)
		res = -(res);
	*n = (int)res;
	return (1);
}


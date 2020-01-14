/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamarant <tamarant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 20:32:01 by tamarant          #+#    #+#             */
/*   Updated: 2019/12/26 18:17:49 by tamarant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi_base(const char *str)
{
	int		res;

	res = 0;
	if (!str)
		return (16777215);
	while (*str == '0' || *str == 'x')
		str++;
	while ((*str >= '0' && *str <= '9') ||
		(*str >= 'a' && *str <= 'f') || (*str >= 'A' && *str <= 'F'))
	{
		res = res * 16 + (*str - 48);
		str++;
	}
	return (res);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamarant <tamarant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 15:28:57 by tamarant          #+#    #+#             */
/*   Updated: 2020/04/07 21:32:00 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char *res;

	res = NULL;
	if (size)
	{
		res = (char*)malloc(sizeof(*res) * size);
		if (res == NULL)
			return (NULL);
		ft_bzero(res, size);
	}
	return ((void*)res);
}

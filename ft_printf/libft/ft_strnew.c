/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamarant <tamarant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 22:42:58 by tamarant          #+#    #+#             */
/*   Updated: 2020/01/22 16:08:23 by tamarant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*res;
	size_t	i;

	i = 0;
	if (size + 1 == 0)
		return (0);
	if (!(res = (char*)malloc(sizeof(*res) * (size + 1))))
		return (NULL);
	while (i < size)
		res[i++] = '\0';
	return (res);
}

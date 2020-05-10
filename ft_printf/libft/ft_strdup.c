/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamarant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 19:00:03 by tamarant          #+#    #+#             */
/*   Updated: 2020/04/07 21:31:59 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*cop;
	int		len;

	len = 0;
	if (!s1)
		return (NULL);
	while (s1[len] != '\0')
		len++;
	if (!(cop = (char*)malloc(sizeof(*s1) * (len + 1))))
		return (NULL);
	len = 0;
	while (s1[len] != '\0')
	{
		cop[len] = s1[len];
		len++;
	}
	cop[len] = '\0';
	return (cop);
}

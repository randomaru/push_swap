/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow_double.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamarant <tamarant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 17:41:30 by tamarant          #+#    #+#             */
/*   Updated: 2020/02/20 14:35:27 by tamarant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

LD		ft_pow_double(LD n, ULL pow)
{
	return (pow ? n * ft_pow_double(n, pow - 1) : 1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamarant <tamarant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 21:45:41 by tamarant          #+#    #+#             */
/*   Updated: 2020/01/14 21:47:30 by tamarant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

	typedef struct		s_number
	{
		int 			number;
		int				index;
		int 			group;
		struct s_number	*next;
	}					t_num;

#endif

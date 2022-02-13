/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push_all.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonniss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 13:27:40 by abonniss          #+#    #+#             */
/*   Updated: 2022/01/16 13:28:37 by abonniss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	stack_push_all(t_stack **stack_1, t_stack **stack_2)
{
	size_t	i;
	size_t	nb_nodes;

	if (*stack_1 != NULL && (*stack_1)->stack_size != 0)
	{
		i = 0;
		nb_nodes = (*stack_1)->stack_size;
		while (i < nb_nodes)
		{
			stack_exchange(stack_2, stack_1);
			i++;
		}
	}
}

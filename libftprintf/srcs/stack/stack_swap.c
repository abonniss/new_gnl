/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonniss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 13:52:07 by abonniss          #+#    #+#             */
/*   Updated: 2021/12/20 14:15:06 by abonniss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	stack_swap(t_stack **ptr_stack)
{
	t_stack	*current_node;
	t_stack	*tmp;

	current_node = *ptr_stack;
	if (current_node != NULL && current_node->stack_size >= 2)
	{
		tmp = current_node->prev;
		if (current_node->stack_size == 2)
			current_node->prev = NULL;
		else
		{	
			current_node->prev = tmp->prev;
			tmp->prev->next = current_node;
		}
		current_node->next = tmp;
		tmp->prev = current_node;
		tmp->next = NULL;
		tmp->stack_size += 1;
		current_node->stack_size -= 1;
		*ptr_stack = tmp;
	}
}

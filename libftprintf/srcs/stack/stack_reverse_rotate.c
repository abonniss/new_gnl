/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_reverse_rotate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonniss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 13:54:32 by abonniss          #+#    #+#             */
/*   Updated: 2021/12/20 14:08:43 by abonniss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	stack_reverse_rotate(t_stack **ptr_stack)
{
	t_stack	*current_node;
	t_stack	*last_node;

	current_node = *ptr_stack;
	if (current_node->stack_size > 1)
	{
		last_node = stack_get_root_node(current_node);
		last_node->prev = current_node;
		current_node->next = last_node;
		last_node->next->prev = NULL;
		last_node->next = NULL;
		*ptr_stack = last_node;
		last_node->stack_size = current_node->stack_size + 1;
		while (last_node != NULL)
		{
			last_node->stack_size -= 1;
			last_node = last_node->prev;
		}
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonniss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 13:53:34 by abonniss          #+#    #+#             */
/*   Updated: 2021/12/20 14:10:53 by abonniss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	stack_rotate(t_stack **ptr_stack)
{
	t_stack	*current_node;
	t_stack	*last_node;

	current_node = *ptr_stack;
	if (current_node->stack_size > 1)
	{
		last_node = stack_get_root_node(current_node);
		last_node->prev = current_node;
		current_node->next = last_node;
		current_node->prev->next = NULL;
		*ptr_stack = current_node->prev;
		current_node->prev = NULL;
		current_node->stack_size = 1;
		while (last_node != NULL)
		{
			last_node->stack_size += 1;
			last_node = last_node->next;
		}
	}
}

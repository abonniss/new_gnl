/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonniss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 13:57:51 by abonniss          #+#    #+#             */
/*   Updated: 2022/01/12 16:58:04 by abonniss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	stack_push(t_stack **ptr_stack, int nbr, int position)
{
	t_stack	*new_node;
	t_stack	*current_node;

	current_node = *ptr_stack;
	new_node = stack_create_node();
	new_node->number = nbr;
	new_node->position = position;
	if (current_node == NULL)
		new_node->stack_size = 1;
	else
	{
		new_node->stack_size = current_node->stack_size + 1;
		new_node->prev = current_node;
		current_node->next = new_node;
	}
	*ptr_stack = new_node;
}

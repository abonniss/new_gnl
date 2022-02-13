/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_pop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonniss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 13:55:21 by abonniss          #+#    #+#             */
/*   Updated: 2021/12/20 14:09:58 by abonniss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	stack_pop(t_stack **ptr_stack)
{
	t_stack	*current_node;

	current_node = *ptr_stack;
	if (current_node == NULL)
		return ;
	if (current_node->prev == NULL)
	{
		free(current_node);
		*ptr_stack = NULL;
		return ;
	}
	*ptr_stack = current_node->prev;
	free(current_node);
	return ;
}

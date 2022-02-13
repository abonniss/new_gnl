/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_get_root_node.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonniss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 13:27:18 by abonniss          #+#    #+#             */
/*   Updated: 2022/01/16 13:27:23 by abonniss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_stack	*stack_get_root_node(t_stack *ptr_stack)
{
	if (ptr_stack == NULL)
		return (NULL);
	while (ptr_stack->prev != NULL)
		ptr_stack = ptr_stack->prev;
	return (ptr_stack);
}

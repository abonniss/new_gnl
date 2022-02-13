/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonniss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 14:00:05 by abonniss          #+#    #+#             */
/*   Updated: 2022/01/15 19:45:45 by abonniss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "ft_printf.h"

void	stack_print(t_stack *stack)
{
	if (stack != NULL)
		ft_printf("Stack Size (%d)\n", stack->stack_size);
	while (stack != NULL)
	{
		ft_printf("(%d)[%d]->", stack->number, stack->final_rank);
		stack = stack->prev;
	}
	ft_printf("\n------------\n");
}

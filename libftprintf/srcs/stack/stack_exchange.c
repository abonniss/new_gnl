/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_exchange.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonniss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 13:58:41 by abonniss          #+#    #+#             */
/*   Updated: 2022/01/16 13:26:19 by abonniss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	stack_exchange(t_stack **receiver, t_stack **sender)
{
	int	sender_number;
	int	sender_position;

	if (*sender != NULL)
	{
		sender_number = stack_get_number(*sender);
		sender_position = stack_get_position(*sender);
		stack_pop(sender);
		stack_push(receiver, sender_number, sender_position);
	}
}

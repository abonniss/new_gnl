/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonniss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 11:59:55 by abonniss          #+#    #+#             */
/*   Updated: 2022/01/16 13:34:03 by abonniss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H
# define NOT_SET -1

# include "libft.h"

typedef struct s_stack
{
	int				number;
	int				final_rank;
	int				position;
	size_t			stack_size;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

t_stack	*stack_create_node(void);

void	stack_print(t_stack *stack);
void	stack_swap(t_stack **ptr_stack);
void	stack_rotate(t_stack **ptr_stack);
void	stack_reverse_rotate(t_stack **ptr_stack);
void	stack_pop(t_stack **ptr_stack);
void	stack_destroy(t_stack **ptr_stack);
void	stack_push(t_stack **ptr_stack, int nbr, int final_rank);
void	stack_exchange(t_stack **receiver, t_stack **sender);
void	stack_push_all(t_stack **stack_1, t_stack **stack_2);
t_stack	*stack_create(void);
t_stack	*stack_create_node(void);
t_stack	*stack_get_root_node(t_stack *ptr_stack);
int		stack_get_number(t_stack *ptr_stack);
int		stack_get_position(t_stack *ptr_stack);

#endif

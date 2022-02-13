/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_char_buffer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonniss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 11:54:56 by abonniss          #+#    #+#             */
/*   Updated: 2021/11/20 14:12:03 by abonniss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buffer.h"

int	push_char_buffer(t_buffer *str_buff, char c)
{
	return (push_str_buffer(str_buff, &c, 1));
}

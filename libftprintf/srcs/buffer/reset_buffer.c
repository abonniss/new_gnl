/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_buffer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonniss <abonniss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 08:50:44 by abonniss          #+#    #+#             */
/*   Updated: 2021/11/20 14:12:36 by abonniss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buffer.h"

void	reset_buffer(t_buffer *buffer)
{
	ft_bzero(buffer->string, buffer->buffer_size);
	buffer->len = 0;
}

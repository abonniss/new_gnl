/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_str_buffer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonniss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 11:54:01 by abonniss          #+#    #+#             */
/*   Updated: 2021/11/20 14:12:15 by abonniss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buffer.h"

int	push_str_buffer(t_buffer *str_buff,
	const char *str, const size_t len_str)
{
	while (str_buff->len + len_str >= str_buff->buffer_size)
		if (resize_buffer(str_buff) == FAILURE)
			return (FAILURE);
	ft_memmove(str_buff->string + str_buff->len, str, len_str);
	str_buff->len += len_str;
	return (SUCCESS);
}

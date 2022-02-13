/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize_buffer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonniss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 11:52:05 by abonniss          #+#    #+#             */
/*   Updated: 2021/11/19 11:53:30 by abonniss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buffer.h"

int	resize_buffer(t_buffer *str_buff)
{
	char	*bigger_string;

	str_buff->buffer_size += BUFF_SIZE;
	bigger_string = (char *)malloc(sizeof(char) * str_buff->buffer_size);
	if (bigger_string != NULL)
	{
		ft_bzero(bigger_string, str_buff->buffer_size);
		ft_memmove(bigger_string, str_buff->string,
			str_buff->len);
		free(str_buff->string);
		str_buff->string = bigger_string;
		return (SUCCESS);
	}
	return (FAILURE);
}

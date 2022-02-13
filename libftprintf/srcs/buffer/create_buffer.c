/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_buffer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonniss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 11:56:56 by abonniss          #+#    #+#             */
/*   Updated: 2021/11/19 11:57:35 by abonniss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buffer.h"

t_buffer	*create_buffer(void)
{
	t_buffer	*str_buff;

	str_buff = malloc(sizeof(t_buffer));
	if (str_buff != NULL)
	{
		str_buff->buffer_size = BUFF_SIZE;
		str_buff->len = 0;
		str_buff->string = (char *)malloc(sizeof(char) * BUFF_SIZE);
		if (str_buff->string != NULL)
			ft_bzero(str_buff->string, str_buff->buffer_size);
		else
		{
			free(str_buff);
			str_buff = NULL;
		}
	}
	return (str_buff);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonniss <abonniss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 08:52:31 by abonniss          #+#    #+#             */
/*   Updated: 2021/11/19 09:37:44 by abonniss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFFER_H
# define BUFFER_H

# include "libft.h"

# define BUFF_SIZE 16 

typedef struct s_buffer
{
	char			*string;
	size_t			len;
	size_t			buffer_size;
}				t_buffer;

int				resize_buffer(t_buffer *str_buff);
int				push_str_buffer(t_buffer *str_buff,
					const char *str, const size_t len_str);
int				push_char_buffer(t_buffer *str_buff, char c);
void			delete_buffer(t_buffer *str_buff);
t_buffer		*create_buffer(void);
void			reset_buffer(t_buffer *buffer);
#endif

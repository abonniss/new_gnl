/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonniss <abonniss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 11:05:35 by abonniss          #+#    #+#             */
/*   Updated: 2021/11/19 20:08:28 by abonniss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include "buffer.h"
# include <stdarg.h>
# include <stddef.h>

# define SUCCESS 0
# define FAILURE -1
# define NULL_STRING "(null)"
# define CONV_CHARSET "cspduixX%"
# define FORMAT_CHAR '%'

# define NO_FLAG	0x00
# define HASH_FLAG	0x01
# define SPACE_FLAG	0x02
# define PLUS_FLAG	0x04

enum	e_state
{
	E_LETTER,
	E_FLAG,
	E_CONV
};

typedef unsigned char	t_flag;

typedef struct s_state_machine
{
	t_buffer		*buffer;
	enum e_state	state;
	t_flag			flag;
}				t_state_machine;

typedef int				(*t_state_function)(char, t_state_machine *, va_list);
typedef int				(*t_conv_function)(va_list, char **);
typedef int				(*t_conv_bonus_function)(va_list, char **, t_flag);

/*#####################FT_PRINTF#########################*/
int				ft_printf(const char *input, ...);
int				ft_dprintf(int fd, const char *input, ...);
int				ft_asprintf(char **ret, const char *input, ...);
int				ft_vasprintf(char **ret, const char *input, va_list args);
/*#####################STATE_MACHINE#######################*/
int				letter_state(char c, t_state_machine *machine, va_list args);
int				conv_state(char c, t_state_machine *machine, va_list args);
int				parse_string(char **output, const char *input, va_list args);
char			*dup_buffer(t_buffer *buffer);
/*#####################CONVERSIONS#########################*/
int				conv_c(va_list args, char **output);
int				conv_s(va_list args, char **output);
int				conv_p(va_list args, char **output);
int				conv_di(va_list args, char **output);
int				conv_u(va_list args, char **output);
int				conv_x(va_list args, char **output);
int				conv_x_big(va_list args, char **output);
int				conv_percent(va_list args, char **output);
int				conv_error(char **output, char c);
/*#####################CONVERSIONS_BONUS#########################*/
int				conv_bonus_c(va_list args, char **output, t_flag flag);
int				conv_bonus_s(va_list args, char **output, t_flag flag);
int				conv_bonus_p(va_list args, char **output, t_flag flag);
int				conv_bonus_di(va_list args, char **output, t_flag flag);
int				conv_bonus_u(va_list args, char **output, t_flag flag);
int				conv_bonus_x(va_list args, char **output, t_flag flag);
int				conv_bonus_x_big(va_list args, char **output, t_flag flag);
int				conv_bonus_percent(va_list args, char **output, t_flag flag);
int				conv_bonus_error(char **output, char c, t_flag flag);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonniss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 18:32:49 by abonniss          #+#    #+#             */
/*   Updated: 2022/02/14 18:36:16 by abonniss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_2_H
# define GET_NEXT_LINE_2_H

# include <stdio.h>
# include <stddef.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include "libft.h"

# define BUFF				5
# define NEW_LINE			'\n'
# define RET_READ_UNDEFINED 2
# define LINE_READ			1
# define END_OF_FILE		0
# define FAILURE			-1

int	get_next_line_2(int fd, char **str);

#endif
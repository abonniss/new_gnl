/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonniss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 18:51:58 by abonniss          #+#    #+#             */
/*   Updated: 2020/02/11 18:52:06 by abonniss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include "libftprintf.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <fcntl.h>

# define DELIMITER   '\n'
# define BUFFER_SIZE 4096

char    *ft_strjoin_gnl(char *st1, char *bf);
char	*ft_maketheline(char *s1);
int     ft_texteanalyse(char *ana_texte);
char	*ft_cleanstock(char *clean_stock);
int	    ft_get_next_line(int fd, char **line);
char    *ft_substr_gnl(char **str, int start, int len);
int 	ft_pushtheline(char **stock, char **line);

#endif

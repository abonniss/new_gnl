/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonniss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 18:52:15 by abonniss          #+#    #+#             */
/*   Updated: 2020/02/11 18:53:07 by abonniss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin_gnl(char *st1, char *bf)
{
	int		i;
	int		j;
	char	*st2;

	i = 0;
	while (st1[i])
		i++;
	if (!(st2 = malloc(sizeof(char) * (i + BUFFER_SIZE + 1))))
		return (NULL);
	i = 0;
	while (st1[i])
	{
		st2[i] = st1[i];
		i++;
	}
	j = 0;
	while (bf[j])
		st2[i++] = bf[j++];
	st2[i] = '\0';
	free(st1);
	st1 = NULL;
	return (st2);
}

char	*ft_maketheline(char *s1)
{
	int		i;
	char	*pre_line;

	i = 0;
	while (s1[i] && s1[i] != '\n')
		i++;
	if (!(pre_line = malloc(sizeof(char) * i + 1)))
		return (NULL);
	i = 0;
	while (s1[i] && s1[i] != '\n')
	{
		pre_line[i] = s1[i];
		i++;
	}
	pre_line[i] = '\0';
	return (pre_line);
}

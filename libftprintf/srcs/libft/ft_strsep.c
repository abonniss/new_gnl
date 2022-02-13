/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonniss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 16:44:39 by abonniss          #+#    #+#             */
/*   Updated: 2022/01/16 17:31:53 by abonniss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsep(char *input, char c, char **output)
{
	static char	*init_ptr = NULL;

	if (input == NULL)
		return (NULL);
	if (init_ptr == NULL)
		init_ptr = input;
	if (*init_ptr == '\0')
	{
		init_ptr = NULL;
		return (NULL);
	}
	while (*init_ptr == c)
		init_ptr++;
	*output = strcdup(init_ptr, c);
	if (*output == NULL)
		init_ptr = NULL;
	else
		init_ptr += ft_strclen(init_ptr, c);
	return (*output);
}

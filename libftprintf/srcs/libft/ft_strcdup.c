/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonniss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 16:10:06 by abonniss          #+#    #+#             */
/*   Updated: 2021/12/20 16:11:55 by abonniss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*strcdup(const char *input, const char c)
{
	size_t	len;
	char	*output;

	len = ft_strclen(input, c);
	if (len == 0)
		return (NULL);
	output = (char *)malloc(sizeof(char) * (len + 1));
	if (output == NULL)
		return (NULL);
	ft_strncpy(output, input, len);
	output[len] = '\0';
	return (output);
}

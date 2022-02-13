/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonniss <abonniss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 12:58:43 by abonniss          #+#    #+#             */
/*   Updated: 2021/10/23 14:53:02 by abonniss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	conv_bonus_error(char **output, char c, t_flag flag)
{
	int	ret;

	(void)flag;
	*output = (char *)ft_calloc(1, sizeof(char));
	if (*output != NULL)
		**output = c;
	ret = 1;
	return (ret);
}

int	conv_bonus_c(va_list args, char **output, t_flag flag)
{
	int	ret;
	int	c;

	(void)flag;
	c = va_arg(args, int);
	*output = (char *)ft_calloc(1, sizeof(char));
	if (*output != NULL)
		**output = (unsigned char)c;
	ret = 1;
	return (ret);
}

int	conv_bonus_s(va_list args, char **output, t_flag flag)
{
	int		ret;
	char	*str;

	(void)flag;
	str = va_arg(args, char *);
	if (str == NULL)
		str = NULL_STRING;
	ret = 0;
	*output = ft_strdup(str);
	if (*output != NULL)
		ret = ft_strlen(*output);
	return (ret);
}

int	conv_bonus_p(va_list args, char **output, t_flag flag)
{
	int				ret;
	unsigned long	lnbr;

	(void)flag;
	lnbr = va_arg(args, unsigned long);
	*output = ft_ultoa_base(lnbr, 16);
	ret = 0;
	if (*output != NULL)
	{
		ret = ft_strlen(*output);
		if (ft_add_prefix(output, HEXA_PREFIX) == FAILURE)
			ret = 0;
		else
		{
			ret += ft_strlen(HEXA_PREFIX);
			*output = ft_str_to_lowercase(*output);
		}
	}
	return (ret);
}

int	conv_bonus_percent(va_list args, char **output, t_flag flag)
{
	int	ret;

	(void)flag;
	(void)args;
	*output = (char *)ft_calloc(1, sizeof(char));
	if (*output != NULL)
		**output = '%';
	ret = 1;
	return (ret);
}

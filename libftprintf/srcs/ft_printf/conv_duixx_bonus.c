/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_duixx_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonniss <abonniss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 12:58:43 by abonniss          #+#    #+#             */
/*   Updated: 2021/10/23 15:20:04 by abonniss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	conv_bonus_di(va_list args, char **output, t_flag flag)
{
	int	ret;
	int	lnbr;

	(void)flag;
	lnbr = (int)va_arg(args, long);
	*output = ft_ltoa_base(lnbr, 10);
	if (*output == NULL)
		return (0);
	ret = ft_strlen(*output);
	if (flag & PLUS_FLAG && lnbr >= 0)
	{
		if (ft_add_prefix(output, "+") == FAILURE)
			ret = 0;
		else
			ret += ft_strlen("+");
	}
	else if (flag & SPACE_FLAG && lnbr >= 0)
	{
		if (ft_add_prefix(output, " ") == FAILURE)
			ret = 0;
		else
			ret += ft_strlen(" ");
	}
	return (ret);
}

int	conv_bonus_u(va_list args, char **output, t_flag flag)
{
	int				ret;
	unsigned int	lnbr;

	(void)flag;
	lnbr = (unsigned int)va_arg(args, unsigned long);
	*output = ft_ultoa_base(lnbr, 10);
	ret = 0;
	if (*output != NULL)
		ret = ft_strlen(*output);
	return (ret);
}

int	conv_bonus_x(va_list args, char **output, t_flag flag)
{
	int	ret;

	(void)flag;
	ret = conv_bonus_x_big(args, output, flag);
	if (*output != NULL)
		*output = ft_str_to_lowercase(*output);
	return (ret);
}

int	conv_bonus_x_big(va_list args, char **output, t_flag flag)
{
	int				ret;
	unsigned long	lnbr;

	lnbr = va_arg(args, unsigned int);
	*output = ft_ultoa_base(lnbr, 16);
	ret = 0;
	if (*output != NULL)
	{
		ret = ft_strlen(*output);
		if (lnbr != 0 && flag & HASH_FLAG)
		{
			if (ft_add_prefix(output, HEXA_PREFIX) == FAILURE)
				ret = 0;
			else
				ret += ft_strlen(HEXA_PREFIX);
		}
	}
	return (ret);
}

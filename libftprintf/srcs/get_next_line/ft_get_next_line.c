/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonniss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 18:51:40 by abonniss          #+#    #+#             */
/*   Updated: 2020/02/11 18:51:50 by abonniss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_texteanalyse(char *ana_texte)
{
	int i;

	i = 0;
	while (ana_texte[i])
	{
		if (ana_texte[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_cleanstock(char *clean_stock)
{
	int		i;
	int		j;
	char	*new_stock;

	i = 0;
	while (clean_stock[i])
	{
		if (clean_stock[i] == '\n')
		{
			i++;
			break ;
		}
		i++;
	}
	j = 0;
	while (clean_stock[i + j])
		j++;
	if (!(new_stock = malloc(sizeof(char) * j + 1)))
		return (NULL);
	j = 0;
	while (clean_stock[i])
		new_stock[j++] = clean_stock[i++];
	new_stock[j] = '\0';
	free(clean_stock);
	return (new_stock);
}

int	ft_pushtheline(char **stock, char **line)
{
	int i;

	if (ft_texteanalyse(*stock) == 1)
	{
		*line = ft_maketheline(*stock);
		*stock = ft_cleanstock(*stock);
		i = 0;
		return (1);
	}
	return (0);
}

char	*ft_substr_gnl(char **str, int start, int len)
{
	int		i;
	char	*res;

	i = 0;
	if (!(res = malloc(sizeof(char) * len + 1)))
		return (NULL);
	while (i < len && (*str)[start] != '\n')
	{
		res[i] = (*str)[start];
		i++;
		start++;
	}
	res[i] = '\0';
	free(*str);
	*str = NULL;
	return (res);
}

int		ft_get_next_line(int fd, char **line)
{
	char		buffer[BUFFER_SIZE + 1];
	static char	*stock = NULL;
	int			ret;

	if (!line || BUFFER_SIZE < 1 || fd < 0 || read(fd, buffer, 0) < 0)
		return (-1);
	if (stock == 0)
	{
		if (!(stock = malloc(sizeof(char) * BUFFER_SIZE + 1)))
			return (0);
		stock[0] = '\0';
	}
	if (ft_pushtheline(&stock, line) == 1)
		return (1);
	while ((ret = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[ret] = '\0';
		stock = ft_strjoin_gnl(stock, buffer);
		if (ft_pushtheline(&stock, line) == 1)
			return (1);
	}
	if (*line != NULL && **line == '\0')
	{
		free(*line);
		line = NULL;
	}
	*line = ft_substr_gnl(&stock, 0, ft_strlen(stock));
	return (0);
}

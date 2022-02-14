#include "gnl.h"

char	*ft_strjoinfree(char **str, char *str_to_join)
{
	char	*tmp = *str;

	if (tmp == NULL)
		*str = ft_strdup(str_to_join);
	else
		*str = ft_strjoin(tmp, str_to_join);
	free(tmp);
	return *str;
}

int read_into_rest(char **rest_line, char **line)
{
	char	*new_line;
	size_t	index_newline;
	
	if (*rest_line == NULL)
		return RET_READ_UNDEFINED;
	new_line = ft_strchr(*rest_line, '\n');
	if (new_line == NULL)
	{
		*line = ft_strdup(*rest_line);
		free(*rest_line);
		*rest_line = NULL;
		return RET_READ_UNDEFINED;
	}
	index_newline = new_line - *rest_line;
	*line = strndup(*rest_line, index_newline);
	new_line = ft_strdup(new_line + 1);
	free(*rest_line);
	*rest_line = new_line;
	return LINE_READ;
}

int assign_line_to_rest(char **line, char **rest_line)
{
    if (rest_line != NULL)
    {
        line = rest_line;
        rest_line = NULL;
    }
    return (0);
}

int read_til_newline(int fd, char **line, char **rest_line)
{
    char    str_read[BUFF + 1];
    int     ret_read;
	char	*new_line;
	size_t	index_newline;

    ret_read = read(fd, &str_read, BUFF);
	if (ret_read > 0)
	{
    	str_read[ret_read] = '\0';
		new_line = ft_strchr(str_read, '\n');
		if (new_line == NULL)                       // ft_strchr retourne NULL s'il ne trouve pas le char dans la *str envoyé
		{
			*line = ft_strjoinfree(line, str_read);
			return (read_til_newline(fd, line, rest_line));
		}
		index_newline = new_line - str_read;
		*rest_line = ft_strjoinfree(rest_line, new_line + 1);
		str_read[index_newline] = '\0';
		*line = ft_strjoinfree(line, str_read);
		return LINE_READ;
	}
	return ret_read;
}

int get_next_line(int fd, char **line)
{
    static char *rest_line = NULL;
	int			ret;

    if (fd < 0)
        return (FAILURE);
	*line = NULL;
    ret = read_into_rest(&rest_line, line);
    if (ret == RET_READ_UNDEFINED)
    	ret = read_til_newline(fd, line, &rest_line);
	return ret;
}
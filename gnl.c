#include "gnl.h"

int search_for_newline(char *str)
{
    size_t i;

    i = 0;
    while (str != NULL && str[i] != '\0')
    {
        if (str[i] == NEW_LINE)
            return (1);
        ++i;
    }
    return (0); 
}

char	*ft_strncpy2(char *dst, const char *src, size_t len)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0' && i < len)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char *ft_strconcat(char *str1, char *str2)
{
    char *new_str;
    size_t len_str1;
    size_t len_str2;

    len_str1 = 0;
    if (str1 != NULL)
        len_str1 = ft_strclen(str1, '\0');
    len_str2 = ft_strclen(str2, '\0');
    new_str = (char *)malloc(sizeof(char) * (len_str1 + len_str2 + 1));
    if (new_str == NULL)
        return (NULL);
    if (str1 != NULL)
        ft_strcpy(new_str, str1);
    ft_strcpy(new_str + len_str1, str2);
    return (new_str);
}

char *clean_rest_line(char *str)
{
    char *new_str;
    size_t  i;
    size_t  j;

    i = 0;
    while (str[i] != NEW_LINE)
        ++i;
    j = i; 
    while (str[j] != '\0')
        ++j;
    new_str = (char *)malloc(sizeof(char) * (j - i) + 1);
    if (new_str == NULL)
        return (NULL);
    j = 0;
    while (str[i] != '\0')
    {
        new_str[j] = str[i];
        ++j;
        ++i;
    }
    new_str[j] = '\0';
    free(str);
    return (new_str); 
}


int read_into_rest(char **rest_line, char **line)
{
    
    if (*rest_line != NULL && search_for_newline(*rest_line) == 1)
    {
        if (*line != NULL)
            free(*line);
        *line = malloc(sizeof(char) * ft_strclen(*rest_line, NEW_LINE) + 1);
        if (*line == NULL)
            return (-1);
        *line = ft_strncpy2(*line, *rest_line, ft_strclen(*rest_line, NEW_LINE));
        *rest_line = clean_rest_line(*rest_line);
        if (*rest_line == NULL)
            return (-1);
        return (1);
    }
    return (0);
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

    ret_read = read(fd, &str_read, BUFF);
    str_read[ret_read] = '\0';
    while (ret_read > 0)
    { 
        *rest_line = ft_strconcat(*rest_line, str_read);
        if (rest_line == NULL)
            return (-1);
        if (search_for_newline(*rest_line) == 1)
            return (read_into_rest(rest_line, line));
        ret_read = read(fd, &str_read, BUFF);
        str_read[ret_read] = '\0';
    }
    if (ret_read == 0)
        return (assign_line_to_rest(line, rest_line));
    return (ret_read); 
}

int get_next_line(int fd, char **line)
{
    static char *rest_line;

    rest_line = NULL;
    if (fd < 0)
        return (-1);
    if (read_into_rest(&rest_line, line) == 1)
        return (1);
    if (read_into_rest(&rest_line, line) == -1)
        return (-1);
    return (read_til_newline(fd, line, &rest_line));
}
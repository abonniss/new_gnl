#include "get_next_line_2.h"

int main(int ac, char **av)
{
    char *file_name;
    int fd;
    char *str;
    str = NULL;

    if (ac != 2)
        return (0);

    file_name = av[1];
    fd = open(file_name, O_RDONLY);
    while (get_next_line_2(fd, &str) > 0)
        ft_printf("Retour GNL : (%s)\n", str);
    return (0);
}

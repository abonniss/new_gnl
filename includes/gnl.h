
#ifndef GNL_H
# define GNL_H

# include <stdio.h>
# include <stddef.h>
# include <errno.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
#include "libftprintf.h"

# define BUFF 5
# define NEW_LINE '\n'
#define RET_READ_UNDEFINED 2
#define LINE_READ 1
#define END_OF_FILE 0
#define FAILURE -1

int get_next_line(int fd, char **str);


#endif

#include "get_next_line.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int     get_next_line(const int fd, char **line)
{
    size_t  size;

    while (size = read(fd, *line, BUFF_SIZE - 1) > 0)
    {
        *line[BUFF_SIZE] = '\0';
    }
    if (size == -1)
        return (-1);
    return (0);
}
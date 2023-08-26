#include "get_next_line.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int     main(void)
{
    char    *line;
    char    *file_path;
    int     fd;
    int     rslt;

    file_path = "test.txt";
    if (fd = open(file_path, O_RDONLY) == -1)
    {
        write(1, "error file\n", 11);
        return (1);
    }
    while (rslt = get_next_line(fd, &line))
        printf("%s\n", line);
    if (rslt == 0)
        write(1, "end file\n", 9);
    else 
    {
        write(1, "error line\n", 10);
        return (1);
    }
    return (0);
}
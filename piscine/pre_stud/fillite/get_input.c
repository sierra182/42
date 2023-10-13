#include "headerfile.h"

int    check_input(Data *data, char *c)
{
    int j;
    int k;
    int l;

    j = 0;  // letter counter (tetriminos level)
    k = 0;  // line counter
    l = 1;  // tetriminos counter
    while (*c)
    {
        if (*c != '.' && *c != '#' && *c != '\n')
            return (0);
        if (*c != '\n')
            j++;
        if ((*c == '\n' || *(c + 1) == '\0') && j != 4 && *(c - 1) != '\n')
            return (0);
        if (*c == '\n')
        {
            k++;
            j = 0;
        }
        if (*c == '\n' && *(c -1) == '\n' && k != 5)
        {
            return (1);
        }

        if ((*c  == '\n' && *(c - 1) == '\n'))
        {
            k = 0;
            l++;
        }
        c++;
    }
    if (l == 0 || l > 25)
        return (0);
    data->tetnum = l;
    return (1);
}

void    get_input(Data *data, char *argv)
{
    int fd;
    size_t size;
    int input_size;

    data->input = (char*)malloc(sizeof(char) * MAX);
    fd = open(argv, O_RDONLY);
    if (fd == -1)
        display_error();
    size = read(fd, data->input, MAX);
    data->input[size] = '\0';
    input_size = (int)size;
    data->input_size = input_size;
    if (!check_input(data, data->input))
        display_error();
}
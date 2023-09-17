#include <stdio.h>
#include <unistd.h>

char   *ft_strchr(const char *s, int c)
{
    while (*s)    
        if (*s++ == c)
            return ((char *) --s); 
    return (NULL);
}

int     main(void)
{
    char    *line = "bonjour le monde!";
    char    *res;

    res = ft_strchr(line, '5');
    if (res != NULL)
        printf("%s\n", res);
    else
        printf("null!\n");
    write(1, res, 1);
    write(1, "\n", 1);
    return (0);
}
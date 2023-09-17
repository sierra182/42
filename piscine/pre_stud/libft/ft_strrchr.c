#include <stdio.h>
#include <string.h>
#include <unistd.h>

char   *ft_strrchr(const char *s, int c)
{
    int i;

    i = 0;
    while (s[i])    
        i++;        
    while (i >= 0)    
        if (s[i--] == c)
            return ((char *) s + ++i); 
    return (NULL);
}

int     main(void)
{
    char    *line = "bonjour le monde!";
    char    *res;

    res = ft_strrchr(line, 'z');
    if (res != NULL)
        printf("%s\n", res);
    else
        printf("null!\n");
    write(1, res, 1);
    write(1, "\n", 1);
    return (0);
}
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char    *ft_substr(char const *s, unsigned int start, size_t len)
{
    char *sub_s;
    size_t  i;
    
    if (!s || start < 0 || len <= 0)
        return (NULL);
    sub_s = (char *) malloc(sizeof (char) *len + 1);
    if (!sub_s)
        return (NULL);
    i = 0;
    while(i < len && s[start + i])  
        sub_s[i++] = s[start + i];         
    sub_s[i] = '\0';
    return (sub_s);
}

int     main(void)
{
    char const  *line = "bonjour la famille!";
    char    *res = ft_substr(line, 5, 500);
    if (!res)
        printf("res is null\n");    
    else
        printf("%s\n", res);
    write(1, res, 1);
    free(res);
    return (0);
}
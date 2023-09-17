#include <stdlib.h>
#include <stdio.h>

static size_t ft_strlen(const char *s)
{
   size_t  i;

    if (!s)
        return (0);
    i = 0;
    while (s[i])
        i++;
    return (i);
} 

char    *ft_strjoin(char const *s1, char const *s2)
{
    char    *join_s;
    char *temp;
    
    if (!s1 || !s2)
        return NULL;   
    join_s = (char *) malloc(sizeof (char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
    temp = join_s;
    while (*s1)    
        *join_s++ = *s1++;  
    while (*s2)    
        *join_s++ = *s2++;   
    *join_s = '\0';
    return (temp);    
}

int main(void)
{
    char    *s1 = "je mange ";
    char    *s2 = "des patates.";
    char    *join_s;

    join_s = ft_strjoin(s1, s2);
    printf("%s\n", join_s);
    free(join_s);
    return (0);
}
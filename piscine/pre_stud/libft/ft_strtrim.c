#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

static size_t   ft_strlen(const char *s)
{
    size_t  i;

    if (!s)
        return (0);
    i = 0;
    while (s[i])
        i++;
    return (i);
} 

static int ft_parse_prefix(char const **s1, char const *set)
{
    int n_set;
    int j;

    n_set = 0;
    while (**s1)
    {
        j = -1;
        while (set[++j])        
            if (**s1 == set[j])
            {
                n_set++;
                break;
            } 
        if (*(set + j) == '\0')
            break;
        (*s1)++;
    }
    return (n_set); 
}

static int  ft_parse_suffixe(char const *s1, char const *set, int s1_len)
{
    int i;
    int j;
    int n_set;

    n_set = 0;
    i = s1_len;    
    while (--i >= 0)
    {
        j = -1;
        while (set[++j])        
            if (s1[i] == set[j])
            {
                n_set++;
                break;
            }   
        if (*(set + j) == '\0')
            break;      
    }    
    return (n_set);  
}

char *ft_strtrim(char const *s1, char const *set)
{
    char    *trim_s1;
    int s1_len;  
    int n_set;   
    int i; 
    
    if (!s1 || !set)
        return (NULL);
    s1_len = ft_strlen(s1);          
    n_set = ft_parse_suffixe(s1, set, s1_len);  cd ..
    n_set += ft_parse_prefix(&s1, set); 
    trim_s1 = (char *) malloc(sizeof (char) * (s1_len - n_set + 1));
    if (!trim_s1)
        return (NULL);    
    i = 0;  
    while (i < s1_len - n_set)    
        trim_s1[i++] = *s1++;      
    trim_s1[i] = '\0';
    return (trim_s1); 
}

int main(void)
{
    const char *s1 = "%;;!!salut!;!%! les cafés! !%;";
    const char *set = "%!; ";
    char *trim_s1;

    trim_s1 = NULL;
    trim_s1 = ft_strtrim(s1, set);
    printf("%s", trim_s1);
    free(trim_s1);
}
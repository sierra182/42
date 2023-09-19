#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"

int main(void)
{
    const char *s1 = "salut!;!%! les cafés";
    const char *set = "%!; ";
    char *trim_s1;

    trim_s1 = NULL;
    trim_s1 = ft_strtrim(s1, set);
    printf("%s", trim_s1);
    free(trim_s1);
}
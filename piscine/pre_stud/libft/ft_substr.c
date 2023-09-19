/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seblin <seblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 16:51:56 by seblin            #+#    #+#             */
/*   Updated: 2023/09/18 11:40:59 by seblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_s;
	size_t	i;

	sub_s = (char *) malloc(sizeof (char) * (len + 1));
	if (!sub_s)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		sub_s[i] = s[start + i];
		i++;
	}
	sub_s[i] = '\0';
	return (sub_s);
}
/*
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
*/